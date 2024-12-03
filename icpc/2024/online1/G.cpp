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
const int U = 2010;
int w[U], m[U][U], t[U][U], sum[U][U];
signed main(void)
{
    #ifdef LOCAL
	// freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT2.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = next();
    hrp(i, 1, n) cin>>w[i];
    
    hrp(i, 1, n)
    {
        priority_queue<int> p1;
        priority_queue<int, vector<int>, greater<int>> p2;
        p1.push(w[i]);

        hrp(j, i+1, n)
        {
            int median;
            if ((j-i)%2) median = p1.size() > p2.size() ? p1.top() : p2.top();
            else median = p1.top();
            m[i][j-1] = median;

            if (w[j] > median) p2.push(w[j]);
            else p1.push(w[j]);
            
            if (p2.size() == p1.size()+2) p1.push(p2.top()), p2.pop();
            if (p1.size() == p2.size()+2) p2.push(p1.top()), p1.pop();
        }
        if ((n-i+1)%2) m[i][n] = p1.size() > p2.size() ? p1.top() : p2.top();
        else m[i][n] = p1.top();
    }

    auto check = [=](int val)
    {
        hrp(i, 1, n) hrp(j, i, n) t[i][j] = m[i][j] > val;

        hrp(i, 1, n) hrp(j, 1, n) sum[i][j] = sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+t[i][j];

        int ova = 0;
        hrp(i, 1, n) hrp(j, i, n) ova += sum[j][j]-sum[i-1][j]-sum[j][i-1]+sum[i-1][i-1] >= (j-i+2)*(j-i+1)/2/2+1;

        return ova <= n*(n+1)/2/2+1;
    };

    sort(w+1, w+n+1);
    int l = 1, r = n;
    while(l <= r)
    {
        int mid = l+r>>1; D(l, r, mid);
        if (check(w[mid])) r = mid-1;
        else l = mid+1;
    }

    cout<<w[l]<<endl;

    return 0;
}
/*
10
11 9 13 12 9 3 2 3 11 1 
 */