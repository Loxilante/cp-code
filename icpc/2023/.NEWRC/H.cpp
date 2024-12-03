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
const int U = 2e6;
int w[U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = next();
    rep(i, 0, n) cin>>w[i];
    if (n == 1) return cout<<w[0]<<endl, 0;

    sort(w, w+n);
    int cnt = 0;
    rep(i, 0, n) if (w[i] == 1) cnt++; else break;

    bool first = 1;
    int r = cnt;
    if (cnt%2 == 1)
    {
        if (cnt == 1) printf("(1+%d)", w[r++]), first = 0, cnt--;
        else printf("(1+1+1)"), cnt -= 3;
        first = 0;
    }

    while(cnt)
    {
        if (!first) printf("*");
        printf("(1+1)"); first = 0;
        cnt -= 2;
    }
    
    while(r < n)
    {
        if (!first) printf("*");
        printf("%d", w[r++]); first = 0;
    }
    
    return 0;
}
/*
1 1 2 2 3

1 1 2 3

 */