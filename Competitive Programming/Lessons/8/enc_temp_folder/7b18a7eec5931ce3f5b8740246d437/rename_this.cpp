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

//http://usaco.org/index.php?page=viewproblem2&cpid=624
class SegmentTree
{
public:
	int* st;
	int length;
	SegmentTree(int n)
	{
		length = n;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b)
	{
		return a + b;
	}
	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = 0;
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
	}
	void update(int node, int sl, int sr, int i, int v)
	{
		if (i < sl || i > sr)
			return;
		if (sl == sr)
		{
			st[node] = v;
		}
		if (sl != sr)
		{
			int mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, i, v);
			update(node * 2 + 2, mid + 1, sr, i, v);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	int query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int ql, int qr)
	{
		if (sl > qr || sr < ql)
			return -1;
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, ql, qr);
		int b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		if (a == -1)
			return b;
		if (b == -1)
			return a;
		return f(a, b);
	}
};
pii points[100001];

int main()
{
	int n;
	scanf("%d", &n);
	vector<int> v;
	FOR(i, 0, n)
	{
		scanf("%d%d", &points[i].first, &points[i].second);
		v.push_back(points[i].first);
		v.push_back(points[i].second);
	}
	sort(v.begin(), v.end());
	FOR(i, 0, n)
	{
		points[i].first = lower_bound(v.begin(), v.end(), points[i].first) - v.begin();
		points[i].second = lower_bound(v.begin(), v.end(), points[i].second) - v.begin();
	}
	sort(points, points + n);
	SegmentTree left(n);
	SegmentTree right(n);
	FOR(i, 0, n)
	{
		right.update(points[i].second, 1);
	}
	int ans = INF;
	FOR(i, 0, n)
	{
		int j = i;
		while (j < n && points[j].first == points[i].first)
		{
			j++;
			right.update(points[j].second, -1);
			left.update(points[j].second, 1);
		}
		i = j - 1;
		int l = 0;
		int r = n;
		while (l <= r)
		{
			int m = (l + r) >> 1;
			int a = left.query(m + 1, n);
			int c = left.query(0, m);
			int b = right.query(m + 1, n);
			int d = right.query(0, m);
			int x = max(max(a, b), max(c, d));
			ans = min(ans, x);
			if (a == x || b == x)
			{
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
	}
	cout << ans << endl;
}