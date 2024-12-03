#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define hrp(i, l, r) for(int i = l; i <= r; i++)
#define rev(i, r, l) for(int i = r; i >= l; i--)
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename tn = int> tn next(void) { tn k; cin>>k; return k; }
#ifndef LOCAL
#define D(...) 0
#define I(...) 0
#endif
const int N = 5, U = 19, D = 6, MXMSK = (1<<U)-1;
const int R[] = {3, 4, 5, 4, 3}, SR[] = {0, 3, 7, 12, 16, 19};
int convert(pii e)
{
    return SR[e.first]+e.second;
}
pii convert(int e)
{
    if (e >= 16) return {4, e-16};
    if (e >= 12) return {3, e-12};
    if (e >= 7) return {2, e-7};
    if (e >= 3) return {1, e-3};
    return {0, e};
}
bool legal(pii e)
{
    return 0 <= e.first && e.first < 5 && 0 <= e.second && e.second < R[e.first];
}
pii nxt(pii e, int dir)
{
    switch(dir)
    {
        case 0: return {e.first-1, e.second-(e.first < 3)};
        case 1: return {e.first-1, e.second+(e.first > 2)};
        case 2: return {e.first, e.second-1};
        case 3: return {e.first, e.second+1};
        case 4: return {e.first+1, e.second-(e.first > 1)};
        case 5: return {e.first+1, e.second+(e.first < 2)};
    }
}
bool chkmax(int &a, int b)
{
    if (b > a) return a = b, 1;
    return 0;
}
int w[N+1][N+1], dp[(1<<U)+U];
vector<int> msks;
signed main(void)
{
    #ifdef LOCAL
	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    rep(i, 0, N) rep(j, 0, R[i]) cin>>w[i][j];

    rep(msk, 0, MXMSK) msks.push_back(msk);
    sort(msks.begin(), msks.end(), [](int a, int b){ return __builtin_popcount(a) < __builtin_popcount(b); });

    for(auto msk: msks)
    {
        int mskt = msk;
        while(mskt)
        {
            int d0 = __builtin_ctz(mskt);
            rep(d, 0, D)
            {
                pii p0 = convert(d0), p1 = nxt(p0, d), p2 = nxt(p1, d);
                int d1 = convert(p1), d2 = convert(p2);
                if (!legal(p1) || !legal(p2) || (msk>>d1)&1 || (msk>>d2)&1) continue;

                chkmax(dp[(msk^(1<<d0))|(1<<d1)|(1<<d2)], dp[msk]+w[p1.first][p1.second]);
            }
            mskt ^= 1<<d0;
        }
        
        mskt = msk;
        while(mskt != MXMSK)
        {
            int d0 = __builtin_ctz(mskt^MXMSK);
            chkmax(dp[msk|(1<<d0)], dp[msk]);
            mskt ^= 1<<d0;
        }
    }

    int T = next();
    while(T--)
    {
        string str;
        rep(i, 0, N) str += next<string>();

        int msk = 0;
        rep(i, 0, U) if (str[i] == '#') msk |= 1<<i;

        cout<<dp[msk]<<endl;
    }

    return 0;
}
/*
9 2 2
3 3 7 2
0 3 6 8 5
4 7 7 5
8 0 7
3
...
..#.
..##.
....
...
...
....
.##..
..#.
...
###
####
#####
####
###
 */