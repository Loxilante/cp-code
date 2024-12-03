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
int func(int e)
{
    int maxx = 0;
    while(e) maxx = max(maxx, e%10), e /= 10;
    return maxx;
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
        int l1, r1, l2, r2;
        cin>>l1>>r1>>l2>>r2;
        
        int l0 = l1+l2, r0 = r1+r2;
        if ((r0-l0+1) >= 10) { cout<<9<<endl; continue; }

        int maxx = 0;
        hrp(i, l0, r0) maxx = max(maxx, func(i));
        cout<<maxx<<endl;
    }
    
    return 0;
}
/*

 */