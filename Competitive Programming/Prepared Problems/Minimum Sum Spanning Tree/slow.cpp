#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------
int n;
int d[16][16];
ll dp[1 << 16][20];
int main(){
    scanf("%d", &n);
	fill(dp[0], dp[0] + (1 << 16) * 16, (ll)INF * INF);
	FOR(i, 0, n) {
		FOR(j, i + 1, n) {
			scanf("%d", d[i] + j);
			d[j][i] = d[i][j];
		}
		dp[1 << i][i] = 0;
	}
	FOR(mask, 0, 1 << n) {
		int nn = __builtin_popcount(mask);
		FOR(i, 0, n) {
			if (mask & (1 << i)) {
				int nmask = mask ^ (1 << i);
				for (int t = nmask; t > 0; t = (t - 1) & nmask) {
                    int nm = __builtin_popcount(t);
					FOR(j, 0, n){
                        if (t & (1 << j)){
                            dp[mask][i] = min(dp[mask][i], dp[mask ^ t][i] + dp[t][j] + (ll)d[i][j] * nm * (n - nm));
                        }
					}
				}

			}
		}
	}
	printf("%lld\n", *min_element(dp[(1 << n) - 1], dp[(1 << n) - 1] + n));
}

