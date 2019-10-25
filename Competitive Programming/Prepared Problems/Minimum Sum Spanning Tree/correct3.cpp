#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const int64_t INF = 1e+15;
int d[N][N];
int64_t dp[1 << N][N];
int64_t best[1 << N][N];
int n;
int nn;

void update(int mask, int i, int nmask) {
	int64_t nm = __builtin_popcount(nmask);

	dp[mask][i] = min(dp[mask][i], dp[mask ^ nmask][i] + best[nmask][i]);
	// if (best[nmask][i] > dp[nmask][j] + d[i][j] * nm * (n - nm)) {
	// 	cout << nmask << ' ' << i << ' ' << j << "\n";
	// 	cout << "\t" << dp[nmask][j] << ' ' << d[i][j] << ' ' << nm << "\n";
	// 	cout << "Badd\n";
	// 	exit(1);
	// }
}

int main() {
	scanf("%d", &n);
	fill(dp[0], dp[0] + (1 << N) * N, INF);
	fill(best[0], best[0] + (1 << N) * N, INF);
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
					int64_t nm = __builtin_popcount(mask);
					best[mask][j] = min(best[mask][j], dp[mask][i] + d[i][j] * nm * (n - nm));
					// cout << "update " << mask << ' ' << j << ' ' << i << "\n";
					// cout << "\t" << dp[mask][i] << ' ' << d[i][j] << ' ' << nm << "\n";
				}
			}
		}
	}
	printf("%lld\n", *min_element(dp[(1 << n) - 1], dp[(1 << n) - 1] + n));
	return 0;
}
