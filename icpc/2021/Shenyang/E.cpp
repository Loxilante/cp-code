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
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string str; cin>>str;

    int cnt = 0;
    if (str.size() >= 5) rep(i, 0, str.size()-4)
    {
        if (str[i] == 'e' && str[i+1] == 'd' && str[i+2] == 'g' && str[i+3] == 'n' && str[i+4] == 'b') cnt++;
    }

    cout<<cnt<<endl;
    
    return 0;
}
/*

 */