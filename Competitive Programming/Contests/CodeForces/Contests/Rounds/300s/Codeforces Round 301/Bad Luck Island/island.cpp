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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

double dp[105][105][105];

int main()
{
	int R, S, P;
	scanf("%d%d%d", &R, &S, &P);
	dp[R][S][P] = 1;
	RFOR(r, R, -1)
	{
		RFOR(s, S, -1)
		{
			RFOR(p, P, -1)
			{
				int total = r * s + r * p + s * p;
				if (total == 0)
				{
					continue;
				}
				if (r > 0)
				{
					dp[r - 1][s][p] += dp[r][s][p] * (double)p * r / total;
				}
				if (s > 0)
				{
					dp[r][s - 1][p] += dp[r][s][p] * (double)r * s / total;
				}
				if (p > 0)
				{
					dp[r][s][p - 1] += dp[r][s][p] * (double)s * p / total;
				}
			}
		}
	}
	double r = 0;
	double s = 0;
	double p = 0;
	FOR(i, 1, R + 1)
	{
		r += dp[i][0][0];
	}
	FOR(i, 1, S + 1)
	{
		s += dp[0][i][0];
	}
	FOR(i, 1, P + 1)
	{
		p += dp[0][0][i];
	}
	printf("%.11f %.11f %.11f\n", r, s, p);
}