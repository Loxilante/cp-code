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
const int U = 300;
string mp[U];
int calc(string str, int pos = 0)
{
    return str[pos]+str[pos+1]+str[pos+2];
}
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    mp['Y'] = "QQQ";
    mp['V'] = "QQW";
    mp['G'] = "QQE";
    mp['C'] = "WWW";
    mp['X'] = "QWW";
    mp['Z'] = "WWE";
    mp['T'] = "EEE";
    mp['F'] = "QEE";
    mp['D'] = "WEE";
    mp['B'] = "QWE";

    string str;
    cin>>str;

    int ans = str.size();
    string pre = str[0];
    for(char ch: str)
    {
        string ope = pre+mp[ch];
        rep(i, 0, 3) if (calc(ch) == calc(ope[i])) { ans += i; break; }
        pre = mp[ch];
    }
    cout<<cnt<<endl;

    
    return 0;
}
/*

 */