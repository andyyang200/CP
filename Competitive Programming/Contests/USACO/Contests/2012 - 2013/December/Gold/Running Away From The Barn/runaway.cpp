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
ll dis[200005];
int ans[200005];
int overcount[200005];
vector<int> edges[200005];
int chain[200005];
int n;
ll l;
void dfs(int depth)
{
	int left = 0;
	int right = depth;
	int x = -1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (dis[chain[depth]] - dis[chain[mid]] <= l)
		{
			x = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	if (x > 0)
	{
		overcount[chain[x - 1]]++;
	}
	FOR(i, 0, edges[chain[depth]].size())
	{
		chain[depth + 1] = edges[chain[depth]][i];
		dfs(depth + 1);
	}
}
int main()
{
	freopen("runaway.in", "r", stdin);
	freopen("runaway.out", "w", stdout);
	scanf("%d%lld", &n, &l);
	FOR(i, 1, n)
	{
		int p;
		ll d;
		scanf("%d%lld", &p, &d);
		p--;
		dis[i] = d + dis[p];
		edges[p].push_back(i);
	}
	FOR(i, 0, n)
	{
		ans[i] = 1;
	}
	dfs(0);
	RFOR(i, n - 1, -1)
	{
		FOR(j, 0, edges[i].size())
		{
			ans[i] += ans[edges[i][j]];
		}
		ans[i] -= overcount[i];
	}
	FOR(i, 0, n)
	{
		printf("%d\n", ans[i]);
	}
}