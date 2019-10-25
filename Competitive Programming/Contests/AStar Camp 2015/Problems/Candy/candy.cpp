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


int options[51];
int dp[40001];
bool isFavorite[40001];
int checked[40001];
int main() 
{
	freopen("candy.in", "r", stdin);
	freopen("candy.out", "w", stdout);
	int n, nopt, f, m;
	scanf("%d%d%d%d", &n, &nopt, &f, &m);	
	FOR(i, 0, nopt)
	{
		scanf("%d", &options[i]);
	}
	FOR(i, 0, f)
	{
		int x;
		scanf("%d", &x);
		isFavorite[x] = true;
	}
	isFavorite[n] = 0;
	memset(dp, -1, sizeof(dp));
	dp[n] = 0;
	RFOR (i, n, 0) 
	{
		if (dp[i] == -1)
		{
			continue;
		}
		if (checked[i] > f + 1) 
		{
			cout << -1 << endl;
			return 0;
		}
		checked[i]++;
		if (isFavorite[i]) 
		{
			if (dp[i] > dp[i + m]) 
			{
				dp[i + m] = dp[i];	
				i += m + 1;
			}
			continue;
		}
		for (int j = 0; j < nopt; j++) 
		{
			if (i - options[j] < 0)
			{
				continue;
			}
			dp[i - options[j]] = max(dp[i - options[j]], dp[i] + options[j]);
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
	return 0;
}