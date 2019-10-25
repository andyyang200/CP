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

int dis[15][15];
int dp[100000][15];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j != i)
			{
				dis[i][j] = INF;
			}
		}
	}
	for (int i = 0; i < m; i++)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u--;
		v--;
		dis[u][v] = min(dis[u][v], d);
		dis[v][u] = min(dis[v][u], d);
	}
	for (int k = 0; k < n; k++) // floyd warshall
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	memset(dp, INF, sizeof(int) * 100000 * 15);
	for (int mask = 1; mask < (1 << n); mask++)
	{
		for (int i = 0; i < n; i++)
		{
			if (mask == (1 << i)) // base case
			{
				dp[mask][i] = 0;
			}
			if (!(mask & (1 << i))) // impossible to end at i
			{
				continue;
			}
			for (int j = 0; j < n; j++)
			{
				if (!(mask & (1 << j))) // check if j is not visited
				{
					dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + dis[i][j]);
				}
			}
		}
	}
	int ans = INF;
	for (int i = 0; i < n; i++)
	{
		ans = min(ans, dp[(1 << n) - 1][i]);
	}
	cout << ans << endl;
}