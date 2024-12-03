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
const int U = 2.1e6;
const int MOD = 1e9+7;
int head[U], nxt[U], to[U], val[U], tot;
void add(int x, int y, int z)
{
    to[++tot] = y; val[tot] = z; nxt[tot] = head[x]; head[x] = tot;
}
int fa[U];
int find(int e)
{
    if (e == fa[e]) return e;
    return fa[e] = find(fa[e]);
}
void merge(int u, int v)
{
    fa[find(v)] = find(u);
}
string str[U];
bool vis[U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int T = next();
    hrp(t, 1, T)
    {
        int r, c;
        cin>>r>>c;
        rep(i, 0, r) cin>>str[i];

        hrp(i, 0, 2*r) fa[i] = i, vis[i] = 0;

        bool no = 0;
        rep(j, 0, (c+1)/2)
        {
            vector<int> ori, rev;
            rep(i, 0, r)
            {
                if (str[i][j] == '1') ori.push_back(i);
                if (str[i][c-j-1] == '1') rev.push_back(i);
            }
            if (ori.size()+rev.size() > 2) no = 1;
            else if (ori.size() == 1 && rev.size() == 1)
            {
                if (find(ori[0]) == find(rev[0]+r) || find(ori[0]+r) == find(rev[0])) no = 1;
                merge(ori[0], rev[0]); merge(ori[0]+r, rev[0]+r);
            }
            else if (ori.size() == 2)
            {
                if (find(ori[0]) == find(ori[1]) || find(ori[0]+r) == find(ori[1]+r)) no = 1;
                merge(ori[0], ori[1]+r); merge(ori[0]+r, ori[1]);
            }
            else if (rev.size() == 2)
            {
                if (find(rev[0]) == find(rev[1]) || find(rev[0]+r) == find(rev[1]+r)) no = 1;
                merge(rev[0], rev[1]+r); merge(rev[0]+r, rev[1]);
            }
        }

        int ans = !no, mul = 1;
        rep(i, 0, 2*r) if (!vis[find(i)]) (ans *= mul+1) %= MOD, vis[find(i)] = 1, mul = !mul;
        cout<<ans<<endl;
    }
    
    return 0;
}
/*

 */