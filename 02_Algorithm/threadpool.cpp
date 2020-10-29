#include <iostream>

using namespace std;
//
// Created by leexsh on 2020/10/29.
//
typedef enum {
    granceful_shutdown = 1,
    immediate_shutdown = 2,
}threadpoll_shutdown_t;

// 线程工作函数的结构体
typedef struct {
    void (*fun)(void *);
    void *arg;

}threadpool_task_t;

class threadpool{
public:
    pthread_mutex_t m_lock;         // 线程互斥锁
    pthread_cond_t m_nofity;        // 线程互斥条件变量
    pthread_t *pthreads;            // 线程id数组
    threadpool_task_t *queue;       // 线程工作队列
    int m_threadCount;              // 线程数目
    int m_tail;                     // 线程工作队列头部
    int m_head;                     // 线程工作队列尾部
    int m_queue_size;               // 任务队列大小

    int m_started;                  // 工作的线程数目
    int m_work_count;               // 任务数目
    int m_shutdown;                 // 关闭的方式 granceful或者immediate关闭
};
threadpool *threadpool_init(int thread_count, int queue_size, int flags);
// 线程的销毁
int threadpool_add(threadpool *tp, void (*fun)(void *), void* arg, int flags);
// 线程池的销毁
int threadpool_des(threadpool *tp, int flags);
int threadpool_free(threadpool *tp);
static void *threadpool_work(void* threadpl);










// 线程池的初始化
threadpool *threadpool_init(int thread_count, int queue_size, int flags)
{
    threadpool *tp;
    do{
        // 线程数目和队列进行合法性判断
        if(thread_count <= 0 || thread_count > MAX_THREAD || queue_size <= 0 || queue_size > MAX_QUEUE) {
            return NULL;
        }
        // 申请空间
        if((tp = (threadpool*)malloc(sizeof(threadpool))) == NULL){
            break;
        }

        // 初始化数据
        // 任务队列头尾 为0
        tp->m_head = tp->m_tail = tp->m_started = 0;
        // 线程数目为0
        tp->m_threadCount = 0;
        // 任务为0
        tp->m_work_count = 0;
        tp->m_shutdown = 0;
        // 任务队列大小
        tp->m_queue_size = queue_size;

        // 线程id分配数组
        tp->pthreads = (pthread_t*)malloc(sizeof(pthread_t) * thread_count);
        // 分配任务队列数组
        tp->queue = (threadpool_task_t *)malloc(sizeof(threadpool_task_t) * queue_size);

        // 合法性检测
        if((pthread_mutex_init(&tp->m_lock, NULL) != 0) || (pthread_cond_init(&tp->m_nofity, NULL) != 0)
           || tp->pthreads == NULL || tp->queue == NULL){
            break;
        }

        for(int i = 0; i < thread_count; ++i){
            // 创建线程
            if(pthread_create(&(tp->pthreads[i]), NULL, threadpool_work, (void*)tp) != 0){
                threadpool_des(tp,0);
                return NULL;
            }
            tp->m_threadCount++;
            tp->m_started++;
        }
        return tp;
    }while(false);

    if(tp != NULL){
        threadpool_free(tp);
        tp = NULL;
    }
    return tp;
}

// 线程池添加任务
int threadpool_add(threadpool *tp, void (*fun)(void *), void* arg, int flags)
{
    if(tp == NULL || fun == NULL){
        return THREADPOOL_UNABLE;
    }
    // 加锁
    if((pthread_mutex_lock(&tp->m_lock)) != 0){
        return THREADPOOL_MUETX_FAIL;
    }
    int next = (tp->m_tail + 1) % tp->m_queue_size;
    int err = 0;        // 错误标志
    do{
        // 任务队列满了
        if(tp->m_work_count == tp->m_queue_size){
            err = THREADPOOL_FULL;
            break;
        }
        // 线程池关闭
        if(tp->m_shutdown != 0){
            err = THREADPOOL_SHUTDOWN;
            break;
        }

        // 加入到线程池
        tp->queue[tp->m_tail].fun = fun;
        tp->queue[tp->m_tail].arg = arg;
        tp->m_work_count++;
        tp->m_tail = next;
        // 通知线程工作
        if((pthread_cond_signal(&tp->m_nofity)) != 0){
            err = THREADPOOL_COND_FAIL;
            break;
        }

    }while(false);
    // 最后解锁
    if((pthread_mutex_unlock(&tp->m_lock))!= 0){
        err = THREADPOOL_MUETX_FAIL;
    }
    return err;
}
int threadpool_des(threadpool *tp, int flags)
{
    std::cout<<"线程池销毁"<<std::endl;
    if(tp == NULL)
    {
        return THREADPOOL_UNABLE;
    }
    if(pthread_mutex_lock(&tp->m_lock) != 0){
        return THREADPOOL_MUETX_FAIL;
    }
    int err = 0;
    do
    {
        if(tp->m_shutdown != 0){
            // return THREADPOOL_SHUTDOWN;
            err = THREADPOOL_SHUTDOWN;
            break;
        }
        tp->m_shutdown = (flags & THREADPOOL_GRANCEFUL) ? granceful_shutdown : immediate_shutdown;

        if((pthread_cond_broadcast(&tp->m_nofity)) != 0 && (pthread_mutex_unlock(&tp->m_lock)) != 0){
            err = THREADPOOL_MUETX_FAIL;
            break;
        }
        for(int i = 0; i < tp->m_threadCount; i++){
            if(pthread_join(tp->pthreads[i], NULL) != 0){
                err = THREADPOOL_UNABLE;
            }
        }
    }while(false);
    if(err == 0){
        free(tp);
    }
    return err;
}
int threadpool_free(threadpool *tp)
{
    if(tp == NULL || tp->m_started > 0){
        return -1;
    }
    if(tp->pthreads){
        free(tp->queue);
        tp->queue = NULL;
        pthread_mutex_destroy(&(tp->m_lock));
        pthread_cond_destroy(&(tp->m_nofity));
        free(tp->pthreads);
        tp->pthreads = NULL;
    }
    free(tp);
    return 0;
}
static void *threadpool_work(void* threadpl)
{
    threadpool *tp = (threadpool*)threadpl;
    threadpool_task_t task;
    while(1){
        pthread_mutex_lock(&tp->m_lock);
        // 没有任务
        while(tp->m_work_count == 0 || tp->m_shutdown != 0){
            pthread_cond_wait(&tp->m_nofity, &tp->m_lock);
        }

        //
        if(((tp->m_shutdown == granceful_shutdown) || (tp->m_shutdown == immediate_shutdown)) || (tp->m_work_count == 0)){
            break;
        }
        task.fun = tp->queue[tp->m_head].fun;
        task.arg = tp->queue[tp->m_head].arg;
        tp->m_work_count--;
        tp->m_head = (tp->m_head + 1) % tp->m_queue_size;
        pthread_mutex_unlock(&tp->m_lock);
        //
        (*(task.fun))(task.arg);
    }
    tp->m_started--;
    pthread_mutex_unlock(&tp->m_lock);
    pthread_exit(0);
    return NULL;
}



int main() {


    return 0;
}