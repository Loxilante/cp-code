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
const int U = 2e5;
struct team
{
    int id, st;
    string univ;
} w[U];
int c[U], ans[U];
map<string, int> mp;
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, minc = 1e10;
    cin>>n>>m;
    rep(i, 0, m) minc = min(minc, next());
    rep(i, 0, n) w[i] = {i, next(), next<string>()};

    sort(w, w+n, [=](team a, team b)
    {
        return a.st > b.st;
    });

    int cnt = 0;
    rep(i, 0, n)
    {
        ans[w[i].id] = cnt+(mp[w[i].univ] < minc);
        mp[w[i].univ]++;
        if (mp[w[i].univ] <= minc) cnt++;
    }
    
    rep(i, 0, n) cout<<ans[i]<<endl;
    
    return 0;
}
/*

 */