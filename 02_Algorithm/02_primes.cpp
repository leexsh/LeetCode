#include <iostream>
#include <vector>
using namespace std;
//
// Created by leexsh on 2020/4/15.
//

// 判断素数个数
//
// 从2到n的素数个数
bool isPrimes(int n)
{
    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0){
            return false;
        }
    }
    return true;
}
int primes(int n)
{
    vector<int> vec(n, false);
    for(int i = 2;i * i < n; i++)
    {
        if(isPrimes(i))
        {
            for (int j = i * i; j < n; j += i) {
                vec[j] = false;
            }
        }
    }
    int count = 0;
    for(int i = 2; i <= n; i++){
        if(vec[i] == true)
        {
            count++;
        }
    }
    return count;
}
int main() {


    return 0;
}