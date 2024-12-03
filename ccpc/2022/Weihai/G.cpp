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
const int U = 1e6+10;
vector<int> sum{0};
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int x, n;
    cin>>x>>n;

    int t = 1<<((int)log2(x)+1);
    hrp(i, 1, t) sum.push_back((__gcd((i*x)^x, x) == 1)+(sum.empty() ? 0: sum.back()));

    rep(i, 0, n)
    {
        int nl, nr;
        cin>>nl>>nr;
        nl--;
        
        cout<<sum[nr%t]-sum[nl%t]+(nr/t-nl/t)*sum.back()<<endl;
    }
    
    return 0;
}
/*
504735 1
814534885376 814535102820
 */
