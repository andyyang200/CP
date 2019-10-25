#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;


#include "Johnson.h"
#include "warshall_floyd.h"
#include "dijkstra.h"

int main_test()
{
	freopen("ShortestPathAlgorithm\\data.in", "r", stdin);
	freopen("ShortestPathAlgorithm\\data.out", "w", stdout);
	int N, M;
	cin >> N >> M;

	// set up Johnson, most efficient
	Johnson js;
	js.g.resize(N + 1);

	int i, j;

	// set up warshall floyd, it uses vector of vectors
	// can be easily modified to use matrix to boost performance
	vector<vector<int> > cost;
	cost.resize(N);
	REP(i, N)
	{
		cost[i].resize(N);
		REP(j, N)
		{
			cost[i][j] = INT_MAX;
		}
	}

	// set up dijkstra
	// note: it has limit of node defined: MAX_N 10000
	g.resize(N + 1);

	REP(i, M)
	{
		int a, b, c;
		cin >> a >> b >> c;
		// put data inside johnson
		js.g[a].push_back({ b, c });

		// put data inside warshall floyd
		cost[a-1][b-1] = c;

		// put data inside dijkstra
		g[a].push_back(edge(b, c));
	}

	int start = 6;
	int end = 40;
	js.Compute();
	cout << js.asp[start][end] << endl;
	warshall_floyd(cost);
	cout << cost[start - 1][end - 1] << endl;

	dijkstra(start);
	cout << dist[end] << endl;
	return 0;
}