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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend(); itr++)
typedef long long ll;
typedef pair<int, int> pii;

pii points[501];
int dp[501][501]; // [x][y] min distance to point x skipping up to y checkpoints

int getDistance(int a, int b)
{
	return abs(points[a].first - points[b].first) + abs(points[a].second - points[b].second);
}

int main()
{
	//freopen("marathon.in", "r", stdin);
	//freopen("marathon.out", "w", stdout);

	int n, k;
	cin >> n >> k;
	FOR(i, 0, n)
	{
		int x, y;
		cin >> x >> y;
		points[i] = pii(x, y);
	}
	FOR(i, 1, n)
	{
		dp[i][0] = dp[i - 1][0] + getDistance(i - 1, i);
	}
	FOR(x, 1, n)
	{
		FOR(y, 1, k + 1)
		{
			int minimum = 1000000000;
			FOR(k, 1, x)
			{
				minimum = min(minimum, dp[k][y - 1] + getDistance(k, x));
			}
			dp[x][y] = minimum;
		}
	}
	cout << dp[n - 1][k] << endl;
}