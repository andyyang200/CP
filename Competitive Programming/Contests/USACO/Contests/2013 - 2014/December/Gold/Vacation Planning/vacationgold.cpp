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
typedef long long ll;
typedef pair<int, int> pii;

struct Edge
{
	int next, weight;
	Edge(int a, int b)
	{
		next = a;
		weight = b;
	}
};

int distances[200][20000];
int distancesReversed[200][20000];
int hubs[200];
vector<Edge> edges[20000];
vector<Edge> edgesReversed[20000];
int N, M, K, Q;

void dijkstra(int source, int d[200][20000], bool reversed)
{
	FOR(i, 0, N)
	{
		d[source][i] = INF;
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	d[source][hubs[source]] = 0;
	nodes.push(pii(0, hubs[source]));
	while (!nodes.empty())
	{
		ll dis = nodes.top().first;
		int node = nodes.top().second;
		nodes.pop();
		if (dis != d[source][node])
		{
			continue;
		}
		for (Edge edge : (reversed ? edgesReversed[node] : edges[node]))
		{
			if (d[source][node] + edge.weight < d[source][edge.next])
			{
				d[source][edge.next] = d[source][node] + edge.weight;
				nodes.push(pii(d[source][edge.next], edge.next));
			}
		}
	}
}

int main()
{
	freopen("vacationgold.in", "r", stdin);
	freopen("vacationgold.out", "w", stdout);
	scanf("%d%d%d%d", &N, &M, &K, &Q);
	FOR(i, 0, M)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u--;
		v--;
		edges[u].push_back(Edge(v, d));
		edgesReversed[v].push_back(Edge(u, d));
	}
	FOR(i, 0, K)
	{
		scanf("%d", &hubs[i]);
		hubs[i]--;
	}
	FOR(i, 0, K)
	{
		dijkstra(i, distances, false);
		dijkstra(i, distancesReversed, true);
	}
	int count = 0;
	ll total = 0;
	FOR(i, 0, Q)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		int minCost = INF;
		FOR(i, 0, K)
		{
			int cost = distancesReversed[i][a] + distances[i][b];
			minCost = min(minCost, cost);
		}
		if (minCost < INF)
		{
			count++;
			total += minCost;
		}
	}
	cout << count << endl;
	cout << total << endl;
}