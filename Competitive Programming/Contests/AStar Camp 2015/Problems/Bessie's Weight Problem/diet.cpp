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
int bales[501];
int dp[3][45001];
int main()
{
	freopen("diet.in", "r", stdin);
	freopen("diet.out", "w", stdout);
	int W, n;
	scanf("%d%d", &W, &n);
	FOR(i, 0, n)
	{
		scanf("%d", &bales[i]);
	}
	int ans = 0;
	for (int i = 0; i <= n; i++)
	{
		for (int w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				dp[1][w] = 0;
			else if (bales[i - 1] <= w)
				dp[1][w] = max(bales[i - 1] + dp[0][w - bales[i - 1]], dp[0][w]);
			else
				dp[1][w] = dp[0][w];
			dp[0][w] = dp[1][w];
		}
	}
	cout << dp[1][W] << endl;
}