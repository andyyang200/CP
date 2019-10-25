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
pii a[101];
int dp[55005];
int main()
{
	freopen("buyhay.in", "r", stdin);
	freopen("buyhay.out", "w", stdout);
	int n, h;
	scanf("%d%d", &n, &h);
	FOR(i, 0, n)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	FOR(i, 1, h + 5001)
	{
		dp[i] = INF;
	}
	FOR(i, 0, n)
	{
		FOR(j, a[i].first, h + 5001)
		{
			dp[j] = min(dp[j], dp[j - a[i].first] + a[i].second);
		}
	}
	int ans = INF;
	FOR(i, h, h + 5001)
	{
		if (dp[i] != 0)
		{
			ans = min(ans, dp[i]);
		}
	}
	cout << ans << endl;
}