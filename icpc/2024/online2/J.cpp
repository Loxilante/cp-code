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
const int U = 2e6;
struct obj
{
    int w, v, c;
};
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<obj> v;

    int n = next();
    rep(i, 0, n) v.push_back({next(), next(), next()});

    sort(v.begin(), v.end(), [=](obj a, obj b)
    {
        return b.c*a.w > a.c*b.w;
    });

    int sumv = 0, mns = 0, sumw = 0;
    for(auto t: v)
    {
        mns += sumw*t.c;
        sumw += t.w;
        sumv += t.v;
    }
    cout<<sumv-mns<<endl;
    
    return 0;
}
/*

 */