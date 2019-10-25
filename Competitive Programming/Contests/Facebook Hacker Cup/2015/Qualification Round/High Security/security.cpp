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
char grid[2][1001];
int n;
bool valid(int r, int c)
{
	return r >= 0 && r < 2 && c >= 0 && c < n && grid[r][c] != 'X';
}
int main()
{
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{
		scanf("%d", &n);
		FOR(i, 0, 2)
		{
			FOR(j, 0, n)
			{
				cin >> grid[i][j];
			}
		}
		int ans = 0;
		FOR(i, 0, n) // top row
		{
			if (!valid(0, i - 1) && !valid(0, i + 1) && valid(0, i))
			{
				if (grid[1][i] != 'X')
				{
					FOR(j, i + 1, n)
					{
						if (grid[1][j] == 'X')
						{
							break;
						}
						grid[1][j] = 'X';
					}
					RFOR(j, i - 1, -1)
					{
						if (grid[1][j] == 'X')
						{
							break;
						}
						grid[1][j] = 'X';
					}
					grid[1][i] = 'X';
				}
				grid[0][i] = 'X';
				ans++;
			}
		}
		FOR(i, 0, n) // bottom row
		{
			if (!valid(1, i - 1) && !valid(1, i + 1) && valid(1, i))
			{
				if (grid[0][i] != 'X')
				{
					FOR(j, i + 1, n)
					{
						if (grid[0][j] == 'X')
						{
							break;
						}
						grid[0][j] = 'X';
					}
					RFOR(j, i - 1, -1)
					{
						if (grid[0][j] == 'X')
						{
							break;
						}
						grid[0][j] = 'X';
					}
					grid[0][i] = 'X';
				}
				grid[1][i] = 'X';
				ans++;
			}
		}
		FOR(i, 0, 2)
		{
			FOR(j, 0, n)
			{
				if (grid[i][j] == '.')
				{
					ans++;
					FOR(k, j, n)
					{
						if (grid[i][k] == 'X')
						{
							break;
						}
						grid[i][k] = 'X';
					}
				}
			}
		}
		printf("Case #%d: %d\n", set + 1, ans);
	}
}