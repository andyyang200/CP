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
vector<int> edges[100001];
int color[100001];
int cycle;
void dfs(int node, int parent)
{
	color[node] = 1;
	FOR(i, 0, edges[node].size())
	{
		if (edges[node][i] == parent)
		{
			continue;
		}
		if (color[edges[node][i]] == 1)
		{
			cycle = true;
		}
		if (color[edges[node][i]] == 0)
		{
			dfs(edges[node][i], node);
		}
	}
	color[node] = 2;
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		edges[x].push_back(y);
		edges[y].push_back(x);
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		if (color[i] == 0)
		{
			cycle = false;
			dfs(i, -1);
			if (!cycle)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}