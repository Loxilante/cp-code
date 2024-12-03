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
const int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    int n, k;
    cin>>n>>k;
    hrp(i, 1, n) for(int j = (i-1)%5+1; j <= n; j += 5)
    {
        cout<<i<<' '<<j<<endl;
        string str = next<string>();

        if (str == "hit")
        {
            auto check = [n](int x, int y)
            {
                if (x <= 0 || x > n || y <= 0 || y > n) return 0;

                cout<<x<<' '<<y<<endl;
                string re = next<string>();
                if (re == "sunk") return 1;
                return 0;
            };

            bool sunk = 0;
            for(int d = 0; d < 4 && !sunk; d++) for(int p = 1; p <= 4 && !sunk; p++) if (check(i+p*dx[d], j+p*dy[d])) k--, sunk = 1;
        }

        if (!k) return 0;
    }
    
    return 0;
}
/*

 */