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

pii targets[1001];
int dp[1001][1001]; // dp[i, j] = max points if starting at i if next jump is to j
int n;
int maxPoints;
int getDis(int a, int b)
{
	return abs(targets[a].first - targets[b].first);
}
void work()
{
	RFOR(i, n - 1, -1)
	{
		FOR(j, i + 1, n)
		{
			dp[i][j] = targets[i].second + targets[j].second;
			FOR(k, j + 1, n)
			{
				if (getDis(j, k) >= getDis(i, j))
				{
					dp[i][j] = max(dp[i][j], targets[i].second + dp[j][k]);
				}
			}
			maxPoints = max(maxPoints, dp[i][j]);
		}
	}
}
int main()
{
	freopen("pogocow.in", "r", stdin);
	freopen("pogocow.out", "w", stdout);
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> targets[i].first;
		cin >> targets[i].second;
	}
	sort(targets, targets + n);
	maxPoints = 0;
	if (n == 1)
	{
		cout << targets[0].second;
		return 0;
	}
	work();
	reverse(targets, targets + n);
	work();
	cout << maxPoints << endl;
}