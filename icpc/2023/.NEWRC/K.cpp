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
const int U = 520;
const int dx[] = {1, 1, -1, -1}, dy[] = {1, -1, 1, -1};
int n, ax[2], ay[2], p;
bool vis[U][U][2];
struct Stat
{
    int x, y, op;
};
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n>>ax[0]>>ay[0]>>ax[1]>>ay[1];

    queue<Stat> que; que.push({1, 1, 0}); que.push({1, 1, 1});
    while(que.size())
    {
        auto [x, y, op] = que.front(); que.pop();
        if (x < 1 || x > n || y < 1 || y > n || vis[x][y][op]) continue;
        vis[x][y][op] = 1;

        int r = !op;
        rep(d, 0, 4) que.push({x+dx[d]*ax[r], y+dy[d]*ay[r], r}),
                     que.push({x+dx[d]*ay[r], y+dy[d]*ax[r], r});
    }

    int cnt = 0;
    hrp(i, 1, n) hrp(j, 1, n) cnt += vis[i][j][0]|vis[i][j][1];
    cout<<cnt<<endl;
    
    return 0;
}
/*

 */