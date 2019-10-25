//Andrew Yang
#include <cctype>
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
#include <unordered_set>
#include <map>
#include <unordered_map>
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
#define INF 1000001
typedef long long ll;
typedef pair<int, int> pii;

struct Edge
{
	int l, u, v;
	bool operator< (const Edge& o) const
	{
		return l < o.l;
	}
};
vector<int> p, r;
void init(int n) {
	r.assign(n, 0);
	p.assign(n, 0);
	FOR(i, 0, n) {
		p[i] = i;
	}
}
int findSet(int i) {
	return (p[i] == i) ? i : (p[i] = findSet(p[i]));
}
bool isSameSet(int a, int b) {
	return findSet(a) == findSet(b);
}
void unionSet(int a, int b) {
	if (!isSameSet(a, b)) {
		int y = findSet(a), x = findSet(b);
		if (r[y] > r[x]) p[x] = y;
		else {
			p[y] = x;
			if (r[y] == r[x]) r[x]++;
		}
	}
}

class LazySegmentTree
{
public:
	int* st;
	vector<int> arr;
	int* lazy;
	int length;
	LazySegmentTree(vector<int> a, int n)
	{
		length = n;
		arr = a;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		lazy = new int[maxSize];
		build(0, 0, length - 1);
	}
	void build(int node, int a, int b)
	{
		lazy[node] = 0;
		if (a > b)
		{
			return;
		}
		if (a == b)
		{
			st[node] = arr[a];
			return;
		}
		build(node * 2 + 1, a, (a + b) / 2);
		build(node * 2 + 2, 1 + (a + b) / 2, b);
		st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
	}
	void update(int node, int a, int b, int i, int j, int v)
	{
		if (lazy[node] != 0)
		{
			st[node] += lazy[node];
			if (a != b)
			{
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (a > b || a > j || b < i)
		{
			return;
		}
		if (a >= i && b <= j)
		{
			st[node] += v * (b - a + 1);
			if (a != b)
			{
				lazy[node * 2 + 1] += v;
				lazy[node * 2 + 2] += v;
			}
			return;
		}
		update(node * 2 + 1, a, (a + b) / 2, i, j, v);
		update(node * 2 + 2, 1 + (a + b) / 2, b, i, j, v);
		st[node] = min(st[node * 2 + 1], st[node * 2 + 2]);
	}
	int query(int node, int a, int b, int i, int j)
	{
		if (a > b || a > j || b < i)
		{
			return 2 * INF;
		}
		if (lazy[node] != 0)
		{
			st[node] += lazy[node];
			if (a != b)
			{
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (a >= i && b <= j)
		{
			return st[node];
		}
		int q1 = query(node * 2 + 1, a, (a + b) / 2, i, j);
		int q2 = query(node * 2 + 2, 1 + (a + b) / 2, b, i, j);
		int res = min(q1, q2);
		return res;
	}
};
int type[200001];
Edge eList[200001];
int pl[200001];
vector<pii> edges[200001];
vector<int> values;
vector<pii> children[200001]; // type, number
unordered_map<int, int> rangeSize[200001];
unordered_map<int, pii> range[200001];
unordered_map<int, int> reached[200001];
int index[200001];
pii updates[200001];
void dfs(int u)
{
	for (pii j : edges[u])
	{
		if (j.second == p[u])
		{
			continue;
		}
		p[j.second] = u;
		pl[j.second] = j.first;
		children[u].push_back({type[j.second], j.second });
		rangeSize[u][type[j.second]]++;
		dfs(j.second);
	}
	sort(children[u].begin(), children[u].end());
	int sz = 0;
	FOR(j, 0, children[u].size())
	{
		pii x = children[u][j];
		values.push_back(pl[x.second]);
		index[x.second] = values.size() - 1;
		sz++;
		if (j == children[u].size() - 1 || children[u][j + 1].first != x.first)
		{
			reached[u][x.first] = values.size();
			while (sz < rangeSize[u][x.first])
			{
				values.push_back(INF);
			}
			
			sz = 0;
		}
		range[u][x.first] = { values.size() - rangeSize[u][x.first], values.size() - 1 };
	}
}
int main(void)
{
	//freopen("grass.in", "r", stdin);
	//freopen("grass.out", "w", stdout);
	int N, M, K, Q;
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	FOR(i, 0, M)
	{
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		u--, v--;
		eList[i].u = u;
		eList[i].v = v;
		eList[i].l = l;
	}
	sort(eList, eList + M);
	init(N);
	int count = 0;
	FOR(i, 0, M)
	{
		int u = eList[i].u;
		int v = eList[i].v;
		int l = eList[i].l;
		if (!isSameSet(u, v))
		{
			unionSet(u, v);
			count++;
			edges[u].push_back({ l, v });
			edges[v].push_back({ l, u });
			if (count == N - 1)
			{
				break;
			}
		}
	}
	
	FOR(i, 0, N)
	{
		scanf("%d", &type[i]);
	}
	FOR(i, 0, Q)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		updates[i].first = a;
		updates[i].second = b;
		if (p[a] != -1)
		{
			rangeSize[p[a]][b]++;
		}
	}
	p[0] = -1;
	dfs(0);
	LazySegmentTree st(values, values.size());
	FOR(i, 0, Q)
	{
		int a = updates[i].first;
		int b = updates[i].second;
		if (p[a] != -1)
		{
			if (b != type[p[a]])
			{
				st.update(0, 0, values.size() - 1, index[a], index[a], INF);
			}
			index[a] = range[p[a]][b].first + reached[p[a]][b] + 1;
			reached[p[a]][b]++;
		}
		st.update(0, 0, values.size() - 1, range[a][type[a]].first, range[a][type[a]].second, INF);
		st.update(0, 0, values.size() - 1, range[a][b].first, range[a][b].second, -INF);
		type[a] = b;
		cout << st.query(0, 0, values.size() - 1, 0, values.size() - 1);
	}
}