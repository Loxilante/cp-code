#define F_C
#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = l; i < r; i++)
#define hrp(i, l, r) for(int i = l; i <= r; i++)
#define rev(i, r, l) for(int i = r; i >= l; i--)
#define ms(n, t) memset(n, t, sizeof(n))
#define pb push_back
#define int ll
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
template<typename tn = int> inline tn next(void) { tn k; cin>>k; return k; }
const int U = 1e6;
int to[U], head[U], nxt[U], val[U], tot;
void add(int x, int y, int z)
{
	val[++tot] = z; to[tot] = y; nxt[tot] = head[x]; head[x] = tot;
}
int bel[U], deg[U], cntb;
vector<int> block[U];
void dfs(int e)
{
	bel[e] = cntb;
	for(int i = head[e]; i; i = nxt[i])
	{
		int y = to[i];
		if (!bel[y]) dfs(y);
	}
}
int dis[U];
bool vis[U];
queue<int> que;
void dijkstra(int e)
{
	priority_queue<pii, vector<pii>, greater<pii> > pq;
	for(int i : block[e]) pq.push({dis[i], i});

	int sb = 0;
	while(pq.size())
	{
		int x = pq.top().second; pq.pop();
		if (vis[x]) continue;

		vis[x] = 1;

		for(int i = head[x]; i; i = nxt[i])
		{
			int y = to[i], z = val[i];
			if (dis[y] > dis[x]+z)
			{
				dis[y] = dis[x]+z;
				if (bel[y] == e) pq.push({dis[y], y});
			}

			if (bel[y] != e && !(--deg[bel[y]])) que.push(bel[y]);
		}
	}
}
void toposort(int s)
{
	ms(dis, 0x3f);
	dis[s] = 0;
	
	hrp(i, 1, cntb) if (!deg[i]) que.push(i);

	while(que.size())
	{
		int t = que.front(); que.pop();
		dijkstra(t);
	}
}
signed main(void)
{
	#ifdef JOEON
		freopen("C:\\Users\\32676\\Desktop\\IN.txt", "r", stdin);
		freopen("C:\\Users\\32676\\Desktop\\OUT.txt", "w", stdout);
	#endif
 
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m1, m2, s;
	cin>>n>>m1>>m2>>s;
	rep(i, 0, m1)
	{
		int a, b, c;
		cin>>a>>b>>c;
		add(a, b, c);
		add(b, a, c);
	}

	hrp(i, 1, n) if (!bel[i]) cntb++, dfs(i);
	hrp(i, 1, n) block[bel[i]].pb(i);

	rep(i, 0, m2)
	{
		int a, b, c;
		cin>>a>>b>>c;
		add(a, b, c);
	}

	hrp(i, 1, n)
	{
		for(int j = head[i]; j; j = nxt[j])
		{
			int y = to[j];
			if (bel[i] != bel[y]) deg[bel[y]]++;
		}
	}

	toposort(s);

	hrp(i, 1, n)
	{
		if (dis[i] >= 1e13) cout<<"NO PATH"<<endl;
		else cout<<dis[i]<<endl;
	}

	return 0;
}
/*
 
 */