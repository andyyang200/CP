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

int grid[501][501];
vector<pii> waypoints;
bool visited[501][501];
int m, n;

bool valid(int r1, int c1, int r2, int c2, int d)
{
	return r2 >= 0 && r2 < m && c2 >= 0 && c2 < n && !visited[r2][c2] && abs(grid[r1][c1] - grid[r2][c2]) <= d;
}

void bfs(int startR, int startC, int d)
{
	queue<pii> q;
	q.push(pii(startR, startC));
	visited[startR][startC] = true;
	while (!q.empty())
	{
		int r = q.front().first;
		int c = q.front().second;
		q.pop();
		if (valid(r, c, r + 1, c, d))
		{
			q.push(pii(r + 1, c));
			visited[r + 1][c] = true;
		}
		if (valid(r, c, r - 1, c, d))
		{
			q.push(pii(r - 1, c));
			visited[r - 1][c] = true;
		}
		if (valid(r, c, r, c + 1, d))
		{
			q.push(pii(r, c + 1));
			visited[r][c + 1] = true;
		}
		if (valid(r, c, r, c - 1, d))
		{
			q.push(pii(r, c - 1));
			visited[r][c - 1] = true;
		}
	}
}

bool check(int d)
{
	FOR(r, 0, m)
	{
		FOR(c, 0, n)
		{
			visited[r][c] = false;
		}
	}
	bfs(waypoints[0].first, waypoints[0].second, d);
	FOR(j, 1, waypoints.size())
	{
		if (!visited[waypoints[j].first][waypoints[j].second])
		{
			return false;
		}
	}
}

int main()
{
	freopen("ccski.in", "r", stdin);
	freopen("ccski.out", "w", stdout);
	cin >> m >> n;
	FOR(r, 0, m)
	{
		FOR(c, 0, n)
		{
			cin >> grid[r][c];
		}
	}
	FOR(r, 0, m) FOR(c, 0, n)
	{
		int isWaypoint;
		cin >> isWaypoint;
		if (isWaypoint)
		{
			waypoints.push_back(pii(r, c));
		}
	}

	int low = 0, high = 1000000000;
	int d = 0;
	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (check(mid))
		{
			d = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	cout << d << endl;
}