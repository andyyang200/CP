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
ll dp[1005][10005];
int c[10005];
ll cost[10005];
int main(void)
{
	ll n, W, B, X;
	cin >> n >> W >> B >> X;
	int sum = 0;
	FOR(i, 0, n) {
		cin >> c[i];
		sum += c[i];
	}
	FOR(i, 0, n) {
		cin >> cost[i];
	}
	FOR(i, 0, n + 1) {
		FOR(j, 0, sum + 1) {
			dp[i][j] = -1;
		}
	}
	dp[0][0] = W;
	FOR(i, 0, n) {
		FOR(j, 0, sum + 1) {
			if (dp[i][j] == -1) continue;
			dp[i + 1][j] = max(min(dp[i][j] + X, W + j * B), dp[i + 1][j]);
			ll mana = dp[i][j];
			FOR(k, 1, c[i] + 1) {
				if (cost[i] > mana) break;
				mana -= cost[i];
				dp[i + 1][j + k] = max(dp[i + 1][j + k], min(mana + X, W + B * (j + k)));
			}
		}
	}
	RFOR(i, sum, -1) {
		if (dp[n][i] > -1) {
			cout << i << endl;
			return 0;
		}
	}

}