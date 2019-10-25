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
int c[1001];
bool visited[1001];
vector<int> edges[1001];
int nodes, path;
int maxNodes;

void dfs(int node)
{
	if (visited[node])
	{
		return;
	}
	visited[node] = true;
	nodes++;
	path += edges[node].size();
	for (int i : edges[node])
	{
		dfs(i);
	}
}

int main(void)
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, k)
	{
		int x;
		scanf("%d", &x);
		x--;
		c[i] = x;
	}
	FOR(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int ans = 0;
	maxNodes = 0;
	FOR(i, 0, k)
	{
		nodes = 0;
		path = 0;
		dfs(c[i]);
		path /= 2;
		n -= nodes;
		m -= path;
		maxNodes = max(maxNodes, nodes);
		ans += (nodes) * (nodes - 1) / 2 - path;
	}
	if (n > 0)
	{
		ans += (n) * (n - 1) / 2 + n * maxNodes - m;
	}
	cout << ans << endl;
}