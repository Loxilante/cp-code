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
const double eps = 1e-9;
double k[5];
bool at[5];
struct Point
{
    double x, y;
} p[5];
bool eq(double a, double b)
{
    return a == b || fabs(a-b) <= eps;
}
double dis(Point a, Point b)
{
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
double slope(Point a, Point b)
{
    return (b.y-a.y)/(b.x-a.x);
}
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
        rep(i, 0, 4) cin>>p[i].x>>p[i].y, at[i] = 0;

        int at = -1, point = -1;
        rep(s, 0, 3)
        {
            int t = (s+1)%3;
            k[s] = slope(p[s], p[t]);
            if (eq(p[s].x, p[3].x) && eq(p[s].y, p[3].y)) point = s;
            else if ((eq(k[s], slope(p[3], p[s])) || eq(k[s], slope(p[s], p[3]))) 
                    && min(p[s].x, p[t].x) <= p[3].x && p[3].x <= max(p[s].x, p[t].x)
                    && min(p[s].y, p[t].y) <= p[3].y && p[3].y <= max(p[s].y, p[t].y)) at = s;
        }
        if (point != -1) { cout<<(p[(point+1)%3].x+p[(point+2)%3].x)/2<<' '<<(p[(point+1)%3].y+p[(point+2)%3].y)/2<<endl; continue; }
        if (at == -1) { cout<<-1<<endl; continue; }

        double r1 = dis(p[at], p[3])/dis(p[(at+1)%3], p[3]), r2 = r1<1 ? (r1+1)/2 : (r1-1)/r1/2;
        int u = (at+1+(r1>=1))%3, v = (u+1)%3;
        double ans1 = p[u].x+r2*(p[v].x-p[u].x), ans2 = p[u].y+r2*(p[v].y-p[u].y);
        cout<<fixed<<setprecision(12)<<ans1<<' '<<ans2<<endl;
    }
    
    return 0;
}
/*

 */