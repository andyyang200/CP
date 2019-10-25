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
int rooms[1000];
int n, k;
ll dp[1000][1000][7];
ll cost[1000];
int main()
{
	freopen("cbarn2.in", "r", stdin);
	freopen("cbarn2.out", "w", stdout);
	scanf("%d%d", &n, &k);
	ll sum = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &rooms[i]);
	}
	FOR(d, 1, n)
	{
		FOR(l, 0, n)
		{
			int r = (l + d) % n;
			FOR(i, 0, k)
			{
				if (i >= d)
				{
					continue;
				}
				dp[l][r][i] = -1;
				ll cost = 0;
				int pos = 1;
				int limit = (r + 1) % n;
				for (int j = (l + 1) % n; j != limit; j = (j + 1) % n)
				{
					if (i > 0)
					{
						ll x = cost + dp[j][r][i - 1];
						if (dp[l][r][i] == -1 || x < dp[l][r][i])
						{
							dp[l][r][i] = x;
						}
					}
					cost += (ll)pos * rooms[j];
					pos++;
				}
				if (i == 0)
				{
					dp[l][r][i] = cost;
				}
			}
		}
	}
	ll ans = -1;
	FOR(i, 0, n)
	{
		ll x = dp[i][(i + n - 1) % n][k - 1];
		if (ans == -1 || x < ans)
		{
			ans = x;
		}
	}
	cout << ans << endl;
}