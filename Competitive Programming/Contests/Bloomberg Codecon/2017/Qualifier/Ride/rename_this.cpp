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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int sc, sp, md, cr, cy, pr, py, n, m;
int grid[105][105];
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
vector<pii> edges[100005]; // distance to source, end node number; initialize
ll dcar[100005];
ll dperson[100005];
void dijkstra(int source, ll d[])
{
	FOR(i, 0, n * m)
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
			if (d[node] + edge.first < d[edge.second])
			{
				d[edge.second] = d[node] + edge.first;
				nodes.push(pii(d[edge.second], edge.second));
			}
		}
	}
}
int getkey(int i, int j) {
	return i * m + j;
}
bool isvalid(int i, int j) {
	return i >= 0 && i < n && j >= 0 && j < m;
}
int main(void)
{
	cin >> sc >> sp >> md >> cr >> cy >> pr >> py >> n >> m;
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			cin >> grid[i][j];
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, m) {
			FOR(x, 0, 4) {
				int ni = i + dx[x];
				int nj = j + dy[x];
				if (!isvalid(ni, nj)) continue;
				int u = getkey(i, j);
				int v = getkey(ni, nj);
				edges[u].push_back({ grid[ni][nj], v });
				
			}
		}
	}
	dijkstra(getkey(cr, cy), dcar);
	dijkstra(getkey(pr, py), dperson);
	ll ans = INF;
	FOR(i, 0, n * m) {
		ll t1 = dcar[i] / sc;
		ll t2 = dperson[i] / sp;
		if (dperson[i] > md) continue;
		if (t1 < t2) continue;
		ans = min(ans, max(t1, t2));
	}
	cout << ans << endl;
}