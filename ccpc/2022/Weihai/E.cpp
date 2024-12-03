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
const int U = 2e5;
int w[U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k;
    cin>>n>>k;
    hrp(i, 1, n) cin>>w[i];

    rep(i, 1, U) if ((i <= n && w[i] < k) || (i > n && (w[i] = 2*w[i-1]-w[i-2]) < k)) return cout<<"Python 3."<<i<<" will be faster than C++"<<endl, 0;
    cout<<"Python will never be faster than C++"<<endl;
    
    return 0;
}
/*

 */