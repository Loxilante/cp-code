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
const int U = 1e6+1000;
int fa[U];
int find(int e)
{
    if (fa[e] == e) return e;
    return fa[e] = find(fa[e]);
}
void merge(int a, int b)
{
    fa[find(b)] = find(a);
}
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
        int n = next();
        hrp(i, 0, n) fa[i] = i;

        int ans = 1, l, r;
        hrp(i, 1, n)
        {
            cin>>l>>r;
            if (find(l-1) == find(r)) ans = 0;
            else merge(l-1, r);
        }
        cout<<ans<<endl;
    }
    
    return 0;
}
/*

 */