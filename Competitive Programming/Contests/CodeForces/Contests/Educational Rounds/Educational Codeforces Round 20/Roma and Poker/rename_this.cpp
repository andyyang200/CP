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
int dp[1005][2005];
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	if (k > n) {
		cout << "NO" << endl;
		return 0;
	}
	string s;
	cin >> s;
	s = " " + s;
	FOR(i, 0, s.length()) {
		FOR(j, 0, 2 * n + 3) {
			dp[i][j] = INF;
		}
	}
	dp[0][n + 1] = 0; // shift all values by n + 1
	FOR(i, 1, s.length()) {
		FOR(j, 1, 2 * n + 2) {
			if (i < s.length() - 1 && (j == k + n + 1 || j == n + 1 - k)) {
				continue;
			}
			if (s[i] == '?') {
				FOR(x, -1, 2) {
					if (dp[i - 1][j - x] != INF) {
						dp[i][j] = x;
						break;
					}
				}
			}
			else {
				int x = INF;
				if (s[i] == 'W') x = 1;
				if (s[i] == 'L') x = -1;
				if (s[i] == 'D') x = 0;
				if (dp[i - 1][j - x] != INF) {
					dp[i][j] = x;
				}
			}
		}
	}
	int x = -1;
	if (dp[n][k + n + 1] != INF) {
		x = k + n + 1;
	}
	else if (dp[n][n + 1 - k] != INF) {
		x = n + 1 - k;
	}
	if (x == -1) {
		cout << "NO	" << endl;
		return 0;
	}
	string ans = "";
	RFOR(i, n, 0) {
		if (dp[i][x] == -1) ans = 'L' + ans;
		if (dp[i][x] == 0) ans = 'D' + ans;
		if (dp[i][x] == 1) ans = 'W' + ans;
		x -= dp[i][x];
	}
	cout << ans << endl;
}