//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;


vector<pair<int, ll>> adj[100001]; // {neighbor, cost};
int parent[100001];
int heavy[100001];
int sz[100001];
int chainHead[100001];
int chainNumber[100001];
int chainPosition[100001];
ll cost[100001];
pii edges[100001];
int n;
class SegmentTreeMax
{
public:
	ll* st;
	ll* a;
	int length;
	SegmentTreeMax()
	{
		st = NULL;
		a = NULL;
		length = 0;
	}
	SegmentTreeMax(ll arr[], int n)
	{
		length = n;
		a = new ll[n];
		memcpy(a, arr, sizeof(ll)*n);
		int height = (int)(ceil(log2(n)));
		int maxSize = 4 * (1 << height) - 1;
		st = new ll[maxSize];
		build(0, 0, length - 1);
	}
	ll f(ll a, ll b)
	{
		return max(a, b);
	}

	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = a[l];
		else
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	void update(int i, int v)
	{
		update(0, 0, length - 1, i, v);
		a[i] = v;
	}
	void update(int node, int sl, int sr, int i, ll v)
	{
		if (i < sl || i > sr || sl > sr)
			return;
		if (sl == sr)
		{
			st[node] = v;
			return;
		}
		int mid = (sl + sr) / 2;
		update(node * 2 + 1, sl, mid, i, v);
		update(node * 2 + 2, mid + 1, sr, i, v);
		st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
	}

	ll query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	ll query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > qr || sr < ql || sl > sr)
			return 0;
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		ll a = query(node * 2 + 1, sl, mid, ql, qr);
		ll b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		return f(a, b);
	}
};
SegmentTreeMax* st[100001];
void dfsHLD(int node) // helper for HLD
{
	sz[node] = 1;
	FOR(i, 0, adj[node].size())
	{
		int j = adj[node][i].first;
		if (j == parent[node])
		{
			continue;
		}
		parent[j] = node;
		cost[j] = adj[node][i].second;
		dfsHLD(j);
		sz[node] += sz[j];
	}
	FOR(i, 0, adj[node].size())
	{
		int j = adj[node][i].first;
		if (j == parent[node])
		{
			continue;
		}
		if (sz[j] > sz[node] / 2)
		{
			heavy[node] = j;
			break;
		}
	}
}
void HLD()
{
	memset(heavy, -1, sizeof(heavy));
	parent[0] = -1;
	dfsHLD(0);
	int c = 0;
	FOR(i, 0, n)
	{
		if (parent[i] == -1 || heavy[parent[i]] != i)
		{
			int pos = 0;
			vector<ll> chain;
			for (int k = i; k != -1; k = heavy[k])
			{
				if (pos != 0)
				{
					chain.push_back(cost[k]);
				}
				chainNumber[k] = c;
				chainHead[k] = i;
				chainPosition[k] = pos;
				pos++;
			}
			if (chain.size() > 0)
			{
				st[c] = new SegmentTreeMax(&chain[0], chain.size());
			}
			c++;
		}
	}
}
// lca
class SegmentTreeLCA
{
public:
	pii* st;
	int* a;
	int length;
	SegmentTreeLCA()
	{

	}
	SegmentTreeLCA(int arr[], int n)
	{
		length = n;
		a = new int[n];
		memcpy(a, arr, sizeof(int)*n);
		int height = (int)(ceil(log2(n)));
		int maxSize = 4 * (1 << height) - 1;
		st = new pii[maxSize];
		build(0, 0, length - 1);
	}
	pii f(pii a, pii b)
	{
		return min(a, b);
	}
	void build(int node, int l, int r)
	{
		if (l == r)
		{
			st[node].first = a[l];
			st[node].second = l;
		}
		else
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}
	pii query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	pii query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > qr || sr < ql || sl > sr)
			return{ 1000000000, 01 };
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		pii a = query(node * 2 + 1, sl, mid, ql, qr);
		pii b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		return min(a, b);
	}
};
SegmentTreeLCA LCAst;
int LCApath[100001];
int LCAdepth[100001];
int LCAid[100001];
int x;
void tour(int current, int p, int d)
{
	LCAid[current] = x;
	LCApath[x] = current;
	LCAdepth[x++] = d;
	FOR(i, 0, adj[current].size())
	{
		int neighbor = adj[current][i].first;
		if (neighbor != p)
		{
			tour(neighbor, current, d + 1);
			LCApath[x] = current;
			LCAdepth[x++] = d;
			if (x < 0 || x >= 100000)
			{
				return;
			}
		}
	}
}
int getLCA(int u, int v) //prepLCA first!
{
	return LCApath[LCAst.query(min(LCAid[u], LCAid[v]), max(LCAid[u], LCAid[v])).second];
}
void prepLCA() // call this first
{
	x = 0;
	tour(0, -1, 0);
	LCAst = SegmentTreeLCA(LCAdepth, 2 * 100000);
}
// end lca
ll queryUp(int a, int lca)
{
	ll ans = 0;
	while (a != lca)
	{
		if (heavy[parent[a]] != a) // light edge
		{
			ans = max(ans, cost[a]);
			a = parent[a];
		}
		else // heavy path
		{
			if (chainNumber[lca] == chainNumber[a])
			{
				int pos1 = min(chainPosition[lca], chainPosition[a]);
				int pos2 = max(chainPosition[lca], chainPosition[a]);
				pos2--;
				pos2 = max(pos2, 0);
				ll x = st[chainNumber[lca]]->query(pos1, pos2);
				ans = max(ans, x);
				break;
			}
			else
			{
				if (chainPosition[a] > 0)
				{
					ll x = st[chainNumber[a]]->query(0, chainPosition[a] - 1);
					ans = max(ans, x);
				}
				a = chainHead[a];
			}
		}
	}
	return ans;
}
ll query(int a, int b)
{
	int lca = getLCA(a, b);
	return max(queryUp(a, lca), queryUp(b, lca));
}
void update(pii edge, ll v)
{
	int a = edge.first;
	int b = edge.second;
	if (chainNumber[a] == chainNumber[b])
	{
		if (parent[a] == b)
		{
			if (chainPosition[a] > 0)
			{
				st[chainNumber[a]]->update(chainPosition[a] - 1, v);
			}
		}
		else
		{
			if (chainPosition[b] > 0)
			{
				st[chainNumber[b]]->update(chainPosition[b] - 1, v);
			}
		}
	}
	else
	{
		if (parent[a] == b)
		{
			cost[a] = v;
		}
		else
		{
			cost[b] = v;
		}
	}
}
ll f(ll x) {
	int cnt = __builtin_popcountl(x);
	ll b = ((1ll << cnt) - 1);
	ll a = b << (50 - cnt);
	return a ^ b;
}
int bits(ll x) {
	int ans = __builtin_popcountl(x);
	if (ans > 25) ans = 50 - ans;
	return ans;
}
int main() // test
{
	int t;
	scanf("%d", &t);
	FOR(asd, 0, t)
	{
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			adj[i].clear();
		}
		FOR(i, 0, n - 1)
		{
			int a, b;
			ll c;
			scanf("%d%d%lld", &a, &b, &c);
			a--;
			b--;
			c = bits(c);
			adj[a].push_back(pii(b, c));
			adj[b].push_back(pii(a, c));
			edges[i] = pii(a, b);
		}
		prepLCA();
		HLD();
		int q;
		scanf("%d", &q);
		FOR(i, 0, q){
			int type, a, b;
			scanf("%d%d%d", &type, &a, &b);
			if (type == 1)
			{
				a--;
				update(edges[a], bits(f(b)));
			}
			else
			{
				a--;
				b--;
				ll cnt = query(a, b);
				ll b = ((1ll << cnt) - 1);
				ll a = b << (50 - cnt);
				printf("%lld\n", a ^ b);
			}
		}
	}
}
/*
1
15
8 1 4
12 2 2
6 3 4
14 4 8
2 5 9
11 6 8
5 7 8
2 8 5
10 9 3
3 10 7
3 12 8
11 13 4
3 14 1
12 15 1
6
2 1 7
2 9 11
1 3 6
1 10 2
2 15 9
2 2 4
15
8 1 4
12 2 2
6 3 4
14 4 8
2 5 9
11 6 8
5 7 8
2 8 5
10 9 3
3 10 7
3 12 8
11 13 4
3 14 1
12 15 1
6
2 1 7
2 9 11
1 3 6
1 10 2
2 15 9
2 2 4
*/