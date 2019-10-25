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
int x[201];
int y[201];
int p[201];
vector<int> edges[201];
bool visited[201];
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
int main(void)
{
	freopen("moocast.in", "r", stdin);
	freopen("moocast.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d%d", &x[i], &y[i], &p[i]);
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (i == j)
			{
				continue;
			}
			if (p[i] * p[i] >= abs(x[i] - x[j]) * abs(x[i] - x[j]) + abs(y[i] - y[j]) * abs(y[i] - y[j]))
			{
				edges[i].push_back(j);
			}
		}
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		FOR(i, 0, n)
		{
			visited[i] = false;
		}
		ans = max(ans, dfs(i));
	}
	cout << ans << endl;
}