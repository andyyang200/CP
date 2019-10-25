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
ll m;
int k;
ll c[100][100];
void init() {
	c[0][0] = 1;
	FOR(i, 1, 64) {
		FOR(j, 0, 64) {
			c[i][j] += c[i - 1][j];
			if (j > 0) {
				c[i][j] += c[i - 1][j - 1];
			}
		}
	}
}
int popcount(ll x) {
	int ans = 0;
	while(x){
        if (x & 1) ans++;
        x /= 2;
	}
	return ans;
}
ll fff(ll x) {
	int y = 0;
	ll ans = 0;
	RFOR(i, 63, -1) {
		if (x & ((ll)1 << i)) {
			if (k - y >= 0)
				ans += c[i][k - y];
			y++;
		}
	}
	if (popcount(x) == k) ans++;
	return ans;
}
bool check(ll mid) { // at least m numbers
	ll a = fff(2 * mid);
	ll b = fff(mid);
	return a - b >= m;
}

int main() {
	init();
	cin >> m >> k;
	ll l = 1;
	ll r = (ll)2e18;
	ll ans = -1;
	while (l <= r) {
		ll mid = (l + r) / 2;
		if (check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
}



