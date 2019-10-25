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

int dp[751][751];
int board[751][751];
int R, C, K;

int main()
{
	freopen("hopscotch.in", "r", stdin);
	freopen("hopscotch.out", "w", stdout);
	scanf("%d%d%d", &R, &C, &K);
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			scanf("%d", &board[r][c]);
		}
	}
	dp[0][0] = 1;
	FOR(r, 0, R)
	{
		FOR(c, 0, C)
		{
			FOR(i, 0, r)
			{
				FOR(j, 0, c)
				{
					if (board[r][c] != board[i][j])
					{
						dp[r][c] += dp[i][j];
						dp[r][c] %= 1000000007;
					}
				}
			}
		}
	}
	cout << dp[R - 1][C - 1] << endl;
}