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
map<char, int> m;
vector<pii> edges[100000]; // distance to source, end node number; initialize
ll d[100000];
int n;// initialize
void dijkstra(int source)
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
	cin >> m['1'];
	cin >> m['2'];
	cin >> m['3'];
	cin >> m['u'];
	cin >> m['4'];
	cin >> m['5'];
	cin >> m['6'];
	cin >> m['d'];
	cin >> m['7'];
	cin >> m['8'];
	cin >> m['9'];
	cin >> m['l'];
	cin >> m['0'];
	int x;
	int y;
	n = 100;
	cin >> x >> y;
	FOR(n, 0, 100) {
		FOR(i, 0, 10) {
			if (m['0' + i]) {
				edges[n].push_back({ 1, i });
			}
		}

		FOR(i, 10, 100) {
			if (m['l'] && m['0' + i / 10] && m['0' + i % 10]) {
				edges[n].push_back({ 3, i });
			}
		}

		if (m['u']) {
			edges[n].push_back({ 1, (n + 1) % 100 });
		}

		if (m['d']) {
			edges[n].push_back({ 1,(n - 1 + 100) % 100 });
		}

	}
	dijkstra(x);
	if (d[y] > 1000) {
		cout << -1 << endl;
	}
	else {
		cout << d[y] << endl;
	}
}
/*
0 0 1 1
1 1 1 1
1 1 1
1 1
23
52
*/