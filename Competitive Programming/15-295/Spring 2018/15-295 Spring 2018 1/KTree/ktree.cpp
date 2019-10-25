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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
ll dp[10005][2];
int main(void)
{
	int n, d, k;
	cin >> n >> k >> d;
	dp[0][0] = 1;
	FOR(i, 0, n + 1) {
		FOR(j, 1, k + 1) {
			if (j < d) {
				dp[i + j][0] += dp[i][0];
				dp[i + j][0] %= M;
				dp[i + j][1] += dp[i][1];
				dp[i + j][1] %= M;
			}
			else {
				dp[i + j][1] += dp[i][0];
				dp[i + j][1] %= M;
				dp[i + j][1] += dp[i][1];
				dp[i + j][1] %= M;
			}
		}
	}
	cout << dp[n][1] << endl;
}