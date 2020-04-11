#include<iostream>
#include<vector>
using namespace std;
/*
LeetCode167-两数之和Ⅱ：
    给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。
    函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。

    说明:
	    返回的下标值（index1 和 index2）不是从零开始的。
	    你可以假设每个输入只对应唯一的答案，而且你不可以重复使用相同的元素。
    示例:
        输入: numbers = [2, 7, 11, 15], target = 9
        输出: [1,2]
    解释: 2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。
 */

/*
思路：
    定义两个下标 一个指向第一个元素 另一个指向最后一个元素
    如果两个下标所指向的元素之和为target， 直接加入到容器中， 返回；
    如果两个数的和大于target， 将后面的下标 向前移动 使得两数之和变小；
    如果两个数的和小于target， 将前面的下标 向后移动，使得两数之和变大；
    直到两数之和为target为止。
 */
vector<int> twoSum(vector<int> &numbers, int target){
    vector<int> vec;
    int i = 0, j = numbers.size() - 1;
    while(i != j){
        if(numbers[i] + numbers[j] == target){
            vec.push_back(++i);
            vec.push_back(++j);
            return vec;
        }
        else if(numbers[i] + numbers[j] < target){
            i++;
        }
        else
        {
            j--;
        }
        
    }
    return vec;
}
int main(){
    vector<int> numbers{2,7,11,15};
    vector<int> vec = twoSum(numbers, 9);
    for(int i : vec){
        cout<<i<<endl;
    }
    system("pause");
    return 0;
}