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
const int U = 1.5e3;
int w[U][U], l[U][U], r[U][U], u[U][U], t[U*U];
bool sl[U][U], su[U][U];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m;
    cin>>n>>m;
    rep(i, 0, n) rep(j, 0, m) t[next()] = i*m+j+1;
    rep(i, 0, n) rep(j, 0, m) w[i][j] = t[next()], l[i][j] = r[i][j] = j, u[i][j] = 1;

    int col = 0;
    rep(i, 0, n) rep(j, 0, m)
    {
        if (i && w[i][j] == w[i-1][j]+m) su[i][j] = 1;
        if (j && (w[i][j]-1)%m && w[i][j] == w[i][j-1]+1) sl[i][j] = 1;
    }

    rep(i, 0, n) rep(j, 1, m) if (su[i][j-1]) l[i][j] = l[i][j-1];
    rep(i, 0, n) rev(j, m-2, 0) if (sl[i][j+1]) r[i][j] = r[i][j+1];

    int ans = 0;
    rep(i, 0, n) rep(j, 0, m)
    {
        if (i && su[i][j])
        {
            l[i][j] = max(l[i][j], l[i-1][j]);
            r[i][j] = min(r[i][j], r[i-1][j]);
            u[i][j] = u[i-1][j]+1;
        }
        ans = max(ans, (r[i][j]-l[i][j]+1)*u[i][j]);
    }

    cout<<ans<<endl;

    return 0;
}
/*
12 12
144 73  133  126   22    86   83   13  120  62 101  39
26  7    141 125   3    40   99    140 114  28 68   27
42  17   85  35   71    50   46    45  5   14  47   2
49  9    88  32   18    97   29   95   8  109   1   76
111 48  60   132   20    115 138  43  135 112   4   92
55  143  127  52   117   36   84  107 110 15   105  104
74  37   102   129  108   23   98 38  19   122   6   59
33  90   118   89   116   11  56  134  100  81   66  12
31  82   130   75   128   63  77  103  94   65   16  34
106 30  53   80     54    51  93   58   79  91  121  123
61  139  96   64    119   10  137   24  67   78  44  25
72  131  113  57   70     69   124  41  87   136 21  142

144 28  1    51  127  80    74   79  141  24 21  34
116 136 62  123   3    40   70  109  8   111  4  105
76  11   85  35  71   50    46   45  37  139  49  94
125 124 108  32   18   97   29   95  10  142  81  130
5   66    60 132  20   115  138  83  61  30  91  47
99  100  121  52  117   36  84  140 122 103  75  64
82  89   104  129  16  78   13  128  65  53  6  107
48  110  58   12   38   33  90   43  17 77  63   96
118 39  88   134   143 126  55  137  31  9   44   135
102 67  42   114   72   73 54   133 106  26   112  56
25  68   119   22   93  86  57  7   120  92  113  23
27  59   41    101  131 14 15   98   87  2  69   19
 */
 