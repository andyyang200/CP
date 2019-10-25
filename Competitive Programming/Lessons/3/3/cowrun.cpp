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
typedef long long ll;
typedef pair<int, int> pii;

int cows[1005];
int dp[1005][1005][2];
int getDis(int a, int b)
{
	return abs(cows[a] - cows[b]);
}
int main()
{
	freopen("cowrun.in", "r", stdin);
	freopen("cowrun.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &cows[i]);
	}
	n++;
	sort(cows, cows + n);
	int start = lower_bound(cows, cows + n, 0) - cows;
	FOR(length, 2, n + 1)
	{
		FOR(l, 0, n)
		{
			int r = l + length - 1;
			int remaining = n - length + 1;
			if (r >= n)
			{
				break;
			}
			if (r < start)
			{
				continue;
			}
			if (l > start)
			{
				break;
			}
			dp[l][r][0] = 1000000000;
			dp[l][r][1] = 1000000000;
			if (l < start)
			{
				dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][0] + remaining * getDis(l, l + 1));
				dp[l][r][0] = min(dp[l][r][0], dp[l + 1][r][1] + remaining * getDis(l, r));
			}
			if (r > start)
			{
				dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][1] + remaining * getDis(r, r - 1));
				dp[l][r][1] = min(dp[l][r][1], dp[l][r - 1][0] + remaining * getDis(l, r));
			}
		}
	}
	cout << min(dp[0][n - 1][0], dp[0][n - 1][1]) << endl;
}