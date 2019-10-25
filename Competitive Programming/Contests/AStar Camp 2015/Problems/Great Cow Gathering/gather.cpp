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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
ll down[100001];
ll up[100001];
ll cost[100001];
int cows[100001];
vector<pii> edges[100001];
int totalCows;
void compute(int previous, int node, ll distance)
{
	down[node] = cows[node];
	cost[0] += cows[node] * distance;
	FOR(i, 0, edges[node].size())
	{
		if (edges[node][i].second == previous)
		{
			continue;
		}
		compute(node, edges[node][i].second, distance + edges[node][i].first);
		down[node] += down[edges[node][i].second];
	}
	up[node] = totalCows - down[node];
}
void dfs(int previous, int node)
{
	FOR(i, 0, edges[node].size())
	{
		if (edges[node][i].second == previous)
		{
			continue;
		}
		cost[edges[node][i].second] = cost[node] - down[edges[node][i].second] * edges[node][i].first + up[edges[node][i].second] * edges[node][i].first;
		dfs(node, edges[node][i].second);
	}
}
int main()
{
	freopen("gather.in", "r", stdin);
	freopen("gather.out", "w", stdout);
	int n;
	scanf("%d", &n);
	totalCows = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &cows[i]);
		totalCows += cows[i];
	}
	FOR(i, 0, n - 1)
	{
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		a--;
		b--;
		edges[a].push_back(pii(l, b));
		edges[b].push_back(pii(l, a));
	}
	compute(-1, 0, 0);
	dfs(-1, 0);
	ll ans = cost[0];
	FOR(i, 1, n)
	{
		ans = min(ans, cost[i]);
	}
	cout << ans << endl;
}