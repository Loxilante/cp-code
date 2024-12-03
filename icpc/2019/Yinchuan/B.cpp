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
const int dx[] = {-1, -1, 1, 1}, dy[] = {1, -1, 1, -1};
const int U = 2e3;
int w[U][U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = next(), px, py;
    rep(i, 0, n) rep(j, 0, n)
    {
        cin>>w[i][j];
        if (w[i][j] == -1) px = i, py = j;
    }

    rep(d, 0, 4)
    {
        int x = px+dx[d], y = py+dy[d];
        if (x < 0 || x >= n || y < 0 || y >= n) continue;

        cout<<w[x][py]-w[x][y]+w[px][y]<<endl;
        break;
    }
    
    return 0;
}
/*

 */