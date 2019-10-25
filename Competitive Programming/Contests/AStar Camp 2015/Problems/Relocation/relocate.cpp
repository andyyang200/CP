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
map<pii, int> d;
vector<pii> edges[10001];
int n, m, k;
int markets[6];
void dijkstra(int& source)
{
	FOR(i, 0, n)
	{
		d[pii(source, i)] = INF;
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	d[pii(source, source)] = 0;
	nodes.push(pii(0, source));
	while (!nodes.empty())
	{
		int dis = nodes.top().first;
		int node = nodes.top().second;
		nodes.pop();
		if (dis != d[pii(source, node)])
		{	
			continue;
		}
		FOR (i, 0, edges[node].size())
		{
			pii edge = edges[node][i];
			if (d[pii(source, node)] + edge.first < d[pii(source, edge.second)])
			{
				d[pii(source, edge.second)] = d[pii(source, node)] + edge.first;
				nodes.push(pii(d[pii(source, edge.second)], edge.second));
			}
		}
	}
}
int main()
{
	freopen("relocate.in", "r", stdin);
	freopen("relocate.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, k)
	{
		scanf("%d", &markets[i]);
		markets[i]--;
	}
	FOR(i, 0, m)
	{
		int u, v, l;
		scanf("%d%d%d", &u, &v, &l);
		u--;
		v--;
		edges[u].push_back(pii(l, v));
		edges[v].push_back(pii(l, u));
	}
	FOR(i, 0, k)
	{
		dijkstra(markets[i]);
	}
	int ans = INF;
	int permutation[] = { 0, 1, 2, 3, 4, 5};
	do
	{
		int travel = 0;
		FOR(j, 1, k)
		{
			travel += d[pii(markets[permutation[j]], markets[permutation[j - 1]])];
		}
		FOR(i, 0, n)
		{
			bool isMarket = false;
			FOR(j, 0, k)
			{
				if (i == markets[j])
				{
					isMarket = true;
					break;
				}
			}
			if (isMarket)
			{
				continue;
			}
			int dis = travel;
			dis += d[pii(markets[permutation[0]], i)];
			dis += d[pii(markets[permutation[k - 1]], i)];
			ans = min(ans, dis);
		}
	} while (next_permutation(permutation, permutation + k));
	cout << ans << endl;
}