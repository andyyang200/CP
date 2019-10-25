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
int a[100001];
int dp[100001][21][4];
int main(void)
{
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		char c;
		cin >> c;
		if (c == 'H')
		{
			a[i] = 1;
		}
		else if (c == 'P')
		{
			a[i] = 2;
		}
		else
		{
			a[i] = 3;
		}
	}
	FOR(x, 1, 4)
	{
		FOR(j, 0, k + 1)
		{
			dp[0][j][x] = (a[0] == x ? 1 : 0);
		}
	}
	FOR(i, 1, n)
	{
		FOR(j, 0, k + 1)
		{
			FOR(x, 1, 4)
			{
				dp[i][j][x] = dp[i - 1][j][x] + (a[i] == x ? 1 : 0);
				if (j > 0)
				{
					FOR(y, 1, 4)
					{
						if (y == x)
						{
							continue;
						}
						dp[i][j][x] = max(dp[i][j][x], dp[i - 1][j - 1][y] + (a[i] == x ? 1 : 0));
					}
				}
			}
		}
	}
	int ans = dp[n - 1][k][1];
	ans = max(ans, dp[n - 1][k][2]);
	ans = max(ans, dp[n - 1][k][3]);
	cout << ans << endl;
}