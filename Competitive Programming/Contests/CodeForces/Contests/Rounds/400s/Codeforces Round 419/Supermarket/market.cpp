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
int n, b;
int c[5005];
int d[5005];
int x[5005];
vector<int> children[5005];
bool bad[5005];
bool visited[5005];
ll dp[5005][5005][2];
vector<int> v;
void dfs(int node) {
	for (int x : children[node]) {
		dfs(x);
	}
	FOR(i, 0, n + 1) {
		dp[node][i][0] = dp[node][i][1] = 1e18;
	}
	dp[node][0][0] = 0;
	dp[node][1][0] = c[node];
	dp[node][1][1] = d[node] - d[node];
	for (int x : children[node]) {
		RFOR(i, n, 0) {
			dp[node][i][0] = min(dp[node][i][0], dp[x][i - 1][0] + c[node]);
			dp[node][i][1] = min(dp[node][i][1], dp[x][i - 1][1] + c[node] - d[node]);
		}
	}
}
int main(void)
{
	scanf("%d%d", &n, &b);
	x[0] = -1;
	FOR(i, 0, n) {
		scanf("%d%d", &c[i], &d[i]);
		if (i > 0) {
			scanf("%d", &x[i]);
			x[i]--;
			children[x[i]].push_back(i);
		}
	}
	FOR(i, 0, n) {
		int cur = i;
		int cnt = 0;
		while (cur != -1) {
			cur = x[cur];
			cnt++;
			if (cnt > n + 2) {
				bad[i] = true;
				break;
			}
		}
	}
	dfs(0);
	FOR(i, 0, n) {
		FOR(j, 0, n + 1) {
			FOR(k, 0, 2) {
				dp[i][j][k] = 1e18;
			}
		}
	}
	dp[0][0][0] = dp[0][0][1] = 0;
	FOR(i, 0, v.size()) {
		dp[i][0][0] = 0;
		if (i == 0) {
			dp[i][1][0] = c[i];
			dp[i][1][1] = c[i] - d[i];
		}
		if (i > 0) {
			FOR(j, 1, n + 1) {
				dp[i][j][0] = min(d[i][j][0], dp[i - 1][j - 1][0] + c[i], dp[i - 1][j - 1][1] + c[i] - d[i])
			}
		}
	}
}