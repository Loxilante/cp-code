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
const int U = 1e6+100;
const int MOD = 1000000007;
int fac[2*U];
int quickPow(int a, int b)
{
	int ret = 1%MOD, t = a;
	while(b)
	{
		if (b & 1) ret = ret*t%MOD;
		t = t*t%MOD;
		b >>= 1;
	}
	return ret;
}
int inv(int x)
{
	return quickPow(x, MOD-2);
}
int C(int n, int m)
{
    return fac[n]*inv(fac[m])%MOD*inv(fac[n-m])%MOD;
}
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);

    fac[1] = 1;
    rep(i, 2, 1e6+10) fac[i] = fac[i-1]*i%MOD;
    
    int T = next();
    while(T--)
    {
        int n, m;
        cin>>n>>m;
        if (n+m == 2) cout<<1<<endl;
        else if (n == 1 || m == 1) cout<<2<<endl;
        else cout<<4*C(n+m-2, n-1)%MOD<<endl;
    }
    
    return 0;
}
/*

 */