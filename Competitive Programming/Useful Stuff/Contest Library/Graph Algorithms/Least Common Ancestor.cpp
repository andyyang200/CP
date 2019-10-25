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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;
#define INF 1000000000

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
	pii f(pii a, pii b) // change for different problems
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
vector<pii> adj[10001]; // {neighbor, cost}, build this first
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
		}
	}
}
void prepLCA() // call this first
{
	x = 0;
	tour(0, -1, 0);
	LCAst = SegmentTreeLCA(LCAdepth, 2 * 100000);
}
int getLCA(int u, int v) //prepLCA first!
{
	return LCApath[LCAst.query(min(LCAid[u], LCAid[v]), max(LCAid[u], LCAid[v])).second];
}