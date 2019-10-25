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
vector<pii> edges[100]; // node, cost
int memo[85][85][85][85];
int dp(int loc, int l, int r, int k) {
	if (k == 0) {
		return 0;
	}
	int val = memo[loc][l][r][k];
	if (val != 0)
	{
		return val;
	}
	int ans = INF;
	for(pii e : edges[loc]) {
		if (e.first >= l && e.first < loc)
		{
			int x = e.second + dp(e.first, l, loc - 1, k - 1);
			ans = min(ans, x);
		}
		else if (e.first <= r && e.first > loc) {
			int x = e.second + dp(e.first, loc + 1, r, k - 1);
			ans = min(ans, x);
		}
	}
	return memo[loc][l][r][k] = ans;
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	int m;
	scanf("%d", &m);
	FOR(i, 0, m) {
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		v--;
		u--;
		edges[u].push_back({ v, c });
	}
	int ans = INF;
	FOR(i, 0, n) {
		ans = min(ans, dp(i, 0, n - 1, k - 1));
	}
	if (ans == INF) {
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}
}