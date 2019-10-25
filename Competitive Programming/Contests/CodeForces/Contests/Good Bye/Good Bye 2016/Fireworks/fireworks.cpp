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
int t[31];
int visited[305][305];
int visited2[305][305][8][30];
int n;
pii getNext(int x, int y, int d)
{
	if (d == 0)
	{
		y++;
	}
	if (d == 1)
	{
		x++;
		y++;
	}
	if (d == 2)
	{
		x++;
	}
	if (d == 3)
	{
		x++;
		y--;
	}
	if (d == 4)
	{
		y--;
	}
	if (d == 5)
	{
		x--;
		y--;
	}
	if (d == 6)
	{
		x--;
	}
	if (d == 7)
	{
		x--;
		y++;
	}
	return { x, y };

}
void dfs(int x, int y, int d, int i)
{
	if (i == n)
	{
		return;
	}
	if (visited2[x][y][d][i])
	{
		return;
	}
	visited2[x][y][d][i] = true;
	FOR(j, 0, t[i])
	{
		pii a = getNext(x, y, d);
		x = a.first;
		y = a.second;
		visited[x][y] = true;
	}
	dfs(x, y, (d - 1 + 8) % 8, i + 1);
	dfs(x, y, (d + 1 + 8) % 8, i + 1);
}
int main(void)
{
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &t[i]);
	}
	dfs(151, 151, 0, 0);
	int ans = 0;
	FOR(i, 0, 305)
	{
		FOR(j, 0, 305)
		{
			if (visited[i][j])
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}