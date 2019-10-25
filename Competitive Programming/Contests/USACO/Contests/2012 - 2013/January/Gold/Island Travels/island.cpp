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
int island[51][51];
char grid[51][51];
bool visited[51][51];
pii location[20];
int R, C, N;
int nextR[] = { 1, 0, -1, 0 };
int nextC[] = { 0, 1, 0, -1 };
int dis[20][20];
int d[51][51];
void fill(int i, int r, int c)
{
	if (r < 0 || r >= R || c < 0 || c >= C)
	{
		return;
	}
	if (island[r][c] != -1)
	{
		return;
	}
	if (grid[r][c] != 'X')
	{
		return;
	}
	island[r][c] = i;
	location[i] = { r, c };
	FOR(j, 0, 4)
	{
		fill(i, r + nextR[j], c + nextC[j]);
	}
}
void bfs(int i)
{
	queue<pii> q;
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			visited[r][c] = 0;
			d[r][c] = 0;
		}	
	}
	visited[location[i].first][location[i].second] = 1;
	q.push(location[i]);
	while (!q.empty())
	{
		pii current = q.front();
		q.pop();
		FOR(j, 0, 4)
		{
			int nr = current.first + nextR[j];
			int nc = current.first + nextC[j];
			if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc] || grid[nr][nc] == '.')
			{
				continue;
			}
			d[nr][nc] = d[current.first][current.second] + (grid[nr][nc] == 'S' ? 1 : 0);
			visited[nr][nc] = 1;
			q.push({ nr, nc });
		}
	}
	FOR(j, 0, N)
	{
		dis[i][j] = d[location[j].first][location[j].second];
	}
}
int main()
{
	//freopen("island.in", "r", stdin);
	//freopen("island.out", "w", stdout);
	scanf("%d%d", &R, &C);
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			cin >> grid[r][c];
			island[r][c] = -1;
		}
	}
	N = 0;
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			if (grid[r][c] == 'X' && island[r][c] == -1)
			{
				fill(N, r, c);
				N++;
			}
		}
	}
	FOR(i, 0, N)
	{
		bfs(i);
	}
	int a = 5;
}	