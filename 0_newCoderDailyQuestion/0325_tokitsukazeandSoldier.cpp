#include "bits/stdc++.h"
using namespace std;
/*
网址：https://ac.nowcoder.com/discuss/390428
     https://blog.nowcoder.net/n/dd511adc01da43fa927a47a8e0df6e08
*/

/*
思路：

 */
#define ll long long
const int maxn = 1e5+5;
struct node{
    ll v;
    int s;
};
node a[maxn];
bool cmp(node &a, node &b)
{
    return a.s > b.s;
}
priority_queue<ll, vector<ll>, greater<ll>> q;

int main(){
    int n;
    cin>>n;
    for (int i = 1; i <=n ; ++i) {
        cin>>a[i].v>>a[i].s;
    }
    sort(a+1, a+1+n, cmp);
    ll ans = 0, cnt = 0;
    for (int i = 1; i <= n; ++i) {
        while (q.size() >= a[i].s)
        {
                cnt -= q.top();
                q.pop();
        }
        q.push(a[i].v);
        cnt += a[i].v;
        ans = max(ans, cnt);
    }
    cout<<ans<<endl;
//    system("pause");
    return 0;
}