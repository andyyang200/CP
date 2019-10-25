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
typedef long long ll;
typedef pair<int, int> pii;

int cows[20][20];
map<int, vector<pii>> bonuses;
int dp[2 << 20];
int main()
{
	freopen("dec.in", "r", stdin);
	freopen("dec.out", "w", stdout);
	int n, b;
	scanf("%d%d", &n, &b);
	FOR(i, 0, b)
	{
		int k, p, a;
		scanf("%d%d%d", &k, &p, &a);
		bonuses[k].push_back({ p, a });
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			scanf("%d", &cows[i][j]);
		}
	}
	FOREACH(itr, bonuses)
	{
		sort(itr->second.begin(), itr->second.end());
	}
	FOR(i, 1, 2 << n)
	{
		int numCows = 0;
		FOR(j, 0, n)
		{
			if (i & (1 << j))
			{
				numCows++;
			}
		}
		FOR(j, 0, n)
		{
			if (i & (1 << j))
			{
				dp[i] = max(dp[i], dp[i & ~(1 << j)] + cows[j][numCows - 1]);
			}
		}
		for (pii p : bonuses[numCows])
		{
			if (dp[i] >= p.first)
			{
				dp[i] += p.second;
			}
			else
			{
				break;
			}
		}
	}
	cout << dp[(2 << n) - 1] << endl;
}