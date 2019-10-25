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
// Given a weighted undirected graph, minimize the maximum edge weight in a path from a to b.
// alternate solution: sort edges by weight, then loop through and use union find to add edge and query if a and b are connected





















vector<pii> edges[100001];
ll d[100001];
int n, m;
void dijkstra(int source, int m)
{
	FOR(i, 0, n)
	{
		d[i] = 1000000000000;
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	d[source] = 0;
	nodes.push(pii(0, source));
	while (!nodes.empty())
	{
		ll dis = nodes.top().first;
		int node = nodes.top().second;
		nodes.pop();
		if (dis != d[node])
		{
			continue;
		}
		for (pii edge : edges[node])
		{
			if (edge.first > m)
			{
				continue;
			}
			if (d[node] + edge.first < d[edge.second])
			{
				d[edge.second] = d[node] + edge.first;
				nodes.push(pii(d[edge.second], edge.second));
			}
		}
	}
}
int main(void)
{
	scanf("%d%d", &n, &m);
	int l = 0;
	int r = 0;
	FOR(i, 0, m)
	{
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		u--;
		v--;
		edges[u].push_back({ x, v });
		edges[v].push_back({ x, u });
		r = max(r, x);
	}
	int a, b;
	scanf("%d%d", &a, &b);
	a--;
	b--;
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		dijkstra(a, m);
		if (d[b] < 1000000000000)
		{
			r = m - 1;
			ans = m;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << ans << endl;
}