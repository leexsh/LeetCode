#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode-502 题目：IPO
    假设力扣（LeetCode）即将开始其IPO。为了以更高的价格将股票卖给风险投资公司，力扣希望在IPO之前开展一些项目以增加其资本。 
    由于资源有限，它只能在IPO之前完成最多 k 个不同的项目。帮助力扣设计完成最多 k 个不同项目后得到最大总资本的方式。
    
    给定若干个项目。对于每个项目 i，它都有一个纯利润 Pi，并且需要最小的资本 Ci 来启动相应的项目。
    最初，你有 W 资本。当你完成一个项目时，你将获得纯利润，且利润将被添加到你的总资本中。
    总而言之，从给定项目中选择最多 k 个不同项目的列表，以最大化最终资本，并输出最终可获得的最多资本。
    示例 1:
        输入: k=2, W=0, Profits=[1,2,3], Capital=[0,1,1].
    输出: 4
    解释:
        由于你的初始资本为 0，你尽可以从 0 号项目开始。
        在完成后，你将获得 1 的利润，你的总资本将变为 1。
        此时你可以选择开始 1 号或 2 号项目。
        由于你最多可以选择两个项目，所以你需要完成 2 号项目以获得最大的资本。
        因此，输出最后最大化的资本，为 0 + 1 + 3 = 4。
    注意:
	    假设所有输入数字都是非负整数。
	    表示利润和资本的数组的长度不超过 50000。
	    答案保证在 32 位有符号整数范围内。
*/

/*
思路：
    贪心 + 堆
 */
// 把花费和利润构造起节点
class Node{
public:
    Node(){}
    Node(int c, int p) : cost(c), profit(p){}
    int cost; 
    int profit;
};
// 优先队列的比较器 按照花费从小到大排序
struct minCompare{
    bool operator()(Node n1, Node n2){
        return n1.cost > n2.cost;
    }
};
// 优先队列的比较器 按照利润从大到小排序
struct maxCompare{
    bool operator()(Node n1, Node n2){
        return n1.profit < n2.profit;
    }
};
int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    // 全部构造节点
    vector<Node> vec;
    for(int i =  0; i < Profits.size(); i++){
        vec.push_back(Node(Capital[i], Profits[i]));
    }        
    // 按照花费 从小到大的优先队列
    priority_queue<Node, vector<Node>, minCompare> minCost;
    // 按照利润 从大到小的优先队列
    priority_queue<Node, vector<Node>, maxCompare> maxPro;
    // 全部加入到小根堆中
    for(int i = 0; i < vec.size(); i++){
        minCost.push(vec[i]);
    }
    for(int i = 0; i < k; i++){
        // 把当前能做的放入大根堆
        while(!minCost.empty() && minCost.top().cost <= W){
            maxPro.push(minCost.top());
            minCost.pop();
        }
        // 没得做了
        if(maxPro.empty()){
            return W;
        }
        // 求当前profit
        W += maxPro.top().profit;
        maxPro.pop();
    }
    return W;
}
int main(){
    vector<int> cost{0,1,1};
    vector<int> pro{1,2,3};
    int c = findMaximizedCapital(2,0,pro, cost);
    cout<<"c "<<c<<endl;
    system("pause");
    return 0;
}