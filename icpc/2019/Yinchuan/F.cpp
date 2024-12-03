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
const double eps = 1e-9;
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
int inv(int e)
{
    return quickPow(e, MOD-2);
}
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = next(), ans = 0;
    for(int i = 2; i*i <= n; i++)
    {
        int p = (log(n)+eps)/log(i), t = ((p-1)*quickPow(i, p)%MOD-(quickPow(i, p)-i)*inv(i-1)%MOD)%MOD+(n-quickPow(i, p)+1)%MOD*p%MOD;
        ans += t%MOD*i%MOD;
    }
    int g = sqrt(n)+1;
    ans += (g+n)%MOD*((n-g+1)%MOD)%MOD*((n+1)%MOD)%MOD*inv(2)%MOD-n%MOD*((n+1)%MOD)%MOD*((2*n+1)%MOD)%MOD*inv(6)%MOD+(g-1)*g%MOD*(2*g-1)%MOD*inv(6)%MOD;
    cout<<(ans%MOD+MOD)%MOD<<endl;
    
    return 0;
}
/*

 */