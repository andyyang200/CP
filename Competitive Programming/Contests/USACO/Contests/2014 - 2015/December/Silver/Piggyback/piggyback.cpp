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
typedef pair<int, int> pii;

map<int, vector<int> > edges;
map<pii, int> dist;

void bfs(int start)
{
	bool visited[40002] = {false};
	queue<pii> q; // distance to start, node number
	q.push(pii(0, start));
	visited[start] = true;
	while (!q.empty())
	{
		int d = q.front().first;
		int node = q.front().second;
		dist[pii(start, node)] = d;
		q.pop();
		FOR(i, 0, edges[node].size())
		{
			if (!visited[edges[node][i]])
			{
				visited[edges[node][i]] = true;
				q.push(pii(d + 1, edges[node][i]));
			}
		}
	}
}

int main()
{
	//freopen("piggyback.in", "r", stdin);
	//freopen("piggyback.out", "w", stdout);
	int b, e, p, n, m;
	cin >> b >> e >> p >> n >> m;
	FOR(i, 0, m)
	{
		int a, b;
		cin >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	bfs(1);
	bfs(2);
	bfs(n);
	int ans = 1000000000;
	FOR(i, 1, n + 1)
	{
		ans = min(ans, b * dist[pii(1, i)] + e * dist[pii(2, i)] + p * dist[pii(n, i)]);
	}
	cout << ans << endl;
}