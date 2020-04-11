#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
/* 
LeetCode-349 ��Ŀ����������Ľ���
    �����������飬��дһ���������������ǵĽ�����
    ʾ�� 1:
        ����: nums1 = [1,2,2,1], nums2 = [2,2]
        ���: [2]
    ʾ�� 2:
        ����: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
        ���: [9,4]
    ˵��:
        �������е�ÿ��Ԫ��һ����Ψһ�ġ�
	    ���ǿ��Բ�������������˳��
*/

/*
����˼·��
    ���ϵ�˼��
*/
// �ü���
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vec;
    if(nums1.empty() || nums2.empty()){
        return vec;
    }   
    set<int> sn1(nums1.begin(), nums1.end());
    set<int> sn2(nums2.begin(), nums2.end());
    for(auto i : sn1){
        if(sn2.count(i)){
            vec.push_back(i);
            sn2.erase(i);
        }
    }
    return vec;
}
// ����set�Ľ�������
vector<int> intersection2(vector<int>& nums1, vector<int>& nums2) {
    vector<int> vec;
  
    set<int> sn1(nums1.begin(), nums1.end());
    set<int> sn2(nums2.begin(), nums2.end());
    set<int> s;
    set_intersection(sn1.begin(), sn1.end(), sn2.begin(), sn2.end(),inserter(s, s.begin()));
    for(auto i : s){
        vec.push_back(i);
    }
    return vec;
}
int main(){
    vector<int> vec1{4, 9, 5};
    vector<int> vec2{9,4,9,8,4};
    vector<int> vec = intersection2(vec1, vec2);
        // cout<<"location :"<< x<<endl;
    for(auto i : vec)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    system("pause");
    return 0;
}