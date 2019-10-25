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
int c[501];
int dp[501][501];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &c[i]);
		dp[i][i] = 1;
	}
	FOR(k, 1, n)
	{
		FOR(i, 0, n)
		{
			if (i + k >= n)
			{
				break;
			}
			int j = i + k;
			dp[i][j] = INF;
			FOR(x, i, j)
			{
				dp[i][j] = min(dp[i][j], dp[i][x] + dp[x + 1][j]);
			}
			if (c[i] == c[j])
			{
				if (j == i + 1)
				{
					dp[i][j] = 1;
				}
				else
				{
					dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
				}
			}
		}
	}
	cout << dp[0][n - 1] << endl;
}