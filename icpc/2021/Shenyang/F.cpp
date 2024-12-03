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
const int U = 1005;
int cnt[U][300];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int len;
    string str;
    cin>>len>>str;

    rev(i, len-1, 0) rep(j, i+1, len) cnt[i][str[j]]++;

    set<string> st;
    rev(i, len-1, 0)
    {
        string s;
        vector<int> v(300, -1);
        rev(j, i, 0) if (v[str[j]] == -1)
        {
            v[str[j]] = 0;
            hrp(ch, 'a', 'z') v[str[j]] += ch != str[j] && cnt[j][ch];
        }
        hrp(j, 0, i) s += 'a'+v[str[j]];

        st.insert(s);
        rep(j, 0, i) cnt[j][str[i]]--;
    }

    cout<<*prev(st.end())<<endl;

    
    return 0;
}
/*


 */