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

vector<int> order;
vector<int> edges[100001];
int color[100001];
int n, m;
bool cycle = false;
void dfs(int node)
{
	if (color[node] != 0)
	{
		if (color[node] == 1)
		{
			cycle = true;
		}
		return;
	}
	color[node] = 1;
	for (int v : edges[node])
	{
		dfs(v);
	}
	order.push_back(node);
	color[node] = 2;
}

int dp[100001];

int main(void)
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	FOR(i, 0, n)
	{
		if (color[i] == 0)
		{
			dfs(i);
		}
	}
	reverse(order.begin(), order.end());




	// DAG = directed acyclic graph
	int longestPath = 0;
	RFOR(i, n - 1, -1)
	{
		dp[i] = 0;
		for (int edge : edges[i])
		{
			dp[i] = max(dp[i], 1 + dp[edge]); // if edges were weighted add weight of edge instead of 1
		}
		longestPath = max(longestPath, dp[i]);
	}
	cout << longestPath << endl; // longest path


	dp[n - 1] = 1;
	RFOR(i, n - 2, -1)
	{
		dp[i] = 0;
		for (int edge : edges[i])
		{
			dp[i] += dp[edge];
		}
	}
	cout << dp[0] << endl; // number of paths from 0 to n - 1
}