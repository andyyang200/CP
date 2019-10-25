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
vector<int> edges[200001];
int color[200001];
int p[200001];
int maxC = 0;
void dfs(int node)
{
	if (node == 0)
	{
		color[node] = 1;
		p[node] = -1;
	}
	int c = 1;
	for (int edge : edges[node])
	{
		if (edge == p[node])
		{
			continue;
		}
		p[edge] = node;
		while (c == color[node] || (p[node] != -1 && c == color[p[node]]))
		{
			c++;
		}
		color[edge] = c;
		maxC = max(maxC, c);
		c++;
		dfs(edge);
	}
}
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n - 1)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	dfs(0);
	cout << maxC << endl;
	FOR(i, 0, n)
	{
		cout << color[i] << " ";
	}
	cout << endl;
}