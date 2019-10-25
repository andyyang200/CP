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
int h[100001];
int dp[2][101];
int inline square(int x)
{
	return x * x;
}
int main()
{
	freopen("telewire.in", "r", stdin);
	freopen("telewire.out", "w", stdout);
	int n, c;
	scanf("%d%d", &n, &c);
	int maxH = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &h[i]);
		maxH = max(maxH, h[i]);
	}
	FOR(i, h[0], maxH + 1)
	{
		dp[0][i] = square(i - h[0]);
	}
	FOR(i, 1, n)
	{
		FOR(j, h[i], maxH + 1)
		{
			dp[1][j] = INF;
			FOR(k, h[i - 1], maxH + 1)
			{ 
				dp[1][j] = min(dp[1][j], square(j - h[i]) + dp[0][k] + c * abs(j - k));
			}
		}
		FOR(j, 0, maxH + 1)
		{
			dp[0][j] = dp[1][j];
		}
	}
	int ans = INF;
	FOR(i, h[n - 1], maxH + 1)
	{
		ans = min(ans, dp[0][i]);
	}
	cout << ans << endl;
}