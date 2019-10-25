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
class SegmentTree
{
public:
	int* st;
	int* a;
	int length;
	SegmentTree(int arr[], int n)
	{
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
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
int c[1005][1005];
int l[1000005];
int r[1000005];
bool b[1000005];
int u[1000005];
int d[1000005];
int main(void)
{
	freopen("art.in", "r", stdin);
	freopen("art.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, n + 1)
		{
			scanf("%d", &c[i][j]);
			if (u[c[i][j]] == 0)
			{
				u[c[i][j]] = i;
			}
			else
			{
				u[c[i][j]] = min(u[c[i][j]], i);
			}
			if (l[c[i][j]] == 0)
			{
				l[c[i][j]] = j;
			}
			else
			{
				l[c[i][j]] = min(l[c[i][j]], j);
			}
			d[c[i][j]] = max(d[c[i][j]], i);
			r[c[i][j]] = max(r[c[i][j]], j);
		}
	}
	set<int> s;
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, n + 1)
		{
			if (c[i][j] != 0)
			{
				s.insert(c[i][j]);
			}
		}
	}
	if (s.size() == 1)
	{
		cout << n * n - 1;
		return 0;
	}
	FOR(i, 1, n + 1)
	{
		FOR(j, 1, n + 1)
		{
			if (u[c[i][j]] == 0)
			{
				u[c[i][j]] = i;
			}
			else
			{
				u[c[i][j]] = min(u[c[i][j]], i);
			}
			if (l[c[i][j]] == 0)
			{
				l[c[i][j]] = j;
			}
			else
			{
				l[c[i][j]] = min(l[c[i][j]], j);
			}
			d[c[i][j]] = max(d[c[i][j]], i);
			r[c[i][j]] = max(r[c[i][j]], j);
		}
	}
	FOR(x, 1, 1000001)
	{
		if (d[x])
		{
			FOR(i, u[x], d[x] + 1)
			{
				FOR(j, l[x], r[x] + 1)
				{
					if (c[i][j] != x)
					{
						b[c[i][j]] = true;
					}
				}
			}
		}
	}
	int ans = 0;
	FOR(x, 1, 1000001)
	{
		ans += b[x];
	}
	cout << (long)n * n - ans << endl;
}