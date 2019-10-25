/*
ID: andyyang200
PROG: butter
LANG: C++
*/

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

int n, p, c;
int dis[801][801];
vector<pair<int, int> > v[801]; // distance, end
int numCows[801];

void dij(int source)
{
	FOR(i, 1, p + 1)
	{
		dis[source][i] = 1000000000;
	}
	dis[source][source] = 0;
	priority_queue <pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > nodes; // distance from source, node number
	nodes.push(pair<int, int>(0, source));
	while (!nodes.empty())
	{
		pair<int, int> node = nodes.top();
		nodes.pop();
		int d = node.first;
		int num = node.second;
		if (d != dis[source][num])
		{
			continue;
		}
		FOR(i, 0, v[num].size())
		{
			int nextNode = v[num][i].second;
			int nextDis = v[num][i].first;
			if (d + nextDis < dis[source][nextNode])
			{
				dis[source][nextNode] = dis[nextNode][source] = d + nextDis;
				nodes.push(pair<int, int>(dis[source][nextNode], nextNode));
			}
		}
	}
}

int main()
{
	freopen("butter.in", "r", stdin);
	freopen("butter.out", "w", stdout);
	cin >> n >> p >> c;
	FOR(i, 0, n)
	{
		int p;
		cin >> p;
		numCows[p]++;
	}
	FOR(i, 0, c)
	{
		int a, b, d;
		cin >> a >> b >> d;
		v[a].push_back(pair<int, int>(d, b));
		v[b].push_back(pair<int, int>(d, a));
	}
	FOR(i, 1, p + 1)
	{
		if (numCows[i] > 0)
		{
			dij(i);
		}
	}
	int min = 1000000000;
	FOR(i, 1, p + 1)
	{
		int sum = 0;
		FOR(j, 1, p + 1)
		{
			sum += numCows[j] * dis[i][j];
		}
		if (sum < min)
		{
			min = sum;
		}
	}
	cout << min << endl;
}