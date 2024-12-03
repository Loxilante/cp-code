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
typedef pair<int, int> pii;
const int U = 3e5;
const int INF = 1e9;
vector<int> edge[U];
int bot[U], dist[U][2], dist2[U][2], from[U][2];
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
        int n, m, d, k;
        cin>>n>>m>>d;
        hrp(i, 0, n) edge[i].clear(), dist[i][0] = dist[i][1] = dist2[i][0] = dist2[i][1] = INF;
        rep(i, 0, m) { int a, b; cin>>a>>b; edge[a].push_back(b); edge[b].push_back(a); }
        cin>>k;
        queue<pii> que;
        rep(i, 0, k) cin>>bot[i], que.push({bot[i], 0}), dist[bot[i]][0] = 0;

        while(que.size())
        {
            auto [at, dis] = que.front(); que.pop();
            if (dis == d) continue;

            for(auto to: edge[at]) if (dist[to][(dis+1)%2] > dis+1)
                dist[to][(dis+1)%2] = dis+1, que.push({to, dis+1});
        }

        que.push({1, 0}); dist2[1][0] = 0;
        while(que.size())
        {
            auto [at, dis] = que.front(); que.pop();

            for(auto to: edge[at]) if (dis+1 < dist[to][(dis+1)%2] && dist2[to][(dis+1)%2] > dis+1)
                dist2[to][(dis+1)%2] = dis+1, from[to][(dis+1)%2] = at, que.push({to, dis+1});
        }

        if (dist2[n][0] == INF && dist2[n][1] == INF) cout<<-1;
        else
        {
            bool c = dist2[n][0] > dist2[n][1];
            cout<<dist2[n][c]<<endl;

            int at = n;
            vector<int> path;
            while(at) path.push_back(at), at = from[at][c], c = !c;

            reverse(path.begin(), path.end());
            for(auto v: path) cout<<v<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
/*
1
10 10 5
1 9
4 6
1 2
7 9
1 8
2 3
4 10
3 7
1 4
1 5
1 6
 */