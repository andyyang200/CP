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
int dis[10001];
int dp[10005][505];
int main()
{
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 1, n + 1)
	{
		scanf("%d", &dis[i]);
	}
	RFOR(i, n, 0) // minutes
	{
		RFOR(j, m, -1) // exhaustion
		{
			dp[i][j] = 0;
			if (i + j <= n + 1)
			{
				dp[i][j] = max(dp[i][j], dp[i + j][0]);
			}
			else
			{
				continue;
			}
			if (i + 1 <= n && j == 0)
			{
				dp[i][j] = max(dp[i][j], dp[i + 1][j]);
			}
			if (i + 1 <= n && j + 1 <= m && i + j + 2 <= n + 1)
			{
				dp[i][j] = max(dp[i][j], dis[i] + dp[i + 1][j + 1]);
			}
		}
	}
	cout << dp[1][0] << endl;
}