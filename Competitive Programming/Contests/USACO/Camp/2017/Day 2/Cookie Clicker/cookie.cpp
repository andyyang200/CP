//Andrew Yang
//Accepted
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
#include <cmath>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 2e18
#define M 1000000007
#define MAXN 5005
typedef long long ll;
typedef pair<ll, ll> pll;
pll dp[MAXN][MAXN]; // minimum time to reach state
int n;
ll t, ra, rb;
ll getProduction(int i, int j) {
	ll ans = 1;
	ans += (ll)i * ra;
	if (ans > t) return t;
	ans += (ll)j * rb;
	return min(ans, t);
}
pll getmin(pll a, pll b) {
	if (a.first != b.first) {
		return min(a, b);
	}
	if (a.second > b.second) {
		return a;
	}
	return b;
}
int main(void)
{
	cin >> n >> t >> ra >> rb;
	vector<ll> c(n + 1);
	vector<ll> d(n + 1);
	FOR(i, 1, n + 1) {
		cin >> c[i];
	}
	FOR(i, 1, n + 1) {
		cin >> d[i];
	}
	ll ans = t;
	dp[0][0] = { 0, 0 };
	FOR(i, 0, n + 1) {
		FOR(j, 0, n + 1) {
			if (i == 0 && j == 0) continue;
			dp[i][j] = { INF, 0 };
			if (i > 0) {
				pll x = dp[i - 1][j];
				ll production = getProduction(i - 1, j);
				if (production >= t - x.second) continue;
				ll time;
				if (c[i] <= x.second) {
					time = 0;
				}
				else
					time = ceil((double)(c[i] - x.second) / production);
				if (x.first + time < t) {
					dp[i][j] = getmin(dp[i][j], { x.first + time, x.second + time * production - c[i] });
				}
			}
			if (j > 0) {
				pll x = dp[i][j - 1];
				ll production = getProduction(i, j - 1);
				if (production >= t - x.second) continue;
				ll time;
				if (d[j] <= x.second) {
					time = 0;
				}
				else
					time = ceil((double)(d[j] - x.second) / production);
				if (x.first + time <= dp[i][j].first) {
					dp[i][j] = getmin(dp[i][j], { x.first + time, x.second + time * production - d[j] });
				}
			}
		}
	}
	FOR(i, 0, n + 1) {
		FOR(j, 0, n + 1) {
			if (dp[i][j].first < t)
				ans = min(ans, dp[i][j].first + (ll)ceil((double)(t - dp[i][j].second) / getProduction(i, j)));
		}
	}
	cout << (ll)round(ans) << endl;

}