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
int coins[17];
int purchases[100001];
int p[100001];
int dp[(1 << 16) + 1];
int main()
{
	freopen("nochange.in", "r", stdin);
	freopen("nochange.out", "w", stdout);
	int k, n;
	scanf("%d%d", &k, &n);
	int totalCoins = 0;
	FOR(i, 0, k)
	{
		scanf("%d", &coins[i]);
		totalCoins += coins[i];
	}
	FOR(i, 0, n)
	{
		scanf("%d", &purchases[i]);
		p[i] = (i == 0 ? 0 : p[i - 1]) + purchases[i];
	}
	int ans = -1;
	memset(dp, -1, sizeof(dp));
	FOR(mask, 0, 1 << k)
	{
		int sum = 0;
		FOR(i, 0, k)
		{
			if (!(mask & (1 << i)))
			{
				sum += coins[i];
				int l = dp[mask];
				int r = n - 1;
				int best = -1;
				while (l <= r)
				{
					int m = (l + r) / 2;
					if (p[m] - (dp[mask] < 0 ? 0 : p[dp[mask]]) <= coins[i])
					{
						best = m;
						l = m + 1;
					}
					else
					{
						r = m - 1;
					}
				}
				dp[mask | (1 << i)] = max(dp[mask | (1 << i)], best);
			}
		}
		if (dp[mask] == n - 1)
		{
			ans = max(ans, sum);
		}
	}
	cout << ans << endl;
}