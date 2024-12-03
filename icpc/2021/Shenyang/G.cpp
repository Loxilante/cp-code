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
const int C = 20, U = 1200;
int pos[(1<<C)+U], dp[(1<<C)+U], lef[(1<<C)+U];
int sum[C+5][U], lst[C+5][U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, resmsk = 0;
    string str;
    cin>>n>>str;
    str = '$'+str;

    hrp(i, 1, n) rep(j, 0, C) sum[j][i] = sum[j][i-1]+(j == str[i]-'a'), lst[j][i] = j == str[i]-'a' ? i : lst[j][i-1];
    rep(i, 0, 20) if (sum[i][n]) resmsk |= 1<<i;
    int m = __builtin_popcount(resmsk);

    rep(msk, 0, 1<<C)
    {
        int minn = n+1;
        rep(i, 0, 20) if (!((msk>>i)&1) && lst[i][n]) minn = min(minn, lst[i][n]);
        pos[msk] = minn-1;
    }

    vector<int> ans;
    rep(i, 0, m)
    {
        int maxx = 0;
        rep(msk, 0, 1<<C)
        {
            if (__builtin_popcount(msk) != i || (i && dp[msk] != ans.back())) continue;
            rep(j, 0, 20) if (!(msk&(1<<j)) && resmsk&(1<<j))
            {
                int cntn = sum[j][pos[msk|(1<<j)]]-sum[j][lef[msk]];
                maxx = max(maxx, cntn);
                if (cntn > dp[msk|(1<<j)]) dp[msk|(1<<j)] = cntn, lef[msk|(1<<j)] = lst[j][pos[msk|(1<<j)]];
                else if (cntn == dp[msk|(1<<j)]) lef[msk|(1<<j)] = min(lef[msk|(1<<j)], lst[j][pos[msk|(1<<j)]]);
            }
        }
        ans.push_back(maxx);
    }

    string res;
    char ch = 'a'+m;
    for(auto v: ans) res += string(v, --ch);
    cout<<res<<endl;
    
    return 0;
}
/*
23
babcabbaccabbccbccabbac

23
qgjjgjqhghqjgjhgghjhggg
 */