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
        rep(i, 0, n) cin>>w[i];
        
        vector<pair<int, int>> ope;
        while(1)
        {
            rep(i, 0, n) at[w[i]] = i;

            int maxx = 1, l = 0, r = 0;
            hrp(i, 1, n) rep(j, 1, i) if ((at[j]-at[i]+1) > maxx) maxx = at[j]-at[i]+1, l = at[i], r = at[j];

            if (maxx == 1) break;

            ope.push_back({l+1, r+1});
            sort(w+l, w+r+1);
        }
        
        cout<<ope.size()<<endl;
        for(auto v: ope) cout<<v.first<<' '<<v.second<<endl;
    }
    
    return 0;
}
/*
5 4 1 2 3

1 5 2 4 3
3 1 5 4 2
1 3 2 5 4

1 3 2 5 4
2 1 4 3 5

1 2 3 4 5
1 3 2 5 4 

1 2 3 4 5 6 7 8 9
2 1 5 3 6 4 7 9 8


1 4 

2 1 4 6 3 5 7 9 8
2 1 3 4 6 5 7 9 8
 */