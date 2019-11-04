#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode 136-题目：只出现一次的数据
    给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
    说明：
        你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
        示例 1:
            输入: [2,2,1]
            输出: 1
        示例 2:
            输入: [4,1,2,1,2]   
            输出: 4
*/

/*
思路：

 */
//遍历 好像效率很低 耗时 oj不通过的方法
int singleNumber(vector<int>& nums) {
    if(nums.size() == 1){
        return nums[0];
    }
  
    int num;
    for(int i = 0; i < nums.size(); i++){
        bool falg = false;
        for(int j = 0; j < nums.size(); j++){
            if(nums[j] == nums[i] && i != j)
            {    falg = true;
                 break;
            }
        }
        if(falg == false){
            num = nums[i];
            break;
        }
    }
    return num;
}
//异或的方法 相同的数异或得0 不同的异或得1 0与任何数异或还是那个数
int singleNumber(vector<int>& nums) {
    int c = 0;
	for (int i = 0; i < nums.size(); i++)
	{
		c = c ^ nums[i];
	}
	return c;
}
//借助set 如果set中没有这个元素就加入到set中 如果有 就从set中取出， 最后set中就剩下一个元素。
int singleNumber(vector<int>& nums) {
    unordered_set<int> m;
    for(int i = 0; i < nums.size(); ++i){
        if(m.count(nums[i])) m.erase(nums[i]);
        else
        {
            m.insert(nums[i]);
        }
    }
    return *m.begin();
}
int main(){
    vector<int> vec{2,2,1};
    int x = singleNumber(vec);
    cout<<x<<endl;
    system("pause");
    return 0;
}