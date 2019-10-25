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

int farm[20][20];
int cost[20][20];
int dp[20][20];
int sums[20];
int main()
{
	freopen("partition.in", "r", stdin);
	freopen("partition.out", "w", stdout);
	int n, K;
	scanf("%d%d", &n, &K);
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			scanf("%d", &farm[i][j]);
		}
	}
	int ans = INF;
	FOR(mask, 0, (1 << (n - 1)))
	{	
		int used = 0;
		FOR(i, 0, n - 1)
		{
			if (mask & (1 << i))
			{
				used++;
			}
		}
		if (used > K)
		{
			continue;
		}
		FOR(l, 0, n)
		{
			memset(sums, 0, sizeof(sums));
			FOR(r, l + 1, n + 1)
			{	
				cost[l][r] = 0;
				int sum = 0;
				for (int j = 0; j < n; ++j) 
				{
					sums[j] += farm[r - 1][j];
					sum += sums[j];
					cost[l][r] = max(cost[l][r], sum);
					if (mask & (1 << j)) 
					{
						sum = 0;
					}
				}
			}
		}
		FOR(i, 0, n + 1)
		{
			FOR(k, 0, n + 1)
			{
				dp[i][k] = INF;
			}
		}
		FOR(i, 0, n + 1)
		{
			dp[i][0] = cost[i][n];
			dp[n][i] = 0;
		}
		for (int k = 1; k < n && k <= (K - used); k++)
		{
			RFOR(l, n - 1, -1)
			{
				FOR(r, l + 1, n + 1)
				{
					dp[l][k] = min(dp[l][k], max(dp[r][k - 1], cost[l][r]));
				}
			}
		}
		for (int k = 0; k < n && k <= (K - used); k++)
		{
			ans = min(ans, dp[0][k]);
		}
	}
	cout << ans << endl;
}