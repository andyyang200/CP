#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

//---------------------------------------------------------------------------------------------------------------

int dp[2][200001];
int maxr, maxg;
int main() {
	cin >> maxr >> maxg;
	RFOR(i, 900, 0) {
		FOR(r, 0, maxr + 1) {
			int usedr = maxr - r;
			int used = (i - 1) * i / 2;
			int usedg = used - usedr;
			int g = maxg - usedg;
			// if (g < 0) continue;
			if (r >= i) {
				dp[1][r] = max(dp[1][r], dp[0][r - i]);
			}
			if (g >= i) {
				dp[1][r] = max(dp[1][r], dp[0][r]);
			}
			if (i > r && i > g) {
                dp[1][r] = i - 1;
			}
		}
		FOR(i, 0, maxr + 1) {
			dp[0][i] = dp[1][i];
			dp[1][i] = 0;
		}
	}
	int maxh = dp[0][maxr];
	FOR(i, 0, maxr + 1) {
		dp[0][i] = 0;
		dp[1][i] = 0;
	}
	FOR(i, 0, maxr + 1) {
        dp[0][i] = 1;
	}
	RFOR(i, maxh, 0) {
		FOR(r, 0, maxr + 1) {
			int usedr = maxr - r;
			int used = (i - 1) * i / 2;
			int usedg = used - usedr;
			int g = maxg - usedg;
			if (r >= i) {
				dp[1][r] += dp[0][r - i];
				dp[1][r] %= M;
			}
			if (g >= i) {
				dp[1][r] += dp[0][r];
				dp[1][r] %= M;
			}
		}
		FOR(r, 0, maxr + 1) {
			dp[0][r] = dp[1][r];
			dp[1][r] = 0;
		}
	}
	cout << dp[0][maxr] << endl;
}

