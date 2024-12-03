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
const int U = 1e4;
struct Point
{
    int x, y;
} w[U];
istream& operator >> (istream& is, Point& e)
{
    is>>e.x>>e.y;
    return is;
}
struct Frac
{
    int a, b;
 
    Frac simp(void)
    {
        if (!a && !b);
        else if (!b) a = 1;
        else if (!a) b = 1;
        else { int g = gcd(a, b); a /= g; b /= g; }
 
        if (b < 0) a = -a, b = -b;
        return *this;
    }
    Frac(int a): a(a), b(1){}
    Frac(int a, int b): a(a), b(b){ this->simp(); }
    Frac operator / (const Frac& c) const
    {
        return Frac(a*c.b, b*c.a).simp();
    }
    Frac operator / (const int& c) const
    {
        return *this / (c);
    }
    Frac vert(void)
    {
        return Frac(-1) / *this;
    }
    bool operator == (const Frac& c) const
    {
        return a == c.a && b == c.b;
    }
    bool operator < (const Frac& c) const
    {
        if (*this == c) return 0;
        if (!b) return a < 0;
        if (!c.b) return c.a > 0;
        return a*c.b < b*c.a;
    }
};
ostream& operator << (std::ostream& os, const Frac& e)
{
    os<<e.a<<' '<<e.b;
    return os;
}
Frac slope(Point s, Point t)
{
    return Frac(t.y-s.y, t.x-s.x).simp();
}
map<Frac, int> mp[U];
signed main(void)
{
    #ifdef LOCAL
	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    clock_t c = clock();
 
    int n, q;
    cin>>n>>q;
    rep(i, 0, n) cin>>w[i];
 
    rep(i, 0, n) rep(j, i+1, n) mp[i][slope(w[i], w[j])]++;
 
    while(q--)
    {
        int ans = 0;
        Point p; cin>>p;
        map<Frac, int> qu;
 
        rep(i, 0, n) qu[slope(p, w[i])]++;
 
        rep(i, 0, n)
        {
            Frac s = slope(p, w[i]).vert();
            ans += qu[s]+mp[i][s];
            qu[slope(p, w[i])]--;
        }
        cout<<ans<<endl;
    }

    D(clock()-c);
 
    return 0;
}
/*
 
 */