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
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

pii targets[1001];
int dp[1001][1001]; // [i, j] max points if next jump is from i to j
int n;

int main()
{
	freopen("pogocow.in", "r", stdin);
	freopen("pogocow.out", "w", stdout);
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> targets[i].first;
		cin >> targets[i].second;
		dp[i][i] = targets[i].second;
	}
	sort(targets, targets + n);
	int maxPoints = 0;
	if (n == 1)
	{
		cout << targets[0].second;
		return 0;
	}
	RFOR(i, n - 1, -1)
	{
		FOR(j, i + 1, n)
		{
			dp[i][j] = targets[i].second + targets[j].second;
			FOR(k, j + 1, n)
			{
				if (targets[k].first - targets[j].first >= targets[j].first - targets[i].first)
				{
					dp[i][j] = max(dp[i][j], targets[i].second + dp[j][k]);
				}
			}
			maxPoints = max(maxPoints, dp[i][j]);
		}
	}
	FOR(i, 0, n)
	{
		RFOR(j, i - 1, -1)
		{
			dp[i][j] = targets[i].second + targets[j].second;
			RFOR(k, j - 1, -1)
			{
				if (targets[j].first - targets[k].first >= targets[i].first - targets[j].first)
				{
					dp[i][j] = max(dp[i][j], targets[i].second + dp[j][k]);
				}
			}
			maxPoints = max(maxPoints, dp[i][j]);
		}
	}
	cout << maxPoints << endl;
}