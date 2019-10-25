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
typedef pair<int, int> pii;
int n, m;
int grid[1001][1001];
int north[1001][1001]; // new row number
int south[1001][1001]; // new row number
int east[1001][1001]; // new col number
int west[1001][1001]; // new col number
int d[2005000];
vector<pii> edges[2005000]; // new node, weight
int getKey(int r, int c, int smell)
{
	return 2 * m * r + 2 * c + smell;
}
bool inBounds(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m;
}
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, -1, 0, 1 };
int main()
{
	freopen("dream.in", "r", stdin);
	freopen("dream.out", "w", stdout);
	scanf("%d%d", &n, &m);
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			scanf("%d", &grid[r][c]);
			north[r][c] = -1;
			south[r][c] = -1;
			east[r][c] = -1;
			west[r][c] = -1;
		}
	}
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			if (grid[r][c] == 4)
			{
				if (inBounds(r - 1, c) && grid[r - 1][c] == 4)
				{
					south[r][c] = south[r - 1][c];
				}
				else
				{
					FOR(k, r, n + 1)
					{
						if (k == n || grid[k][c] == 0 || grid[k][c] == 3)
						{
							south[r][c] = k - 1;
							break;
						}
						if (grid[k][c] == 1 || grid[k][c] == 2)
						{
							south[r][c] = k;
							break;
						}
					}
				}
				if (inBounds(r, c - 1) && grid[r][c - 1] == 4)
				{
					east[r][c] = east[r][c - 1];
				}
				else
				{
					FOR(k, c, m + 1)
					{
						if (k == m || grid[r][k] == 0 || grid[r][k] == 3)
						{
							east[r][c] = k - 1;
							break;
						}
						if (grid[r][k] == 1 || grid[r][k] == 2)
						{
							east[r][c] = k;
							break;
						}
					}
				}
			}
		}
	}
	RFOR(r, n - 1, -1)
	{
		RFOR(c, m - 1, -1)
		{
			if (grid[r][c] == 4)
			{
				if (inBounds(r + 1, c) && grid[r + 1][c] == 4)
				{
					north[r][c] = north[r + 1][c];
				}
				else
				{
					RFOR(k, r, -2)
					{
						if (k == -1 || grid[k][c] == 0 || grid[k][c] == 3)
						{
							north[r][c] = k + 1;
							break;
						}
						if (grid[k][c] == 1 || grid[k][c] == 2)
						{
							north[r][c] = k;
							break;
						}
					}
				}
				if (inBounds(r, c + 1) && grid[r][c + 1] == 4)
				{
					west[r][c] = west[r][c + 1];
				}
				else
				{
					RFOR(k, c, -2)
					{
						if (k == -1 || grid[r][k] == 0 || grid[r][k] == 3)
						{
							west[r][c] = k + 1;
							break;
						}
						if (grid[r][k] == 1 || grid[r][k] == 2)
						{
							west[r][c] = k;
							break;
						}
					}
				}
			}
		}
	}
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			FOR(s, 0, 2)
			{
				FOR(i, 0, 4)
				{
					int nr = r + dx[i];
					int nc = c + dy[i];
					if (!inBounds(nr, nc) || grid[nr][nc] == 0)
					{
						continue;
					}
					else if (grid[nr][nc] == 1)
					{
						edges[getKey(r, c, s)].push_back(pii(getKey(nr, nc, s), 1));
					}
					else if (grid[nr][nc] == 2)
					{
						edges[getKey(r, c, s)].push_back(pii(getKey(nr, nc, 1), 1));
					}
					else if (grid[nr][nc] == 3)
					{
						if (s == 1)
						{
							edges[getKey(r, c, 1)].push_back(pii(getKey(nr, nc, 1), 1));						
						}
					}
					else
					{
						if (nr < r)
						{
							int finalr = north[nr][nc];
							edges[getKey(r, c, s)].push_back(pii(getKey(finalr, nc, 0), r - finalr));
						}
						else if (nr > r)
						{
							int finalr = south[nr][nc];
							edges[getKey(r, c, s)].push_back(pii(getKey(finalr, nc, 0), finalr - r));
						}
						else if (nc < c)
						{
							int finalc = west[nr][nc];
							edges[getKey(r, c, s)].push_back(pii(getKey(nr, finalc, 0), c - finalc));
						}
						else if (nc > c)
						{
							int finalc = east[nr][nc];
							edges[getKey(r, c, s)].push_back(pii(getKey(nr, finalc, 0), finalc - c));
						}
					}
				}
			}
		}
	}
	FOR(i, 0, getKey(n - 1, m - 1, 1) + 1)
	{
		d[i] = INF;
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
		for (pii edge : edges[node])
		{
			if (d[node] + edge.second < d[edge.first])
			{
				d[edge.first] = d[node] + edge.second;
				nodes.push(pii(d[edge.first], edge.first));
			}
		}
	}
	int ans = min(d[getKey(n - 1, m - 1, 0)], d[getKey(n - 1, m - 1, 1)]);
	if (ans == INF)
	{
		ans = -1;
	}
	cout << ans << endl;
}