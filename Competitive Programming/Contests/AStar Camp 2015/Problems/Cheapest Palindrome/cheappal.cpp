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
#define FOREACH(itr, b) for(auto	 itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int cost[200];
int dp[2005][2005];
int main()
{
	freopen("cheappal.in", "r", stdin);
	freopen("cheappal.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	string s;
	cin >> s;
	FOR(i, 0, n)
	{
		char c;
		int a, b;
		cin >> c >> a >> b;
		cost[c] = min(a, b);
	}
	FOR(d, 1, m)
	{
		FOR(l, 0, m)
		{
			int r = l + d;
			if (r >= m)
			{
				break;
			}
			dp[l][r] = INF;
			dp[l][r] = min(dp[l][r], dp[l + 1][r] + cost[s[l]]);
			dp[l][r] = min(dp[l][r], dp[l][r - 1] + cost[s[r]]);
			if (s[l] == s[r])
			{
				dp[l][r] = min(dp[l][r], dp[l + 1][r - 1]);
			}
		}
	}
	cout << dp[0][m - 1] << endl;
}