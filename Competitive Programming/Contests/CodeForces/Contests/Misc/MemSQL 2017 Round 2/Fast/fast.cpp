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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
double dp[51][100005];
int f[51];
int s[51];
int p[51];
double ans[5][100005];
int main(void)
{
	int n, r;
	scanf("%d%d", &n, &r);
	FOR(i, 0, n) {
		scanf("%d%d%d", &f[i], &s[i], &p[i]);
	}
	FOR(i, 0, r + 1) {
		dp[n][i] = 1;
	}
	RFOR(i, n - 1, -1) {
		FOR(j, 0, r + 1) {
			if (j + f[i] <= r) {
				dp[i][j] += f[i] + dp[i + 1][j + f[i]] * p[i];
			}
			if (j + s[i] <= r) {
				dp[i][j] += dp[i + 1][j + s[i]] * (1 - p[i]);
			}
		}
	}
	FOR(i, 0, r + 1) {
		ans[0][i] = dp[0][i];
	}
	FOR(x, 1, 3) {
		RFOR(i, n - 1, -1) {
			FOR(j, 0, r + 1) {
				if (j + f[i] <= r) {
					dp[i][j] += dp[i + 1][j + f[i]] * p[i];
				}
				if (j + s[i] <= r) {
					dp[i][j] += dp[i + 1][j + s[i]] * (1 - p[i]);
				}
				dp[i][j] = max(dp[i][j], ans[x - 1][j]);
			}
		}
	}
	double diff2 = ans[2][0] - ans[1][0];
	double diff1 = ans[1][0] - ans[0][0];
	double ratio = diff2 / diff1;
	double ret = ans[0][0] / (1 - ratio);
	printf("%.9f\n", ret);
}