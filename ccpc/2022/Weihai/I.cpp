#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define hrp(i, l, r) for(int i = l; i <= r; i++)
#define rev(i, r, l) for(int i = r; i >= l; i--)
#define int ll
using namespace std;
typedef long long ll;
template<typename tn = int> tn next(void) { tn k; cin>>k; return k; }
#ifndef LOCAL
#define D(...) 0
#define I(...) 0
#endif
const int U = 1.2e5;
int a[U], b[U], n, k;
bool check(int mul)
{
    priority_queue<int> pq;
    rep(i, 0, n) pq.push(a[i]*mul);
    vector<int> bt;
    rep(i, 0, k) bt.push_back(b[i]);

    rev(i, k-1, 0) while(bt[i] && pq.top() > 0)
    {
        int t = pq.top(), g = min(bt[i], max(1LL, t/(1<<i))); pq.pop();
        t -= g*(1<<i);
        bt[i] -= g;
        pq.push(t);
    }

    return pq.top() <= 0;
}
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = next();
    while(T--)
    {
        cin>>n>>k;

        int suma = 0, sumb = 0;
        rep(i, 0, n) cin>>a[i], suma += a[i];
        rep(i, 0, k) cin>>b[i], sumb += b[i]*(1<<i);

        int l = 0, r = sumb/suma;
        while(l < r)
        {
            int mid = l+r+1>>1;
            if (check(mid)) l = mid;
            else r = mid-1;
        }
        cout<<l<<endl;
    }
    
    return 0;
}
/*

 */