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
#define I(...) 0
#endif
const int U = 3e5;
int w[U];
vector<pair<int, int>> lim;
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
        lim.clear(); lim.push_back({-1, 0});

        int n, m, ori = 0;
        cin>>n>>m;
        rep(i, 0, n) cin>>w[i], ori += w[i];
        rep(i, 0, m) lim.push_back({next(), next()});

        sort(w, w+n, greater<int>());
        sort(lim.begin(), lim.end(), greater<pair<int, int>>());

        int pos1 = 0, pos2 = -1, sum = 0;
        while(++pos2 <= m)
        {
            if (!lim[pos2].second)
            {
                int cnt = 0, maxx = lim[pos2].first+1, pos3 = pos2-1;
                while(pos1 < n && w[pos1] > lim[pos2].first) pos1++, cnt++;
                while(cnt > 0 && pos3+1 && lim[pos3].first-1 == lim[pos3+1].first) maxx++, sum += lim[pos3].first*min(lim[pos3].second, cnt), cnt -= lim[pos3--].second;
                if (cnt > 0) sum += maxx*cnt;
            }
        }

        cout<<((ori-sum)%2 ? "Pico" : "FuuFuu")<<endl;
    }

    return 0;
}
/*
5
2 0
1 2
2 1
1 2
0 1
3 2
3 3 4
0 2
1 1
3 2
2 3 3
1 2
0 1
5 4
6 7 8 12 17
1 1
2 1
9 0
10 1

 */