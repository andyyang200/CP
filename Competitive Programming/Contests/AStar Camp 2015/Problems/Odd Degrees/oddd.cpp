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
bool visited[50001];
int size;
struct Edge
{
	int u, v, index;
	Edge(int a, int b, int c)
	{
		u = a;
		v = b;
		index = c;
	}
};
vector<Edge> edges[50001];
vector<int> ans;
bool dfs(Edge e) 
{
	if (visited[e.v]) 
	{
		return false;
	}
	visited[e.v] = true;
	int count = 0;
	for (int i = 0; i < edges[e.v].size(); i++) 
	{
		if (edges[e.v][i].v != e.u) 
		{
			if (dfs(edges[e.v][i]))
			{
				count++;
			}
		}
	}
	if (count % 2 == 0) 
	{
		ans.push_back(e.index);
		return true;
	}
	return false;
}
int main()
{
	freopen("oddd.in", "r", stdin);
	freopen("oddd.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(Edge(u, v, i + 1));
		edges[v].push_back(Edge(v, u, i + 1));
	}
	FOR(i, 0, n)
	{
		if (!visited[i])
		{
			if (dfs(Edge(-1, i, -1)))
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}
	cout << ans.size() << endl;
	FOR(i, 0, ans.size())
	{
		cout << ans[i] << endl;
	}

}