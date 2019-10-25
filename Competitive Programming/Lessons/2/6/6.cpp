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
int grid[1001][1001];
int dp[1001][1001]; // dp[i][j] = largest square with top-left point at (i, j)
int main(void)
{
	int r, c;
	cin >> r >> c;
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	RFOR(i, r - 1, -1)
	{
		RFOR(j, c - 1, -1)
		{
			if (grid[i][j] == '#')
			{
				dp[i][j] = 0;
			}
			dp[i][j] = INF;
			dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1);
			dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1);
			dp[i][j] = min(dp[i][j], dp[i + 1][j + 1] + 1);
			ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;
}