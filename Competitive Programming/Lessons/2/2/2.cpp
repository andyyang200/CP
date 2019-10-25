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
char grid[1000][1000];
int dp[1000][1000];
int f(int r, int c)
{
	if (r < 0 || c < 0)
	{
		return 0;
	}
	if (grid[r][c] == '#')
	{
		return 0;
	}
	if (dp[r][c] == -1)
	{
		dp[r][c] = f(r - 1, c) + f(r, c - 1);
	}
	return dp[r][c];
}

int main(void)
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> grid[i][j];
		}
	}
	cout << f(n - 1, m - 1) << endl;


	dp[0][0] = 1;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
}