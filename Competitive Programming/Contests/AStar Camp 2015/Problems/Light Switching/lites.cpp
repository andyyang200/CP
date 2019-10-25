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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int arr[1000005];
int t[3000005];
int lazy[3000005];

void build(int node, int a, int b)
{
	if (a>b) return;
	if (a == b)
	{
		t[node] = arr[a];
		return;
	}

	build(node * 2, a, (a + b) / 2);
	build(node * 2 + 1, (a + b) / 2 + 1, b);

	t[node] = t[node * 2] + t[node * 2 + 1];
}

int query(int node, int a, int b, int i, int j)
{
	if (a>b || a>j || b<i) return 0;
	if (lazy[node] != 0)
	{
		t[node] += lazy[node] * (b - a + 1);
		if (a != b)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (a >= i && b <= j) return t[node];

	int q1 = query(node * 2, a, (a + b) / 2, i, j);
	int q2 = query(node * 2 + 1, (a + b) / 2 + 1, b, i, j);

	return q1 + q2;
}

void update(int node, int a, int b, int i, int j, int inc)
{
	if (a>b) return;
	if (lazy[node] != 0)
	{
		t[node] += lazy[node] * (b - a + 1);
		if (a != b)
		{
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (a>b || a>j || b<i) return;

	if (a >= i && b <= j)
	{
		t[node] += inc*(b - a + 1);
		if (a != b)
		{
			lazy[node * 2] += inc;
			lazy[node * 2 + 1] += inc;
		}
		return;
	}

	update(node * 2, a, (a + b) / 2, i, j, inc);
	update(node * 2 + 1, (a + b) / 2 + 1, b, i, j, inc);
	t[node] = t[node * 2] + t[node * 2 + 1];
}
int main()
{
	//freopen("lites.in", "r", stdin);
	//freopen("lites.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	build(1, 0, n - 1);
	FOR(i, 0, m)
	{
		int type, l, r;
		scanf("%d%d%d", &type, &l, &r);
		l--;
		r--;
		if (type)
		{
			printf("%d\n", query(1, 0, n - 1, l, r));
		}
		else
		{
			update(1, 0, n - 1, l, r, 1);
		}
	}
}