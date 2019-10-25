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

int dp[1001][1001];
int open[1001];
int main()
{
	freopen("bbreeds.in", "r", stdin);
	freopen("bbreeds.out", "w", stdout);
	string s;
	cin >> s;
	int n = s.length();
	open[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		open[i] = open[i - 1] + (s[i - 1] == '(' ? 1 : -1);
	}
	dp[n][0] = 1;
	RFOR(i, n - 1, -1)
	{
		FOR(j, 0, open[i] + 1)
		{
			if (s[i] == '(')
			{
				dp[i][j] = dp[i + 1][j] + dp[i + 1][j + 1];
			}
			else
			{
				if (j > 0)
				{
					dp[i][j] += dp[i + 1][j - 1];
				}
				if (j < open[i])
				{
					dp[i][j] += dp[i + 1][j];
				}
			}
			dp[i][j] %= 2012;
		}
	}
	cout << dp[0][0] << endl;
}