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
int ans;
multiset<int> weights;
vector<pii> edges[1001];
vector<pii> g[1001];
int d[1001];
int n, p, k;
bool check(int x)
{
	FOR(i, 0, n)
	{
		d[i] = INF;
		g[i].clear();
		FOR(j, 0, edges[i].size())
		{
			pii edge = edges[i][j];
			g[i].push_back(make_pair((edge.first > x ? 1 : 0), edge.second));
		}
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	d[0] = 0;
	nodes.push(pii(0, 0));
	while (!nodes.empty())
	{
		int dis = nodes.top().first;
		int node = nodes.top().second;
		nodes.pop();
		if (dis != d[node])
		{
			continue;
		}
		FOR(i, 0, g[node].size())
		{
			pii edge = g[node][i];
			if (d[node] + edge.first < d[edge.second])
			{
				d[edge.second] = d[node] + edge.first;
				nodes.push(pii(d[edge.second], edge.second));
			}
		}
	}
	if (d[n - 1] == INF)
	{
		return false;
	}
	return d[n - 1] <= k;
}
int main()
{
	freopen("phoneline.in", "r", stdin);
	freopen("phoneline.out", "w", stdout);
	scanf("%d%d%d", &n, &p, &k);
	FOR(i, 0, p)
	{
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u--;
		v--;
		edges[u].push_back(make_pair(d, v));
		edges[v].push_back(make_pair(d, u));
	}
	ans = -1;
	int low = 0;
	int high = 1000000;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (check(mid))
		{
			high = mid - 1;
			ans = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << ans << endl;
}