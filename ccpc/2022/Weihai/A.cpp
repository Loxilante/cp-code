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
const int U = 1005;
map<string, int> cpos;
int cnt[10];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n = next();
    rep(i, 0, n) hrp(j, 1, 5) cpos[next<string>()] = j;

    int m = next(), cntc = 0;
    rep(i, 0, m)
    {
        string str;
        int pos;
        cin>>str>>pos;

        cnt[pos]++;
        if (cpos[str] == pos) cntc++;
    }

    int minn = cnt[1];
    hrp(i, 2, 5) minn = min(minn, cnt[i]);
    cout<<min(cntc, minn)<<endl;
    
    return 0;
}
/*

 */