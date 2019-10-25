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
int d[501][501];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			d[i][j] = INF;
		}
	}
	FOR(i, 0, m)
	{
		int u, v, x;
		scanf("%d%d%d", &u, &v, &x);
		u--;
		v--;
		d[u][v] = x;
		d[v][u] = x;
	}
	FOR(k, 0, n)
	{
		FOR(i, 0, n)
		{
			FOR(j, 0, n)
			{
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}

}
/*
dp[k][i][j] = shortest distance from i to j using first k nodes
dp[k][i][j] = 
{
	min(dp[k - 1][i][j], dp[k][j][k] + dp[k][k][i])
}
*/




/*
Pascal's Triangle

dp[n][k] = nCk
dp[n][k] = 
{
	dp[n - 1][k] + dp[n - 1][k - 1];
}
*/