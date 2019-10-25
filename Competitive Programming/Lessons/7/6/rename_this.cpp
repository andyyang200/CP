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
/* given a directed weighted graph, what is the maximum number of edges in a path
if you can start and end anywhere, but every edge weights in you path must be strictly increasing?
 N, M <= 100000
*/





















vector< pair<int, int> > edges[100010];
int d[300010];
int n;
int m;

int main()
{
	cin >> n >> m;
	FOR(i, 0, n)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edges[w].push_back(make_pair(u, v));
	}


















	int ans = 0;
	int temp[300010];
	for (int x = 0; x < 100010; x++)
	{
		for (int i = 0; i < edges[x].size(); i++)
		{
			int u = edges[x][i].first;
			int v = edges[x][i].second;
			temp[v] = 0;
		}
		for (int i = 0; i < edges[x].size(); i++)
		{
			int u = edges[x][i].first;
			int v = edges[x][i].second;
			temp[v] = max(max(d[v], d[u] + 1), temp[v]);
			ans = max(temp[v], ans);
		}
		for (int i = 0; i < edges[x].size(); i++)
		{
			int u = edges[x][i].first;
			int v = edges[x][i].second;
			d[v] = temp[v];
		}
	}
	cout << ans << endl;
	return 0;
}