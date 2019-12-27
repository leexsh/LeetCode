#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-295 题目：数据流中的中位数
    中位数是有序列表中间的数。如果列表长度是偶数，中位数则是中间两个数的平均值。
    例如，
        [2,3,4] 的中位数是 3
        [2,3] 的中位数是 (2 + 3) / 2 = 2.5
    设计一个支持以下两种操作的数据结构：
        void addNum(int num) - 从数据流中添加一个整数到数据结构中。
	    double findMedian() - 返回目前所有元素的中位数。
    示例：
        addNum(1)   
        addNum(2)   
        findMedian() -> 1.5
        addNum(3) 
        findMedian() -> 2
    进阶:
        如果数据流中所有整数都在 0 到 100 范围内，你将如何优化你的算法？
	    如果数据流中 99% 的整数都在 0 到 100 范围内，你将如何优化你的算法？
*/

/*
思路：
    堆的思想
    大根堆：保存的所有元素都比堆顶小 用来保存比中位数小的元素
    小根堆：保存的所有元素都比堆顶大 用来保存比中位数大的元素
    如果奇数个元素 肯定有个堆比另一个多一个元素 多的那个数就是中位数
    如果偶数个元素  两个堆顶元素的平均数
 */
class MedianFinder {
public:
    priority_queue<int, vector<int>, greater<int> >  minHeap;//小根堆
    priority_queue<int, vector<int>, less<int> > maxHeap;//大根堆
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    // 调整的过程 只要一个堆比另一个多两个元素 就要进行调整
    void modifyHeapSize(){
        if(minHeap.size() == maxHeap.size() + 2){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if(maxHeap.size() == minHeap.size() + 2){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }
    
    // 添加一个数的过程
    void addNum(int num) {
        // 大根堆为空 知己诶入大根堆
        if(maxHeap.empty()){
            maxHeap.push(num);
            return;
        }
        // 如果比大根堆堆顶的元素小 或等于 直接进大根堆
        if(maxHeap.top() >= num){
            maxHeap.push(num);
        }
        else
        {
            // 小根堆空 进小根堆
            if(minHeap.empty()){
                minHeap.push(num);
                return;
            }
            // 比小根堆的堆顶小 进大根堆
            if(minHeap.top() > num){
                maxHeap.push(num);
            }
            // 进小根堆
            else
            {
                minHeap.push(num);
            }
            
        }
        // 进完之后 调整一次
        modifyHeapSize();
    }
    
    double findMedian() {
        // 两个堆的大小
        int minSize = minHeap.size();
        int maxSize = maxHeap.size();
        // 两个堆为空
        if(minHeap.empty() && maxHeap.empty()){
            return 0;
        }
        // 一个为空 一个不空 则为不空的元素
        if(minHeap.empty() && !maxHeap.empty()){
            return maxHeap.top();
        }
        if(!minHeap.empty() && maxHeap.empty()){
            return minHeap.top();
        }
        
        // 堆顶元素
        double minHead = minHeap.top();
        double maxHead = maxHeap.top();
        // 堆是偶数个元素  两个堆顶元素之和
        if(((minSize + maxSize) & 1) == 0){
            return (minHead + maxHead) *0.5;
        }
        // 堆是奇数个元素 选多一个数的那个堆顶
        return minSize > maxSize ? minHead : maxHead;
    }
};
int main(){
    MedianFinder m;
    m.addNum(1);
    double x = m.findMedian();
    cout<<x<<endl;

    system("pause");
    return 0;
}