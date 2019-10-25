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
#define INF 2000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
pii ha[1001];
pii ga[1001];
int dp[1001][1001][2];
int dis(pii a, pii b)
{
	return abs(a.first - b.first) * abs(a.first - b.first) + abs(a.second - b.second) * abs(a.second - b.second);
}
int main(void)
{
	freopen("checklist.in", "r", stdin);
	freopen("checklist.out", "w", stdout);
	int h, g;
	scanf("%d%d", &h, &g);
	FOR(i, 1, h + 1)
	{
		scanf("%d%d", &ha[i].first, &ha[i].second);
	}
	FOR(i, 1, g + 1)
	{
		scanf("%d%d", &ga[i].first, &ga[i].second);
	}
	FOR(i, 0, h + 1)
	{
		FOR(j, 0, g + 1)
		{
			FOR(k, 0, 2)
			{
				dp[i][j][k] = INF;
			}
		}
	}
	dp[1][0][0] = 0;
	FOR(i, 1, h + 1)
	{
		FOR(j, 0, g + 1)
		{
			dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][0] + dis(ha[i - 1], ha[i]));
			dp[i][j][0] = min(dp[i][j][0], dp[i - 1][j][1] + dis(ga[j], ha[i]));
			if (j > 0)
			{
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][0] + dis(ha[i], ga[j]));
				dp[i][j][1] = min(dp[i][j][1], dp[i][j - 1][1] + dis(ga[j - 1], ga[j]));
			}
		}
	}
	cout << dp[h][g][0] << endl;
}