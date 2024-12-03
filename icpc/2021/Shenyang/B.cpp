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
const int U = 1e5+50;
struct DisjointSet
{
    int fa[U];
    DisjointSet(void) { rep(i, 0, U) fa[i] = i; }
    int find(const int& k)
    {
        if (fa[k] == k) return k;
        return fa[k] = find(fa[k]);
    }
    void uni(const int& a, const int& b)
    {
        fa[find(a)] = find(b);
    }
} ds[32];
vector<int> dif[32][U];
set<int> st1[U], st2[U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif

    int n, m;
    cin>>n>>m;
    rep(i, 0, m)
    {
        int u, v, bit;
        cin>>u>>v>>bit;

        int nb = 0;
        while(bit)
        {
            if (bit&1) dif[nb][v].push_back(u), dif[nb][u].push_back(v);
            else ds[nb].uni(u, v);
            bit >>= 1;
            nb++;
        }
    }

    rep(b, 0, 30) rep(i, 0, n) for(auto d: dif[b][i]) if (ds[b].find(i) == ds[b].find(d)) return cout<<-1<<endl, 0;

    int ans = 0, p2 = 1;
    rep(b, 0, 30)
    {
        rep(i, 0, n) st1[i].clear(), st2[i].clear();
        rep(i, 0, n)
        {
            st1[ds[b].find(i)].insert(i);
            for(auto d: dif[b][i]) st2[ds[b].find(i)].insert(d);
        }
        rep(i, 0, n) ans += p2*min(st1[i].size(), st2[i].size()), I(min(st1[i].size(), st2[i].size()), b, i, st1[i], st2[i]);
    }

    cout<<ans<<endl;
    
    return 0;
}
/*
10
10
 */