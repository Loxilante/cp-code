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
int w[5], t[5];
int sign(int ind)
{
    if (t[ind] < 0) return 1;
    if (t[ind] > 0) return 3;
    return 2;
}
int sign(int L, int R)
{
    bool l = 0, e = 0, g = 0;
    rep(i, L, R) l |= t[i] < 0, e |= t[i] == 0, g |= t[i] > 0;
    if (l && !(e+g)) return 1;
    if (e && !(l+g)) return 2;
    if (g && !(l+e)) return 3;
    return 4;
}
int solve(int l, int r)
{
    int sig;
    if (l >= r || (sig = sign(l, r)) == 2) return 0;

    if (sig == 1)
    {
        rep(i, l, r) t[i] = -t[i];
        return solve(l, r);
    }

    int ans = 0;
    if (sig == 3)
    {
        int minn = *min_element(t+l, t+r);
        rep(i, l, r) t[i] -= minn;
        ans += minn;
    }
    
    int s = l;
    rep(i, l+1, r) if (sign(i) != sign(i-1)) ans += solve(s, i), s = i;
    return ans+solve(s, r);
}
signed main(void)
{
    #ifdef LOCAL
	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    clock_t a = clock();

    int T = next();
    while(T--)
    {
        string s1, s2;
        cin>>s1>>s2;

        rep(i, 0, 4) w[i] = s2[i]-s1[i];
        
        int ans = 100;
        hrp(d0, -1, 1) hrp(d1, -1, 1) hrp(d2, -1, 1) hrp(d3, -1, 1)
        {
            rep(i, 0, 4) t[i] = w[i];
            if (d0) t[0] += d0*10;
            if (d1) t[1] += d1*10;
            if (d2) t[2] += d2*10;
            if (d3) t[3] += d3*10;
            ans = min(ans, solve(0, 4));
        }
        cout<<ans<<endl;
    }

    D((double)(clock()-a)/CLOCKS_PER_SEC);
    
    return 0;
}
/*
1
1234 9999
1234 0123
1234 9012
 */