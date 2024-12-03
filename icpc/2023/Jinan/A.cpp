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
bool check(string s)
{
    rep(r, s.size()/2, s.size())
    {
        int l = s.size()-r-1;
        if (s[l] != s[r]) return 1;
        if (l != r-1 && s[r] == s[r-1]) return D(s), 0;
    }
    return 1;
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
        string str; cin>>str;

        rep(i, 0, str.size())
        {
            if (str[i] == ')') str[i] = '(';
            if (str[i] == ']') str[i] = '[';
        }

        int cnt = 0;
        rep(i, 0, str.size()-1) if (str[i] == str[i+1]) cnt++;

        if (cnt <= 2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    
    return 0;
}
/*
0110 0110 0110
112112
D


([([])]([]))
([([])]([]))


[([()])]
[][()]()[][()]()

]])) ])]])]
21121221
 */