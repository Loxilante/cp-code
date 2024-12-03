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
const int U = 2e4;
int w[U], at[U];
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
        rep(i, 0, n) cin>>w[i], at[w[i]] = i;

        vector<pair<int, int>> ope;
        rep(i, 0, n-1) if (w[i] > i+1)
        {
            int r = max(at[i+1], at[i+2]);
            ope.push_back({i+1, r+1});
            sort(w+i, w+r+1);
            rep(i, 0, n) at[w[i]] = i;
        }

        cout<<ope.size()<<endl;
        for(auto v: ope) cout<<v.first<<' '<<v.second<<endl;
    }
    
    return 0;
}
/*

 */