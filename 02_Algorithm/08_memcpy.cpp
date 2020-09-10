#include <iostream>

using namespace std;
//
// Created by leexsh on 2020/9/9.
//

void* memcpy1(char* res, char* des, int n) {
    if (!res || !des || n <= 0) {
        return nullptr;
    }
    char* r = res;
    char* d = des;
//    判断重叠
    if(res + n > des) {
        r = res + n - 1;
        d = des + n - 1;
        while (n--) {
            *r-- = *d--;
        }
    } else {
        while (n--) {
            *r++ = *d++;
        }
    }

    return (void *)res;
}

void* memcpy(char* res, char* des, int n) {
    if (!res || !des || n <= 0) {
        return nullptr;
    }
//    按四个字节拷贝
    int c = n / 4;
    int y = n % 4;
    char* r = res;
    char* d = des;
//    重叠
    if (res + n >= des) {
        r = res + n - 1;
        d = des + n - 1;
        while (y--) {
            *r-- = *d--;
        }

        while (c--) {
            *(int*)r-- = *(int*)d--;
        }
    } else {
        while (c--) {
            *(int*)r++ = *(int*)d++;
        }
        while (d--) {
            *r++ = *d++;
        }
    }
    return (void*) res;
}
int main() {


    return 0;
}