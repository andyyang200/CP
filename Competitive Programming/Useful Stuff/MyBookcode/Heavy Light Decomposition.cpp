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


vector<pii> edges[10001]; // {neighbor, cost};
int parent[10001];
int heavy[10001];
int sz[10001];
int chainHead[10001];
int stIndex[10001];
int chainPosition[10001];
int cost[10001];
int n;
class SegmentTreeMax
{
public:
	ll* st;
	int* a;
	int length;
	SegmentTreeMax()
	{

	}
	SegmentTreeMax(int arr[], int n)
	{
		length = n;
		a = new int[n];
		memcpy(a, arr, sizeof(int)*n);
		int height = (int)(ceil(log2(n)));
		int maxSize = 4 * (1 << height) - 1;
		st = new ll[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b)
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
	void update(int node, int sl, int sr, int i, int v)
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

	int query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > qr || sr < ql || sl > sr)
			return 0;
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, ql, qr);
		int b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		return f(a, b);
	}
};
SegmentTreeMax st;
int a[200005];
void dfsHLD(int u){ // helper; for HLD
	sz[u] = 1;
	for(pii edge : edges[u]){
		int v = edge.first;
		if (v == parent[u]){
			continue;
		}
		parent[v] = u;
		cost[v] = edge.second;
		dfsHLD(v);
		sz[u] += sz[v];
	}
	for(pii edge : edges[u]){
		int v = edge.first;
        if (v == parent[u]){
            continue;
        }
		if (sz[v] > sz[u] / 2){
			heavy[u] = v;
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
	FOR(i, 0, n){
		if (parent[i] == -1 || heavy[parent[i]] != i){
			for (int k = i; k != -1; k = heavy[k]){
                a[c] = cost[k];
                stIndex[k] = c++;
				chainHead[k] = i;
			}
		}
	}
	st = SegmentTreeMax(a, n * 2);
}
// lca
class SegmentTreeLCA{
public:
	pii* st;
	int* a;
	int length;
	SegmentTreeLCA(){

	}
	SegmentTreeLCA(int arr[], int n){
		length = n;
		a = new int[n];
		memcpy(a, arr, sizeof(int)*n);
		int height = (int)(ceil(log2(n)));
		int maxSize = 4 * (1 << height) - 1;
		st = new pii[maxSize];
		build(0, 0, length - 1);
	}
	pii f(pii a, pii b){
		return min(a, b);
	}
	void build(int node, int l, int r){
		if (l == r){
			st[node].first = a[l];
			st[node].second = l;
		}
		else{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}
	pii query(int ql, int qr){
		return query(0, 0, length - 1, ql, qr);
	}
	pii query(int node, int sl, int sr, int ql, int qr){
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
void tour(int u, int p, int d){
	LCAid[u] = x;
	LCApath[x] = u;
	LCAdepth[x++] = d;
	for(pii edge : edges[u]){
        int v = edge.first;
		if (v != p){
			tour(v, u, d + 1);
			LCApath[x] = u;
			LCAdepth[x++] = d;
			if (x < 0 || x >= 100000){
				return;
			}
		}
	}
}
int getLCA(int u, int v){ //prepLCA first!
	return LCApath[LCAst.query(min(LCAid[u], LCAid[v]), max(LCAid[u], LCAid[v])).second];
}
void prepLCA(){ // call this first
	x = 0;
	tour(0, -1, 0);
	LCAst = SegmentTreeLCA(LCAdepth, 2 * 100000);
}
// end lca
ll queryUp(int a, int lca){
	int ans = 0;
	while (a != lca){
		if (heavy[parent[a]] != a){ // light edge
			ans = max(ans, cost[a]);
			a = parent[a];
		}
		else{ // heavy path
            int b = -1;
			if (chainHead[lca] == chainHead[a]){
			    b = lca;
            }
			else{
			    b = chainHead[a];
			}
            int x = st.query(stIndex[b] + 1, stIndex[a]);
            ans = max(ans, x);
            a = b;
            break;
		}
	}
	return ans;
}
ll query(int a, int b){
	int lca = getLCA(a, b);
	return max(queryUp(a, lca), queryUp(b, lca));
}
void update(pii edge, int v){
	int a = edge.first;
	int b = edge.second;
	if (parent[b] != a){
        swap(a, b);
    }
	if (chainHead[a] == chainHead[b]){
        st.update(stIndex[b], v);
	}
    cost[b] = v;
}
pii edgeList[100005];
int main() // test
{
	int t;
	scanf("%d", &t);
	FOR(sets, 0, t)
	{
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			edges[i].clear();
		}
		FOR(i, 0, n - 1)
		{
			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			a--;
			b--;
			edges[a].push_back(pii(b, c));
			edges[b].push_back(pii(a, c));
			edgeList[i] = pii(a, b);
		}
		prepLCA();
		HLD();
		char s[10];
		scanf("%s", s);
		while (s[0] != 'D')
		{
			int a, b;
			scanf("%d%d", &a, &b);
			if (s[0] == 'C')
			{
				a--;
				update(edgeList[a], b);
			}
			else
			{
				a--;
				b--;
				printf("%d\n", query(a, b));
			}
			scanf("%s", s);
		}
	}
}
