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
const int U = 1.5e5;
const vector<int> P{2, 3, 5, 7};
struct SegTree
{
    struct Seg
    {
        int l, r, maxx, tag;
    } seg[4*U];
    void build(int e, int l, int r)
    {
        seg[e].l = l; seg[e].r = r;
        if (l == r) { seg[e].maxx = seg[e].tag = 0; return; }
        int mid = l+r>>1;
        build(e*2, l, mid);
        build(e*2+1, mid+1, r);
    }
    void spread(int e)
    {
        if (seg[e].tag)
        {
            seg[e*2].tag += seg[e].tag;
            seg[e*2+1].tag += seg[e].tag;
            seg[e*2].maxx += seg[e].tag;
            seg[e*2+1].maxx += seg[e].tag;
            seg[e].tag = 0;
        }
    }
    void change(int e, int l, int r, int v)
    {
        if (l <= seg[e].l && seg[e].r <= r) { seg[e].maxx += v; seg[e].tag += v; return; }
        spread(e);
        int mid = seg[e].l+seg[e].r>>1;
        if (l <= mid) change(e*2, l, r, v);
        if (r > mid) change(e*2+1, l, r, v);
        seg[e].maxx = max(seg[e*2].maxx, seg[e*2+1].maxx);
    }
    int query(int e, int l, int r)
    {
        if (l <= seg[e].l && seg[e].r <= r) return seg[e].maxx;
        spread(e);
        int mid = seg[e].l+seg[e].r>>1, ans = 0;
        if (l <= mid) ans = max(ans, query(e*2, l, r));
        if (r > mid) ans = max(ans, query(e*2+1, l, r));
        return ans;
    }
} seg[10];
signed main(void)
{
    #ifdef LOCAL
//	freopen("C:\\Users\\Loxil\\Desktop\\IN.txt", "r", stdin);
//	freopen("C:\\Users\\Loxil\\Desktop\\OUT.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, q;
    cin>>n>>q;
    for(auto p: P) seg[p].build(1, 1, n);
    
    while(q--)
    {
        string ope; int l, r;
        cin>>ope>>l>>r;
        if (ope == "MULTIPLY")
        {
            int v = next();
            for(auto p: P)
            {
                int cnt = 0;
                while(v%p == 0) cnt++, v /= p;
                seg[p].change(1, l, r, cnt);
            }
        }
        else
        {
            int maxx = 0;
            for(auto p: P) maxx = max(maxx, seg[p].query(1, l, r));
            cout<<"ANSWER "<<maxx<<endl;
        }
    }
    
    return 0;
}
/*
5 6
MULTIPLY 3 5 2
MULTIPLY 2 5 3
MAX 1 5
MULTIPLY 1 4 2
MULTIPLY 2 5 5
MAX 3 5
 */