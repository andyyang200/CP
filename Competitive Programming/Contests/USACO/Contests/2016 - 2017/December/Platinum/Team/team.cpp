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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000009
typedef long long ll;
typedef pair<int, int> pii;

int FJ[1005];
int FP[1005];
ll pSums[1005][1005][11];
ll dp[1005][1005][11];
int main(void)
{
	freopen("team.in", "r", stdin);
	freopen("team.out", "w", stdout);
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	n++;
	m++;
	FOR(i, 1, n)
	{
		scanf("%d", &FJ[i]);
	}
	FOR(j, 1, m)
	{
		scanf("%d", &FP[j]);
	}
	sort(FJ + 1, FJ + n);
	sort(FP + 1, FP + m);
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			if (FJ[i] > FP[j])
			{
				dp[i][j][1] = 1;
			}
			pSums[i][j][1] = pSums[i - 1][j][1] + pSums[i][j - 1][1] - pSums[i - 1][j - 1][1] + M + dp[i][j][1];
			pSums[i][j][1] %= M;
		}
	}
	FOR(x, 2, k + 1)
	{
		FOR(i, 1, n)
		{
			FOR(j, 1, m)
			{
				if (FJ[i] > FP[j])
				{
					dp[i][j][x] = pSums[i - 1][j - 1][x - 1];
				}
				pSums[i][j][x] = pSums[i - 1][j][x] + pSums[i][j - 1][x] - pSums[i - 1][j - 1][x] + M + dp[i][j][x];
				pSums[i][j][x] %= M;
			}
		}
	}
	int ans = 0;
	FOR(i, 1, n)
	{
		FOR(j, 1, m)
		{
			if (FJ[i] > FP[j])
			{
				ans += dp[i][j][k];
				ans %= M;
			}
		}
	}
	cout << ans << endl;
}