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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int h[100005];
int c[100005];

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
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}
	void update(int node, int a, int b, int i, int j, int v)
	{
		if (lazy[node] != 0)
		{
			st[node] += lazy[node] * (b - a + 1);
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
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}
	int query(int node, int a, int b, int i, int j)
	{
		if (a > b || a > j || b < i)
		{
			return 0;
		}
		if (lazy[node] != 0)
		{
			st[node] += lazy[node] * (b - a + 1);
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
		int res = q1 + q2;
		return res;
	}
};
int d[100005];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%d", &h[i]);
	}
	FOR(i, 0, m) {
		scanf("%d", &c[i]);
	}
	sort(h, h + n);
	FOR(i, 0, n) {
		if (i == 0) {
			d[i] = h[i];
		}
		else {
			d[i] = h[i] - h[i - 1];
		}
	}
	int j = 0;
	int val = 0;
	FOR(i, 0, n) {
		val += d[i];
		while (j < m && val > 0) {
			if (c[j] > (n - i)) {
				cout << j << endl;
				return 0;
			}
			val--;
			d[i + c[j]]++;
			j++;
		}
	}
	cout << m << endl;

}