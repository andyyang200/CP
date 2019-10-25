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
int x[1001];
int y[1001];
vector<int> edges[1001];
int n;
bool visited[1001];
int dfs(int u)
{
	if (visited[u])
	{
		return 0;
	}
	visited[u] = true;
	int ret = 1;
	for (int v : edges[u])
	{
		ret += dfs(v);
	}
	return ret;
}
bool check(int mid)
{
	FOR(i, 0, n)
	{
		edges[i].clear();
		visited[i] = false;
	}
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			if (mid >= abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]))
			{
				edges[i].push_back(j);
				edges[j].push_back(i);
			}
		}
	}
	return dfs(0) == n;
}
int main(void)
{
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &x[i], &y[i]);
	}
	int l = 0;
	int r = 25000 * 25000;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans << endl;
}