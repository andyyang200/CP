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

vector<pii> edges[100000]; // distance to source, end node number; initialize
ll d[100000];
int n, m; // initialize
void dijkstra(int source)
{
	FOR(i, 0, n)
	{
		d[i] = 1000000000000;
	}
	priority_queue<pii, vector<pii>, greater<pii>> nodes; // distance to source, node number
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
	FOR(i, 0, m)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u--;
		v--;
		edges[u].push_back({ d, v });
		edges[v].push_back({ d, u });
	}
	int a, b;
	scanf("%d%d", &a, &b);
	a--;
	b--;
	dijkstra(a);
	cout << d[b] << endl;
}