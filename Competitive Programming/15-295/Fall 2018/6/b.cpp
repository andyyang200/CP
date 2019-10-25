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
#define M 998244353
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

ll dp[1005][2005][4];
int get(int b1, int b2){
    if (b1 == 0 && b2 == 0) return 0;
    if (b1 == 0 && b2 == 1) return 1;
    if (b1 == 0 && b2 == 2) return 1;
    if (b1 == 0 && b2 == 3) return 1;

    if (b1 == 1 && b2 == 0) return 0;
    if (b1 == 1 && b2 == 1) return 0;
    if (b1 == 1 && b2 == 2) return 2;
    if (b1 == 1 && b2 == 3) return 0;

    if (b1 == 2 && b2 == 0) return 0;
    if (b1 == 2 && b2 == 1) return 2;
    if (b1 == 2 && b2 == 2) return 0;
    if (b1 == 2 && b2 == 3) return 0;

    if (b1 == 3 && b2 == 0) return 1;
    if (b1 == 3 && b2 == 1) return 1;
    if (b1 == 3 && b2 == 2) return 1;
    if (b1 == 3 && b2 == 3) return 0;
}
int main() {
	int n, k;
	cin >> n >> k;
	dp[1][1][0] = 1;
	dp[1][2][1] = 1;
	dp[1][2][2] = 1;
	dp[1][1][3] = 1;
	FOR(i, 2, n + 1) {
		FOR(j, 1, k + 1) {
			FOR(b1, 0, 4) {
				FOR(b2, 0, 4) {
				    int j2 = j - get(b2, b1);
				    if (j2 < 0) continue;
					dp[i][j][b1] += dp[i - 1][j2][b2];
					dp[i][j][b1] %= M;
				}
			}
		}
	}
	ll ans = 0;
	FOR(i, 0, 4) {
		ans += dp[n][k][i];
		ans %= M;
	}
	cout << ans << endl;
}

