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
vector<int> edges[100005];
int n, m;
int k, x;
int p[100005];
ll dp[100005][3][11][2];
void dfs(int u) {
	int children = 0;
	for (int v : edges[u]) {
		if (v == p[u]) {
			continue;
		}
		children++;
		p[v] = u;
		dfs(v);
	}
	if (children == 0) {
		dp[u][0][0][1] = k - 1;
		dp[u][1][1][1] = 1;
		dp[u][2][0][1] = x - k; 
	}
	for (int v : edges[u]) {
		if (v == p[u]) {
			continue;
		}
		FOR(i, 0, 11) {
			FOR(j, 0, i + 1) {
				dp[u][0][i][1] += dp[u][0][j][0] + dp[v][0][i - j][0];
				dp[u][0][i][1] %= M;
				dp[u][0][i][1] += dp[u][0][j][0] + dp[v][1][i - j][0];
				dp[u][0][i][1] %= M;
				dp[u][0][i][1] += dp[u][0][j][0] + dp[v][2][i - j][0];
				dp[u][0][i][1] %= M;
			}
		}
	}
	for (int v : edges[u]) {
		if (v == p[u]) {
			continue;
		}
		FOR(i, 0, 11) {
			FOR(j, 0, i) {
				dp[u][1][i][1] += dp[u][1][j][0] + dp[v][0][i - j - 1][0];
				dp[u][1][i][1] %= M;
				
			}
		}
	}
	for (int v : edges[u]) {
		if (v == p[u]) {
			continue;
		}
		FOR(i, 0, 11) {
			FOR(j, 0, i + 1) {
				dp[u][2][i][1] += dp[u][2][j][0] + dp[v][0][i - j][0];
				dp[u][2][i][1] %= M;
				dp[u][0][i][1] += dp[u][2][j][0] + dp[v][2][i - j][0];
				dp[u][0][i][1] %= M;
			}
		}
	}
	FOR(i, 0, 3) {
		FOR(j, 0, 11) {
			if (i == 0) {
				dp[u][i][j][1] *= k - 1;
				dp[u][i][j][1] %= M;
			}
			if (i == 2) {
				dp[u][i][j][1] *= x - k;
				dp[u][i][j][1] %= M;
			}
			dp[u][i][j][0] = dp[u][i][j][1];
			dp[u][i][j][1] = 0;
		}
	}
	int a = 5;
}
int main(void)
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, n - 1) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		edges[u].push_back(v);
		edges[v].push_back(u);
	}
	scanf("%d%d", &k, &x);
	dfs(0);
	ll ans = 0;
	FOR(i, 0, 3) {
		FOR(j, 0, x + 1) {
			ans += dp[0][i][j][0];
			ans %= M;
		}
	}
	cout << ans << endl;
}