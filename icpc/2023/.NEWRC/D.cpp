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
const int U = 30;
string str[10];
int d, h;
int dfs(int e, int vis)
{
    if (__builtin_popcount(vis) == d)
    {
        int bit = 0;
        vector<int> cnt(30, 0);
        while(vis)
        {
            if (vis&1) rep(i, 0, 24) if (str[bit][i] == '.') cnt[i]++;
            vis >>= 1; bit++;
        }
        
        sort(cnt.begin(), cnt.end(), greater<int>());
        int ans = 0;
        rep(i, 0, h) ans += cnt[i]; D(ans);
        return ans;
    }

    int ans = 0;
    rep(i, 0, 7) if (!(vis&(1<<i))) ans = max(ans, dfs(i, vis|(1<<i)));
    return ans;

}
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    rep(i, 0, 7) cin>>str[i];
    cin>>d>>h;

    cout<<fixed<<setprecision(10)<<1.0*dfs(-1, 0)/d/h<<endl;

    
    return 0;
}
/*

 */