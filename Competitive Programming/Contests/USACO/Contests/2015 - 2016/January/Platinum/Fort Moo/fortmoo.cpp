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
char grid[201][201];
int phorizontal[201][201];
int pvertical[201][201];
bool checkRow(int r, int c1, int c2)
{
	return phorizontal[r][c2] - (c1 == 0 ? 0 : phorizontal[r][c1 - 1]);
}		
bool checkCol(int r1, int r2, int c)
{
	return pvertical[r2][c] - (r1 == 0 ? 0 : pvertical[r1 - 1][c]);
}
int main()
{
	freopen("fortmoo.in", "r", stdin);
	freopen("fortmoo.out", "w", stdout);	
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> grid[i][j];
			if (i == 0)
			{
				pvertical[i][j] = (grid[i][j] == 'X');
			}
			else
			{
				pvertical[i][j] = pvertical[i - 1][j] + (grid[i][j] == 'X');
			}
			if (j == 0)
			{
				phorizontal[i][j] = (grid[i][j] == 'X');
			}
			else
			{
				phorizontal[i][j] = phorizontal[i][j - 1] + (grid[i][j] == 'X');
			}
		}
	}
	int ans = 0;
	FOR(r1, 0, n)
	{
		FOR(c1, 0, m)
		{
			if (grid[r1][c1] == 'X')
			{
				continue;
			}
			FOR(r2, r1, n)
			{
				if (grid[r2][c1] == 'X')
				{
					break;
				}
				int farthest = -1;
				int l = c1;
				int r = m - 1;
				while (l <= r)
				{
					int mid = (l + r) / 2;
					if (!checkRow(r1, c1, mid) && !checkRow(r2, c1, mid))
					{
						farthest = mid;
						l = mid + 1;
					}
					else
					{
						r = mid - 1;
					} 
				}
				if (farthest == -1)
				{
					continue;
				}
				RFOR(c2, farthest, c1 - 1)
				{	
					int area = (c2 - c1 + 1) * (r2 - r1 + 1);
					if (area <= ans)
					{
						break;
					}
					if (!checkCol(r1, r2, c2))
					{
						ans = max(area, ans);
						break;	
					}
				}
			}
		}
	}
	cout << ans << endl;
}