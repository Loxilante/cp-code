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
        int n = next();
        double t = sqrt(2*n);
        int t1 = t, t2 = t1+1;

        int u1 = t1*t1-t1+2*n, d1 = 2*t1, g1 = __gcd(u1, d1);
        int u2 = t2*t2-t2+2*n, d2 = 2*t2, g2 = __gcd(u2, d2);

        if (u1*d2 < u2*d1) cout<<u1/g1<<' '<<d1/g1<<endl;
        else cout<<u2/g2<<' '<<d2/g2<<endl;
    }
    
    return 0;
}
/*

 */