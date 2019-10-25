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
int height[100001];
bool visited[100001];
int cuts[100001];
vector<int> edges[100001];
int n, s;
void dfs(int node, int maxDiameter)
{
	visited[node] = true;
	vector<int> heights;
	FOR(i, 0, edges[node].size())
	{
		if (!visited[edges[node][i]])
		{
			dfs(edges[node][i], maxDiameter);
			cuts[node] += cuts[edges[node][i]];
			heights.push_back(height[edges[node][i]]);
		}
	}
	if (heights.size() > 0) 
	{
		sort(heights.begin(), heights.end());
		reverse(heights.begin(), heights.end());
		int i = 0;
		while (i < heights.size() - 1 && heights[i] + heights[i + 1] + 1 > maxDiameter)
		{
			i++;
		}
		if (i < heights.size() - 1) 
		{
			cuts[node] += i;
			height[node] = heights[i] + 1;
		}
		else if (heights[i] > maxDiameter) 
		{
			cuts[node] += i + 1;
			height[node] = 2;
		}
		else 
		{
			cuts[node] += i;
			height[node] = heights[i] + 1;
		}
	}
}
int main()
{
	freopen("exercise.in", "r", stdin);
	freopen("exercise.out", "w", stdout);
	scanf("%d%d", &n, &s);
	FOR(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	int l = 0;
	int r = INF;
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) / 2;
		memset(cuts, 0, sizeof(cuts));
		memset(visited, false, sizeof(visited));
		memset(height, 1, sizeof(height));
		dfs(0, m);
		if (cuts[0] <= s)
		{
			r = m - 1;
			ans = m;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << ans - 1 << endl;
}