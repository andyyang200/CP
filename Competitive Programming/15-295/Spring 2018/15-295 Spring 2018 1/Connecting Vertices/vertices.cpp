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

bool a[501][501];
ll dp[501][501];
int n;
int next(int i) {
	return (i + 1) % n;
}
int prev(int i) {
	return (i - 1 + n) % n;
}
int dis(int i, int j) {
	if (j >= i) {
		return j - i;
	}
	return n - i + j + 1;
}
int main(void)
{
	cin >> n;
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			cin >> a[i][j];
		}
	}
	FOR(d, 1, n) {
		FOR(i, 0, n) {
			int j = (i + d) % n;
			if (!a[i][j]) {
				continue;
			}
			if (d == 1) {
				dp[i][j] = 1;
				continue;
			}
			if (d == 2) {
				dp[i][j] = 2;
				continue;
			}
			for (int k = next(i); k != j; k = next(k)) {
				if (!a[i][k]) {
					continue;
				}
				if (k == next(i)) {
					dp[i][j] += dp[next(k)][prev(j)];
				}
				else if (k == prev(j)) {
					dp[i][j] += dp[next(i)][prev(k)];
				}
				else {
					dp[i][j] += dp[next(i)][prev(k)] * dp[next(k)][prev(j)] % M;
				}
				dp[i][j] %= M;
			}
		}
	}
	ll ans = 0;
	FOR(i, 0, n) {
		FOR(d, 1, n) {
			int j = i + d;
			j %= n;
			if (d == 1) {
				ans += dp[next(j)][prev(i)];
			}
			else if (d == n - 1) {
				ans += dp[next(i)][prev(j)];
			}
			else {
				ans += dp[next(i)][prev(j)] * dp[next(j)][prev(i)] % M;
			}
			ans %= M;
		}
	}
	cout << ans << endl;
}