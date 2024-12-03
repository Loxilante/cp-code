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
    
    int T = next();
    while(T--)
    {
        int n = next();
        set<string> st[30];
        rep(i, 0, n)
        {
            string team, problem, stat;
            cin>>team>>problem>>stat;
            team = team.substr(4);

            if (stat[0] == 'a') st[problem[0]-'A'].insert(team);
        }

        int maxx = 0, prob;
        rep(i, 0, 26) if (st[i].size() > maxx) maxx = st[i].size(), prob = i;

        cout<<(char)(prob+'A')<<endl;
    }
    
    return 0;
}
/*
2
5
teamasfd A accepted
teamB B rejected
teamasdf A accepted
teambbbb B accepted
teambbbb C accepted
4
teamA A rejected
teamB A accepted
teamC B accepted
teamC B accepted
 */