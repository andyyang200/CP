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
char grid[3][100];
int n, k;
bool visited[3][100];
bool yes;
void dfs(int row, int time)
{
	if (3 * time >= n)
	{
		yes = true;
		return;
	}
	if (yes)
	{
		return;
	}
	if (visited[row][time])
	{
		return;
	}
	if (time > 0 && 3 * time < n && grid[row][3 * time] != '.')
	{
		return;
	}
	visited[row][time] = true;
	FOR(i, row - 1, row + 2)
	{
		if (i >= 0 && i <= 2 )
		{
			if (3 * time + 1 >= n || (grid[row][3 * time + 1] == '.' && grid[i][3 * time + 1] == '.'))
			dfs(i, time + 1);
		}
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	FOR(sets, 0, t)
	{
		scanf("%d%d", &n, &k);
		int startRow = -1;
		FOR(i, 0, 3)
		{
			FOR(j, 0, n)
			{
				cin >> grid[i][j];
				if (grid[i][j] == 's')
				{
					startRow = i;
				}
			}
			FOR(j, 0, 100)
			{
				visited[i][j] = false;
			}
		}
		yes = false;
		dfs(startRow, 0);
		if (yes)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
}