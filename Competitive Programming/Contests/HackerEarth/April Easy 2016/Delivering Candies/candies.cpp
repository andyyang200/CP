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
typedef pair<long long, long long> pii;
ll d[100001];
vector<pii> edges[100001]; // dis, nxt
ll n, m, s;
ll k[100001];
void dijkstra(ll& source)
{
	FOR(i, 0, n)
	{
		d[i] = (ll)1 << 50;
	}
	priority_queue<pii, vector<pii>, greater<pii> > nodes; // distance to source, node number
	d[source] = 0;
	nodes.push(pii(0, source));
	while (!nodes.empty())
	{
		ll dis = nodes.top().first;
		ll node = nodes.top().second;
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
int main()
{
	cin >> n >> m >> s;
	s--;
	ll totalPeople = 0;
	FOR(i, 0, n)
	{
		cin >> k[i];
		totalPeople += k[i];
	}
	FOR(i, 0, m)
	{
		int a, b, d;
		scanf("%d%d%d", &a, &b, &d);
		a--;
		b--;
		edges[a].push_back({ d, b });
		edges[b].push_back({ d, a });
	}
	dijkstra(s);
	ll total = 0;
	FOR(i, 0, n)
	{
		if (d[i] == (ll)1 << 50)
		{
			totalPeople -= k[i];
			continue;
		}
		total += d[i] * k[i];
	}
	FOR(i, 0, n)
	{
		if (d[i] == (ll)1 << 50)
		{
			cout << 0 << " ";
			continue;
		}
		ll ans = total + d[i] * totalPeople - 2 * d[i] * k[i];
		cout << ans << " ";
	}
	cout << endl;
}