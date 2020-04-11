#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-160 题目：相交链表
    编写一个程序，找到两个单链表相交的起始节点。
    示例 1：
        输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
        输出：Reference of the node with value = 8
        输入解释：相交节点的值为 8 （注意，如果两个列表相交则不能为 0）。从各自的表头开始算起，
        链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
    示例 2：
        输入：intersectVal = 2, listA = [0,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
        输出：Reference of the node with value = 2
        输入解释：相交节点的值为 2 （注意，如果两个列表相交则不能为 0）。
        从各自的表头开始算起，链表 A 为 [0,9,1,2,4]，链表 B 为 [3,2,4]。在 A 中，相交节点前有 3 个节点；在 B 中，相交节点前有 1 个节点。
    示例 3：
        输入：intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2    
        输出：null
        输入解释：从各自的表头开始算起，链表 A 为 [2,6,4]，链表 B 为 [1,5]。由于这两个链表不相交，所以 intersectVal 必须为 0，而 skipA 和 skipB 可以是任意值。
        解释：这两个链表不相交，因此返回 null。
    注意：
	    1.如果两个链表没有交点，返回 null.
	    2.在返回结果后，两个链表仍须保持原有的结构。
	    3.可假定整个链表结构中没有循环。
	    4.程序尽量满足 O(n) 时间复杂度，且仅用 O(1) 内存。
*/

/*
思路：
    见法1 法2 法3
 */
struct ListNode{
    int var;
    ListNode *next;
    ListNode(){}
    ListNode(int x) : var(x), next(NULL){}
};

// 利用set集合 将一个链表的节点放入到集合中 再利用另一个链表查找有没有相同的节点
ListNode *getIntersectionNode1(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
    set<ListNode*> s;//集合
    ListNode *p = NULL; //返回的指针
    ListNode *pTemp = headA; //遍历的指针
    // 将headA链表放入集合中
    while(pTemp)
    {
        s.insert(pTemp);
        pTemp = pTemp->next;
    }
    // 遍历headB链表
    pTemp = headB;
    while(pTemp){
        if(s.count(pTemp))
        {
            p = pTemp;
            break;
        }
        else
        {
            pTemp = pTemp->next;
        } 
    }
    return p;
}

// 法2 计算两个链表的差值  长的链表先走差值 之后再一起走 走到两个链表相等的节点 就是两个链表相交的起始交点
ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL){
        return NULL;
    }
    ListNode *pA = headA;
    ListNode *pB = headB;
    int numA = 0, numB = 0;
    // 计算两个链表中的所有节点的个数
    while(pA){
        ++numA;
        pA = pA->next;
    }
    while(pB){
        ++numB;
        pB = pB->next;
    }
    // 计算差值
    int dis = numA > numB ? numA - numB : numB - numA;
    // 如果A长的话 A先走差值
    if(numA > numB){
        pA = headA;
        pB = headB;
        while(dis >0){
            pA = pA->next;
            dis--;
        }
    }
    // 如果B长的话 B先走差值
    else{
        pA = headA;
        pB = headB;
        while(dis >0){
            pB = pB->next;
            dis--;
        }
    }
    // 两个链表一起走
    while(pA && pB){
        if(pA == pB)
            return pA;
        pA = pA->next;
        pB = pB->next;
    }
    // 没有交点 返回NULL
    return NULL;
}

// 法3 这个真的是个特别好的方法 见：https://www.cnblogs.com/grandyang/p/4128461.html
// https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/tu-jie-xiang-jiao-lian-biao-by-user7208t/
ListNode *getIntersectionNode3(ListNode *headA, ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
    ListNode *pA = headA, *pB = headB;
    while(pA != pB){
        pA = pA ? pA->next : headB;
        pB = pB ? pB->next : headA;
    }
    return pA;
}
int main(){

    system("pause");
    return 0;
}