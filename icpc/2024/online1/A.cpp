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
        vector<int> v;
        rep(i, 0, 32) v.push_back(next());
        int china = v[0];

        sort(v.begin(), v.end(), greater<int>());
        int pos;
        rep(i, 0, 32) if (v[i] == china) pos = i+1;

        if (pos == 1) cout<<1<<endl;
        else if (pos <= 5) cout<<2<<endl;
        else if (pos <= 19) cout<<4<<endl;
        else if (pos <= 26) cout<<8<<endl;
        else if (pos <= 30) cout<<16<<endl;
        else cout<<32<<endl;
    }
    
    return 0;
}
/*
1
8 32 31 30 29 28 27 26 25 24 23 22 21 20
19 18 17 16 15 14 13 12 11 10 9 7 6
5 4 3 2 1
 */