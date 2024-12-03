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
        if (!n || ((n-1)&3) == 3) { cout<<"NO"<<endl; continue; }

        vector<int> bin(40, -1);
        bin[31] = 1;
        int p = 1, i = 0; n--;
        while(n)
        {
            if (n&1) if (i) bin[i-1] += 2; else bin[i]++;
            n >>= 1; i++;
        }

        cout<<"YES"<<endl;
        rep(i, 0, 32) cout<<bin[i]<<" \n"[i%8 == 7];
    }
    
    return 0;
}
/*

 */