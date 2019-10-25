#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const int MAXN = 16;
const ll INF = 1e+15;
int d[MAXN][MAXN];
ll dp[1 << MAXN][MAXN];
ll best[1 << MAXN][MAXN];
int n;
int nn;

void update(int mask, int i, int nmask) {
	ll nm = __builtin_popcount(nmask);
	dp[mask][i] = min(dp[mask][i], dp[mask ^ nmask][i] + best[nmask][i]);
}

int main() {
	scanf("%d", &n);
	fill(dp[0], dp[0] + (1 << MAXN) * MAXN, INF);
	fill(best[0], best[0] + (1 << MAXN) * MAXN, INF);
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			scanf("%d", d[i] + j);
			d[j][i] = d[i][j];
		}
		dp[1 << i][i] = 0;
	}
	for (int mask = 0; mask < (1 << n); ++mask) {
		int nn = __builtin_popcount(mask);
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				int nmask = mask ^ (1 << i);
				for (int t = nmask; t > 0; t = (t - 1) & nmask) {
					update(mask, i, t);
				}

			}
		}
		for (int i = 0; i < n; ++i) {
			if ((mask >> i) & 1) {
				for (int j = 0; j < n; ++j) {
					ll nm = __builtin_popcount(mask);
					best[mask][j] = min(best[mask][j], dp[mask][i] + d[i][j] * nm * (n - nm));
				}
			}
		}
	}
	printf("%lld\n", *min_element(dp[(1 << n) - 1], dp[(1 << n) - 1] + n));
	return 0;
}
