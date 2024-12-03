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

    char maxx = -1;
    vector<pair<int, int>> v;
    bool sync = 0;
    rep(i, 0, str.size())
    {
        if (str[i] > maxx) maxx = str[i], v.clear(), v.push_back({i, 1}), sync = 0;
        else if (str[i] == maxx)
        {
            sync = 0;
            if (str[i-1] == maxx)
            {
                if (++v.back().second > v.begin()->second)
                {
                    auto sv = v.back();
                    v.clear();
                    v.push_back(sv);
                }
            }
            else v.push_back({i, 1});
        }
        else
        {
            if (str[i-1] == maxx && v.back().second == v.begin()->second) sync = 1;
            if (sync)
            {
                if (str[i] > str[i-v.back().first+v.begin()->first])
                {
                    auto sv = v.back();
                    v.clear();
                    v.push_back(sv);
                    sync = 0;
                }
                else if (str[i] < str[i-v.back().first+v.begin()->first]) sync = 0;
            }
        }
        cout<<v.begin()->first+1<<' '<<i+1<<endl;
    }
    
    return 0;
}
/*
\
 */