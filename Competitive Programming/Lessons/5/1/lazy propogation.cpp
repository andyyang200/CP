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
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
// lazy propagation
class LazySegmentTree
{
public:
	int* st;
	int* arr;
	int* lazy;
	int length;
	LazySegmentTree(int a[], int n)
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
		if (a == b)
		{
			st[node] = arr[a];
			return;
		}
		build(node * 2 + 1, a, (a + b) / 2);
		build(node * 2 + 2, 1 + (a + b) / 2, b);
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}
	void update(int node, int sl, int sr, int ql, int qr, int v)
	{
		if (lazy[node] != 0)
		{
			st[node] += lazy[node] * (sr - sl + 1);
			if (sl != sr)
			{
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (sl > sr || sl > qr || sr < ql)
		{
			return;
		}
		if (sl >= ql && sr <= qr)
		{
			st[node] += v * (sl - sr + 1);
			if (sl != sr)
			{
				lazy[node * 2 + 1] += v;
				lazy[node * 2 + 2] += v;
			}
			return;
		}
		int mid = (sl + sr) / 2;
		update(node * 2 + 1, sl, mid, ql, qr, v);
		update(node * 2 + 2, mid + 1, sr, ql, qr, v);
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}
	int query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > sr || sl > qr || sr < ql)
		{
			return 0;
		}
		if (lazy[node] != 0)
		{
			st[node] += lazy[node] * (sr - sl + 1);
			if (sl != qr)
			{
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (sl >= ql && sr <= qr)
		{
			return st[node];
		}
		int mid = (sl + sr) / 2;
		int q1 = query(node * 2 + 1, sl, mid, ql, qr);
		int q2 = query(node * 2 + 2, mid + 1, sr, ql, qr);
		int res = q1 + q2;
		return res;
	}
};
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
}