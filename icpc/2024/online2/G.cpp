#define F_C
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
#endif
const int MOD = 998244353;
int quickPow(int a, int b)
{
    int p = a, ans = 1;
    while(b)
    {
        if (b&1) ans *= p, ans %= MOD;
        p *= p; p %= MOD;
        b >>= 1;
    }
    return ans;
}
int inv(int a)
{
    return quickPow(a, MOD-2);
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
        int x, y, a, b, p, ans = 0, now = 1;
        cin>>x>>y>>a>>b>>p;
        int p1 = a*inv(a+b)%MOD, p2 = b*inv(a+b)%MOD;

        while(x != y)
        {
            int t, pre = now;
            if (x > y)
            {
                t = (x-1)/y;
                x -= t*y;
                now *= quickPow(p2, t);
                now %= MOD;
                ans += pre-now;
            }
            else
            {
                t = (y-1)/x;
                y -= t*x;
                now *= quickPow(p1, t);
                now %= MOD;
            }
        }
        ans += now*p1;

        cout<<(ans%MOD+MOD)%MOD<<endl;
    }
    
    return 0;
}
/*

 */