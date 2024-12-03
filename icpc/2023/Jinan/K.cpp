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
const int U = 1e6;
const int INF = 1e17;
int w[U], n, k, sum[U];
multiset<int> a, b;
int suma, sumb;
void init(void)
{
    suma = sumb = 0;
    a.clear(); b.clear();
    a.insert(-INF), b.insert(INF);
}
void adjust(void)
{
    while (a.size() > b.size()+1)
    {
        auto it = prev(a.end());
        sumb += *it;
        suma -= *it;
        b.insert(*it);
        a.erase(it);
    }
    while (b.size() > a.size())
    {
        auto it = b.begin();
        suma += *it;
        sumb -= *it;
        a.insert(*it);
        b.erase(it);
    }
}
void add(int e)
{
    if (e <= *b.begin()) a.insert(e), suma += e;
    else b.insert(e), sumb += e;
    adjust();
}
void del(int e)
{
    auto it = a.lower_bound(e);
    if (it != a.end()) suma -= *it, a.erase(it);
    else it = b.lower_bound(e), sumb -= *it, b.erase(it);
    adjust();
}
int get_middle()
{
    return *a.rbegin();
}
// bool check(int len)
// {
//     init();
//     hrp(i, 1, len) add(w[i]);
//     int p1 = get_middle(), ans = (int)(((a.size()-1)*p1-suma)+(sumb-(b.size()-1)*p1));
//     hrp(i, 1, n-len)
//     {
//         del(w[i]); add(w[i+len]);
        
//         ans = min(ans, (int)(((a.size()-1)*p-suma)+(sumb-(b.size()-1)*p)));
//     }
//     return ans <= k;
// }
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
        cin>>n>>k;
        hrp(i, 1, n) cin>>w[i], w[i] += n-i;

        init();
        int l = 1, r = 0, ans = 1;
        while(++r <= n)
        {
            add(w[r]);
            while (((a.size()-1)*get_middle()-suma)+(sumb-(b.size()-1)*get_middle()) > k) del(w[l++]);
            ans = max(ans, r-l+1);
        }

        cout<<ans<<endl;
    }
    
    return 0;
}
/*
1
6
199433206
 66537908
472716302
433389752
337965363
487175660
2737277283

4 199433206
472716302
433389752
337965363
487175660

 */