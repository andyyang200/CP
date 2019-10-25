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
ll a[100005];
ll dp[100005][3];
ll n, p, q, r;
int main(void)
{
	cin >> n >> p >> q >> r;
	FOR(i, 0, n) {
		cin >> a[i];
	}

	dp[n - 1][0] = r * a[n - 1];
	RFOR(i, n - 2, -1) {
		dp[i][0] = max(dp[i + 1][0], r * a[i]);
	}
	dp[n - 1][1] = q * a[n - 1] + dp[n - 1][0];
	RFOR(i, n - 2, -1) {
		dp[i][1] = max(dp[i + 1][1], q * a[i] + dp[i][0]);
	}
	dp[n - 1][2] = p * a[n - 1] + dp[n - 1][1];
	RFOR(i, n - 2, -1) {
		dp[i][2] = max(dp[i + 1][2], p * a[i] + dp[i][1]);
	}
	cout << dp[0][2] << endl;
}