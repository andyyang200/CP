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
/*

A simple graph contains N vertices and M edges. All edges have length 1.
The color of each vertex is initially 0.
You are given Q updates. In updates i, all vertices within di distance (di <= 10)
of vi are colored ci.
After all updates, output the color of each vertex.
(N, M, Q <= 100000)

Side note: A simple graph does not contain multiple edges between the same pair of points or self-loops.
Side Note 2: this is an offline problem, because all queries occur after all updates.

runtime: O(N * dmax + Q)
*/









vector<int> edges[100000];
int n, m, q;
int v[100000], d[100000], c[100000];
int ans[100000];
int maxDis[100000];
void dfs(int node, int dis, int color)
{
	if (dis < 0)
	{
		return;
	}
	if (maxDis[node] >= dis)
	{
		return;
	}
	maxDis[node] = dis;
	if (ans[node] == -1)
	{
		ans[node] = color;
	}
	for (int j : edges[node])
	{
		dfs(j, dis - 1, color);
	}

}
int main(void)
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	scanf("%d", &q);
	FOR(i, 0, q)
	{
		scanf("%d%d%d", &v[i], &d[i], &c[i]);
		v[i]--;
	}
	FOR(i, 0, n)
	{
		ans[i] = -1;
		maxDis[i] = -1;
	}
	RFOR(i, q - 1, -1)
	{
		dfs(v[i], d[i], c[i]);
	}
	FOR(i, 0, n)
	{
		if (ans[i] != -1)
		{
			printf("%d\n", ans[i]);
		}
		else
		{
			printf("%d\n", 0);
		}
	}
}