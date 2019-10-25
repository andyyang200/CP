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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int n, m;
vector<int> edges[3001];
int d[3001][3001];
void bfs(int source)
{
	FOR(i, 0, n)
	{
		d[source][i] = INF;
	}
	queue<int> q;
	q.push(source);
	d[source][source] = 0;
	while (!q.empty())
	{
		int node = q.front();
		q.pop();
		for (int nxt : edges[node])
		{
			if (d[source][nxt] == INF)
			{
				d[source][nxt] = d[source][node] + 1;
				q.push(nxt);
			}
		}
	}
}
int dp[3001][5];
int path[3001][5];
int bestPath[4];
int newPath[4];
int main(void)
{
	cin >> n >> m;
	FOR(i, 0, m)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		edges[u].push_back(v);
	}
	FOR(i, 0, n)
	{
		bfs(i);
	}
	FOR(i, 0, n)
	{
		FOR(j, 1, 4)
		{
			dp[i][j] = -1;
			FOR(k, 0, n)
			{
				bool bad = false;
				if (k == i || d[i][k] == INF || dp[k][j - 1]== -1)
				{
					bad = true;
				}
				if (d[i][k] + dp[k][j - 1] > dp[i][j])
				{
					dp[i][j] = d[i][k] + dp[k][j - 1];
					path[i][j] = k;
				}
			}
		}
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		if (dp[i][3] > ans)
		{
			newPath[0] = i;
			int j = i;
			FOR(k, 0, 3)
			{
				j = path[j][3 - k];
				newPath[k + 1] = j;
			}
			bool repeat = false;
			FOR(k, 0, 4)
			{
				FOR(f, k + 1, 4)
				{
					if (newPath[k] == newPath[f])
					{
						repeat = true;
					}
				}
			}
			if (!repeat)
			{
				ans = dp[i][3];
				FOR(k, 0, 4)
				{
					bestPath[k] = newPath[k];
				}
			}
		}
	}
	FOR(i, 0, 4)
	{
		cout << bestPath[i] + 1 << " ";
	}
	cout << endl;
}