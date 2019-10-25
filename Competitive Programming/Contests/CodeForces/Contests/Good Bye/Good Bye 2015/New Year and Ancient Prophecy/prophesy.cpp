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
ll dp[5001][5001];
ll p[5001][5001];
int first[5001][5001];
int main()
{
	int n;
	scanf("%d", &n);
	string s;
	cin >> s;
	RFOR(a, n - 1, -1)
	{
		RFOR(b, n - 1, a)
		{
			if (s[a] != s[b] || b == n - 1)
			{
				first[a][b] = 0;
			}
			else
			{
				first[a][b] = 1 + first[a + 1][b + 1];
			}
			if (a + first[a][b] >= b)
			{
				first[a][b] = 0;
			}
		}
	}
	FOR(c, 0, n)
	{
		RFOR(b, c, -1)
		{
			if (s[b] == '0')
			{
				dp[b][c] = 0;
			}
			else if (b == 0)
			{
				dp[b][c] = 1;
			}
			else
			{
				int a = (b - 1) - (c - b);
				int l = max(a + 1, 0);
				dp[b][c] += p[l][b - 1];
				int length = c - b + 1;
				if (a >= 0 && s[a + first[a][b]] < s[b + first[a][b]])
				{
					dp[b][c] += dp[a][b - 1];
				}
			}
			dp[b][c] %= M;
			p[b][c] = dp[b][c] + (b == c ? 0 : p[b + 1][c]);
			p[b][c] %= M;
		}
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		ans += dp[i][n - 1];
		ans %= M;
	}
	cout << ans << endl;
}