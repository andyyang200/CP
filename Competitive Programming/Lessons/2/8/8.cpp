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
int dp[1000][1000]; // dp[i][j] = longest palindrome subsequence in the range [i, j]
// dp(i, j) = max(dp(i + 1, j), dp(i, j - 1), dp(i + 1, j - 1) + 2)
int main(void)
{
	string s;
	cin >> s;
	FOR(i, 0, s.length())
	{
		dp[i][i] = 1;
	}
	FOR(d, 1, s.length())
	{
		FOR(i, 0, s.length())
		{
			int j = i + d;
			if (j >= s.length())
			{
				break;
			}
			dp[i][j] = dp[i + 1][j];
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			if (s[i] == s[j])
			{
				if (i + 1 == j)
				{
					dp[i][j] = max(dp[i][j], 2);
				}
				else
				{
					dp[i][j] = max(dp[i][j], dp[i + 1][j - 1] + 2);
				}
			}
		}
	}
	cout << dp[0][s.length() - 1] << endl;
}