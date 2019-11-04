#include "bits/stdc++.h"
using namespace std;
/* 
LeetCode 70-棰樼洰鐖?ゼ姊?細
    鍋囪?浣犳?鍦ㄧ埇妤兼?銆傞渶瑕? n 闃朵綘鎵嶈兘鍒拌揪妤奸《銆?
    姣忔?浣犲彲浠ョ埇 1 鎴? 2 涓?彴闃躲€備綘鏈夊?灏戠?涓嶅悓鐨勬柟娉曞彲浠ョ埇鍒版ゼ椤跺憿锛?
    娉ㄦ剰锛氱粰瀹? n 鏄?竴涓??鏁存暟銆?
    绀轰緥 1锛?
        杈撳叆锛? 2
        杈撳嚭锛? 2
    绀轰緥 2锛?
        杈撳叆锛? 3
        杈撳嚭锛? 3
*/

/*
鎬濊矾锛?
    缁忓吀鐨勬枑娉㈤偅濂戦棶棰? 瑕佸埌n闃舵ゼ姊? 鍙?兘浠?(n-1)闃舵垨鑰?(n-2)闃舵ゼ姊?埌杈俱€?
    鍥犳?锛屽?鏋滃埌杈緉闃剁殑姝ユ暟鏄痜(n)鐨勮瘽锛宖(n) = f(n-1) + f(n-2)
 */
int climbStairs(int n) {
    int a = 1,b = 2,j;
    if(n <= 2)
        return n;

    for(int i = 3; i <= n; i++){
        j = a + b;
        a = b;
        b = j;
    }
    return j;
}
int main(){

    system("pause");
    return 0;
}