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
const int U = 2.5e5;
int w[U], l[U], r[U];
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
        rep(i, 0, n) cin>>w[i], l[i] = 0, r[i] = n-1;

        stack<int> st;
        st.push(0);
        rep(i, 1, n)
        {
            while (st.size() && w[i] > w[st.top()]) st.pop();
            if (st.size()) l[i] = w[i] == w[st.top()] ? i : st.top()+1;
            st.push(i);
        }

        while(st.size()) st.pop();
        st.push(n-1);
        rev(i, n-2, 0)
        {
            while (st.size() && w[i] > w[st.top()]) st.pop();
            if (st.size()) r[i] = st.top()-1;
            st.push(i);
        }

        int ans = 0;
        rep(i, 0, n) ans += r[i]-l[i];
        cout<<ans<<endl;
    }
    
    return 0;
}
/*
1
5
1 9 1 1 9
13
1 1 4 5 1 4 1 3 1 2 1 1 9

0 2
1 2
2 3
3 12
3 5
3 12
5 7
5 12
7 9
7 12
9 12
9 12



9 18

5 5
4 1
3 1
2 1

10
1 2 3 4 5 6 5 4 3 2
 */