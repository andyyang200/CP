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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<ll, int> pii;

vector<pii> edges[251]; // distance to source, end node number
int parent[251];
ll d[251];
vector<pii> path;
int n, m;

void dijk(int source)
{
	FOR(i, 0, n)
	{
		d[i] = 1000000000000;
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	parent[source] = -1;
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
		for(pii edge: edges[node])
		{
			if (d[node] + edge.first < d[edge.second])
			{
				d[edge.second] = d[node] + edge.first;
				parent[edge.second] = node;
				nodes.push(pii(d[edge.second], edge.second));
			}
		}
	}
}

int main()
{
	freopen("rblock.in", "r", stdin);
	freopen("rblock.out", "w", stdout);
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		edges[a].push_back(pii(c, b));
		edges[b].push_back(pii(c, a));
	}
	dijk(0);
	int cur = n - 1;
	while (parent[cur] != -1)
	{
		path.push_back(pii(cur, parent[cur]));
		cur = parent[cur];
	}
	ll original = d[n - 1];
	ll best = d[n - 1];
	for (pii edge: path)
	{
		pii * a, * b;
		FOR (i, 0, edges[edge.first].size())
		{
			a = &edges[edge.first][i];
			if (a->second == edge.second)
			{
				break;
			}
		}
		FOR(i, 0, edges[edge.second].size())
		{
			b = &edges[edge.second][i];
			if (b->second == edge.first)
			{
				break;
			}
		}
		a->first *= 2;
		b->first *= 2;
		dijk(0);
		best = max(best, d[n - 1]);
		a->first /= 2;
		b->first /= 2;
	}
	cout << best - original << endl;
}