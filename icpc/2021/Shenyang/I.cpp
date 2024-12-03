#define F_C
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define hrp(i, l, r) for(int i = l; i <= r; i++)
#define rev(i, r, l) for(int i = r; i >= l; i--)
#define int ll
using namespace std;
typedef long long ll;
typedef long double LD;
template<typename tn = int> tn next(void) { tn k; cin>>k; return k; }
#ifndef LOCAL
#define D(...) 0
#endif
const int U = 10;
struct Complex
{
	LD x, y;
    
	Complex(LD _x = 0.0, LD _y = 0.0) { x = _x; y = _y; }
	
    Complex operator + (const LD& e) const { return Complex(x, y+e); }
    Complex operator + (const Complex& e) const { return Complex(x+e.x, y+e.y); }
    Complex operator - (const LD& e) const { return Complex(x, y-e); }
    Complex operator - (const Complex& e) const { return Complex(x-e.x, y-e.y); }
    Complex operator * (const LD& e) const { return Complex(x*e, y*e); }
	Complex operator * (const Complex& e) const { return Complex(y*e.x+x*e.y, y*e.y-x*e.x); }
    Complex operator / (const LD& e) const { return Complex(x/e, y/e); }
	Complex operator / (const Complex& e) const
    {
        LD deno = -e.x*e.x-e.y*e.y;
		return Complex(y*e.x-x*e.y, -y*e.y-x*e.x)/deno;
	}
	bool operator == (const Complex& b) const { return x == b.x && y == b.y; }
} w[U], z[U];
istream& operator >> (istream& is, Complex& e)
{
    is>>e.y>>e.x;
    return is;
}
ostream& operator << (std::ostream& os, const Complex& e)
{
    os<<e.y<<' '<<e.x;
    return os;
}
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout<<fixed<<setprecision(15);

    int T = next();
    while(T--)
    {
        hrp(i, 1, 3) cin>>z[i]>>w[i];
        cin>>z[0];

        bool cont = 0;
        hrp(i, 1, 3) if (z[0] == z[i]) cout<<w[i]<<endl, cont = 1;
        if (cont) continue;

        Complex A = (z[0]-z[1])/(z[0]-z[2])*(z[3]-z[2])/(z[3]-z[1])*(w[3]-w[1])/(w[3]-w[2]);
        cout<<(A*w[2]-w[1])/(A-1)<<endl;
    }
    
    return 0;
}
/*
2
-1 0 0 -1
0 1 -1 0
1 0 0 1
0 -1
-1 0 -1 0
0 1 0 -1
1 0 1 0
0 -1
 */