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
int n;
char grid[51][51];
char ans[100][100];
int main()
{
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			cin >> grid[i][j];
		}
	}
	set<pii> moves;
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			moves.insert({ i, j });
			moves.insert({ -i, j });
			moves.insert({ i, -j });
			moves.insert({ -i, -j });
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (grid[i][j] != 'o')
			{
				continue;
			}
			FOR(r, 0, n)
			{
				FOR(c, 0, n)
				{
					if (grid[r][c] == '.')
					{
						auto itr = moves.find({ r - i, c - j });
						if (itr != moves.end())
						{
							moves.erase(itr);
						}
					}
				}
			}
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (grid[i][j] != 'o')
			{
				continue;
			}
			FOREACH(itr, moves)
			{
				int nextR = i + itr->first;
				int nextC = j + itr->second;
				if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < n && grid[nextR][nextC] == 'x')
				{
					grid[nextR][nextC] = '.';
				}
			}
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			if (grid[i][j] == 'x')
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	FOR(i, 0, 2 * n - 1)
	{
		FOR(j, 0, 2 * n - 1)
		{
			ans[i][j] = '.';
		}
	}
	ans[n - 1][n - 1] = 'o';
	FOREACH(itr, moves)
	{
		ans[n - 1 + itr->first][n - 1 + itr->second] = 'x';
	}
	FOR(i, 0, 2 * n - 1)
	{
		FOR(j, 0, 2 * n - 1)
		{
			cout << ans[i][j];
		}
		cout << endl;
	}
}