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
char a[100005];
int dp[5001][5001];
int pdp[5001][5001];
int query(int i, int a, int b) {
	int ans = 0;
	ans += pdp[i][b];
	if (a > 0) {
		ans -= pdp[i][a - 1];
	}
	ans += M;
	ans %= M;
	return ans;
}
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	FOR(i, 0, n) {
		if (a[i] == 's') {
			dp[i][i] = 1;
			pdp[i][i] = 1;
		}
	}
	RFOR(i, n - 1, -1){
		FOR(j, i + 1, n) {
			if (a[i] == 's') {
				dp[i][j] = dp[i + 1][j]; 
				pdp[i][j] = (dp[i][j] + pdp[i][j - 1]) % M;
				continue;
			}
			if (a[j] == 'f') {
				dp[i][j] = 0;
				pdp[i][j] = (dp[i][j] + pdp[i][j - 1]) % M;
				continue;
			}
			dp[i][j] = query(i + 1, i + 1, j);
			pdp[i][j] = (dp[i][j] + pdp[i][j - 1]) % M;
		}
	}
	cout << dp[0][n - 1] << endl;
}