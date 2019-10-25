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



double dp[2][80707215];
int a[15];
int pow7[12];
int n, m, D;
int get() {
	int ans = 0;
	int pow = 1;
	FOR(i, 0, n + m - 1) {
		ans += pow7[i] * a[i];
	}
	return ans;
}
int getHealth(int x, int i) {
	return (x / pow7[i]) % 7;
}
int health[10];
int main() {
	pow7[0] = 1;
	FOR(i, 1, 12) {
		pow7[i] = 7 * pow7[i - 1];
	}
	scanf("%d%d%d", &n, &m, &D);
	FOR(i, 0, n) {
		scanf("%d", &a[i + m]);
	}
	FOR(i, 0, m){
	    scanf("%d", &a[i]);
	}
	if (D >= n + m) {
		cout << 1 << endl;
		return 0;
	}
	dp[0][get()] = 1;
	FOR(d, 1, D + 1) {
		FOR(mask, 0, pow7[n + m - 1]) {
			int alive = 0;
			int damage = d;
			bool bad = true;
			FOR(i, 0, n + m - 1) {
				health[i] = getHealth(mask, i);
				if (health[i] > a[i]){
                    bad = true;
                    break;
				}
				if (health[i]) {
					alive++;
				}
				damage -= (a[i] - health[i]);
			}
			if (damage < 0 || bad) continue;
			health[n + m - 1] = damage;
			FOR(i, 0, n + m) {
				if (health[i] < a[i]) {
					int prevalive = (alive + (health[i] == 0 ? 1 : 0));
					dp[1][mask] += dp[0][mask + pow7[i]] / prevalive;
				}
			}
		}


		FOR(mask, 0, pow7[n + m - 1]) {
			dp[0][mask] = dp[1][mask];
			dp[1][mask] = 0;
		}
	}
	double ans = 0;
	FOR(i, 0, pow7[n - 1]) {
		ans += dp[0][i * pow7[m]];
	}
	cout << ans << endl;
}


