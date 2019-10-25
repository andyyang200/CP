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
int visited[100001];
int dfs(int u)
{
	if (visited[u])
	{
		return;
	}
	visited[u] = true;
	for (int i = 0; i < edges[u].size(); i++)
	{	
		int v = edges[u][i];
		dfs(v);
	}
}
int getDistance(int a, int b)
{
	
}
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u].push_back(v);
		edges[v].push_back(u);
	}





	int a, b;
	scanf("%d%d", &a, &b);
	queue<int> q;
	q.push(0);
	visited[0] = true;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < edges[u].size(); i++)
		{
			int v = edges[u][i];
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
	
}
int d[100001];
int bfs(int a, int b)
{
	queue<int> q;
	q.push(a);
	visited[a] = true;
	d[a] = 0;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int i = 0; i < edges[u].size(); i++)
		{
			int v = edges[u][i];
			d[v] = d[u] + 1;
			if (!visited[v])
			{
				visited[v] = true;
				q.push(v);
			}
		}
	}
}
//visited(state)
//dfs(state s)
//{
//	if (visited( s))
//	{
//		return;
//	}
//	visited(s) = true;
//	for (transition)
//	{
//		dfs(s + transition);
//	}
//}
// dfs(initial state)
