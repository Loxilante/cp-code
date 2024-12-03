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
const int U = 1500;
const int MOD = 1000000007;
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
int dp[U][U][5], w[U][U];
map<int, vector<pair<int, int>>> pos;
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    set<int> uni;
    cin>>n>>m;
    hrp(i, 1, n) hrp(j, 1, m) cin>>w[i][j], uni.insert(w[i][j]), pos[w[i][j]].push_back({i, j});
    hrp(i, 1, n) hrp(j, 1, m)
    {
        bool ext = 0;
        rep(d, 0, 4)
        {
            int x = i+dx[d], y = j+dy[d];
            if (1 <= x && x <= n && 1 <= y && y <= m && w[x][y] == w[i][j]-1) ext = 1;
        }
        dp[i][j][0] = !ext;
    }

    for(auto v: uni) for(auto p: pos[v]) rep(d, 0, 4) 
    {
        int i = p.first, j = p.second, x = i+dx[d], y = j+dy[d];

        if (w[x][y] == v+1) hrp(k, 1, 4)
            dp[x][y][min(3LL, k)] += dp[i][j][k-1], dp[x][y][min(3LL, k)] %= MOD;
    }

    int ans = 0;
    hrp(i, 1, n) hrp(j, 1, m)
    {
        bool ext = 0;
        rep(d, 0, 4)
        {
            int x = i+dx[d], y = j+dy[d];
            if (1 <= x && x <= n && 1 <= y && y <= m && w[x][y] == w[i][j]+1) ext = 1;
        }
        if (!ext) ans += dp[i][j][3], ans %= MOD;
    }
    cout<<ans<<endl;
        
    return 0;
}
/*
5 5
1 2 3 4 5
2 3 4 5 1
3 4 5 1 2
4 5 1 2 3
5 1 2 3 4
 */