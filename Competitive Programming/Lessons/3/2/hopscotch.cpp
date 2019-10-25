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
int a[101][101];
int dp[101][101]; // dp[i][j] = number of ways to jump to a[i][j]
int main(void)
{
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	int r, c, k;
	scanf("%d%d%d", &r, &c, &k);
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			scanf("%d", &a[i][j]);
		}
	}
	dp[0][0] = 1;
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			FOR(i2, 0, i)
			{
				FOR(j2, 0, j)
				{
					if (i2 == i && j2 == j)
					{
						continue;
					}
					if (a[i2][j2] != a[i][j])
					{
						dp[i][j] += dp[i2][j2];
						dp[i][j] %= M;
					}
				}
			}
		}
	}
	cout << dp[r - 1][c - 1] << endl;
}