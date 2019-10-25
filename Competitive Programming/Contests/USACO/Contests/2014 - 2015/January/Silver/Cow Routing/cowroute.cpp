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

ll d[1001][1001];
int flights[1001][1001];
bool visited[1001];
ll minDis[1001];
int minPaths[1001];
int main()
{
	freopen("cowroute.in", "r", stdin);
	freopen("cowroute.out", "w", stdout);
	int a, b, n;
	cin >> a >> b >> n;
	a--;
	b--;
	FOR(i, 0, 1001)
	{
		FOR(j, 0, 1001)
		{
			d[i][j] = (ll)2 << 50;
		}
	}
	FOR(i, 0, n)
	{
		ll cost;
		int numNodes;
		cin >> cost >> numNodes;
		int nodes[1001] = { 0 };
		FOR(j, 0, numNodes)
		{
			cin >> nodes[j];
			nodes[j]--;
		}
		FOR(x, 0, numNodes)
		{
			FOR(y, x + 1, numNodes)
			{
				if (cost < d[nodes[x]][nodes[y]])
				{
					d[nodes[x]][nodes[y]] = cost;
					flights[nodes[x]][nodes[y]] = y - x;
				}
			}
		}
	}
	FOR(i, 0, 1001)
	{
		minDis[i] = (ll)2 << 50;
		minPaths[i] = 1000000000;
	}
	minDis[a] = 0;
	minPaths[a] = 0;
	while (true)
	{
		int minNode = -1;
		ll minD = (ll)2 << 50;
		FOR(i, 0, 1001)
		{
			if (minDis[i] < minD && !visited[i])
			{
				minNode = i;
				minD = minDis[i];
			}
		}
		if (minNode == -1)
		{
			break;
		}
		visited[minNode] = true;
		FOR(i, 0, 1001)
		{
			if (minDis[minNode] + d[minNode][i] < minDis[i])
			{
				minDis[i] = minDis[minNode] + d[minNode][i];
				minPaths[i] = minPaths[minNode] + flights[minNode][i];
			}
			else if (minDis[minNode] + d[minNode][i] == minDis[i] && minPaths[minNode] + flights[minNode][i] < minPaths[i])
			{
				minPaths[i] = minPaths[minNode] + flights[minNode][i];
			}
		}
	}
	if (minDis[b] == (ll)2 << 50)
	{
		cout << "-1 -1" << endl;
	}
	else
	{
		cout << minDis[b] << " " << minPaths[b] << endl;
	}
}