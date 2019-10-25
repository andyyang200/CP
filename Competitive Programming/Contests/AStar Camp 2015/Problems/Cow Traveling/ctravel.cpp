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
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
char grid[105][105];
int dp[105][105][20];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0};
int main()
{
	freopen("ctravel.in", "r", stdin);
	freopen("ctravel.out", "w", stdout);
	int n, m, t;
	scanf("%d%d%d", &n, &m, &t);
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> grid[i][j];
		}
	}
	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	r1--;
	r2--;
	c1--;
	c2--;
	dp[r1][c1][0] = 1;
	FOR(i, 1, t + 1)
	{
		FOR(r, 0, n)
		{
			FOR(c, 0, m)
			{
				if (grid[r][c] != '*')
				{
					FOR(j, 0, 4)
					{
						int nextR = r + dx[j];
						int nextC = c + dy[j];
						if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && grid[nextR][nextC] != '*')
						{
							dp[r][c][i] += dp[nextR][nextC][i - 1];
						}
					}
				}
			}
		}
	}
	cout << dp[r2][c2][t] << endl;
}