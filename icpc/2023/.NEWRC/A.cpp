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
const int U = 5e5;
int w[U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, s;
    cin>>n>>s;
    rep(i, 0, n) cin>>w[i];

    if (n <= 2 || s <= 2) return cout<<min(n, s)<<endl, 0;

    sort(w, w+n);
    int len = s-2, ans = 2, alt = 0;
    int cnt[] = {0, 0, 0};
    rep(i, 0, n-2)
    {
        int t = (w[i]+2)/3;
        len -= t;

        if (w[i]%3 == 1)
        {
            if (cnt[2]) len++, cnt[2]--;
            else if (cnt[1]) len++, alt++, cnt[1]--;
            else cnt[1]++;
        }
        else if (w[i]%3 == 2)
        {
            if (cnt[1]) len++, cnt[1]--;
            else if (alt) cnt[1]++, alt--;
            else cnt[2]++;
        }

        if (len < 0) break;
        ans++;
    }

    cout<<ans<<endl;
    
    return 0;
}
/*
1 3
211
 */