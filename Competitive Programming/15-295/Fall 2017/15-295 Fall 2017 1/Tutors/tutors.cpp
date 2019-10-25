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
int x[1000];
int y[1000];
int x2[1000];
int y2[1000];
int dist(int a, int b) { // student, tutor
	return abs(x[a] - x2[b]) + abs(y[a] - y2[b]);
}

int p[205];
int res[205][205]; // initialize
ll mf, f;
int s, t; // initialize
int n; // initialize
void augment(int v, int minEdge)
{
	if (v == s)
	{
		f = minEdge;
		return;
	}
	else if (p[v] != -1)
	{
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
int maxflow()
{
	mf = 0;
	while (true)
	{
		f = 0;
		int dist[100];
		FOR(i, 0, 2 * n + 2)
		{
			dist[i] = 1000000000;
		}
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int u = q.front();
			q.pop();
			if (u == t)
			{
				break;
			}
			for (int v = 0; v < 2 * n + 2; v++)
			{
				if (res[u][v] > 0 && dist[v] == 1000000000)
				{
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, 1000000000);
		if (f == 0)
		{
			break;
		}
		mf += f;
	}
	return mf;
}
bool check(int k) {
	s = 2 * n;
	t = 2 * n + 1;
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			if (dist(i, j) <= k) {
				res[i][j + n] = 1;
			}
			else {
				res[i][j + n] = 0;
			}
		}
		res[2 * n][i] = 1;
		res[i + n][2 * n + 1] = 1;
	}
	return maxflow() >= n;
}
int main(void)
{
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d%d", &x[i], &y[i]);
	}
	FOR(i, 0, n) {
		scanf("%d%d", &x2[i], &y2[i]);
	}
	int l = 0;
	int r = INF;
	int ans = -1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid - 1;
			ans = mid;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
}
/*
2 
0 0
0 3
0 2
0 5
*/
/*
4 
0 1
0 2
0 3
0 4
1 0
1 1
1 2
1 3
*/

/*
3
0 5
5 2
4 5
3 3
5 2
5 2
*/

/*
2
0 0
0 5
-1 4
8 3
*/