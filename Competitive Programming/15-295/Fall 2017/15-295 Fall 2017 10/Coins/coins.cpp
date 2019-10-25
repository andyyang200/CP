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
double dp[500][500]; // flip, heads
int main(void)
{
	int n, k;
	cin >> n >> k;
	FOR(i, 0, 500) {
		FOR(j, 0, 500) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1;
	FOR(i, 0, k) {
		FOR(j, 0, n + 1) {
			if (abs(dp[i][j] + 1) < 1e-9) continue;
			if (j < n) {
				if (dp[i + 1][j] < 0) dp[i + 1][j] = 0;
				if (dp[i + 1][j + 1] < 0) dp[i + 1][j + 1] = 0;
				dp[i + 1][j] += dp[i][j] * 0.5;
				dp[i + 1][j + 1] += dp[i][j] * 0.5;
			}
			else {

				if (dp[i + 1][j] < 0) dp[i + 1][j] = 0;
				if (dp[i + 1][j - 1] < 0) dp[i + 1][j - 1] = 0;
				dp[i + 1][j] += dp[i][j] * 0.5;
				dp[i + 1][j - 1] += dp[i][j] * 0.5;
			}
		}
	}
	double ans = 0;
	FOR(i, 0, n + 1){
		if (dp[k][i] >0)
			ans += i * dp[k][i];
	}
	printf("%.9f\n", ans);
}