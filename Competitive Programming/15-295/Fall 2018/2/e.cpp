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

map<pii, ll> dp;

int maxh = 0;
int maxr, maxg;
ll f(int i, int r) {
	if (i == maxh + 1) {
		return 1;
	}
	if (dp.find({ i, r }) != dp.end()) {
		return dp[{i, r}];
	}
	int usedr = maxr - r;
	int used = (i - 1) * i / 2;
	int usedg = used - usedr;
	int g = maxg - usedg;
	ll ans = 0;
	if (i <= r) {
		ans += f(i + 1, r - i);
		ans %= M;
	}
	if (i <= g) {
		ans += f(i + 1, r);
		ans %= M;
	}
	return dp[{i, r}] = ans;
}
ll f2(int i, int r) {
	if (dp.find({ i, r }) != dp.end()) {
		return dp[{i, r}];
	}
	int usedr = maxr - r;
	int used = (i - 1) * i / 2;
	int usedg = used - usedr;
	int g = maxg - usedg;
	ll ans = 0;
	if (i <= r) {
		ans = max(ans, f2(i + 1, r - i));
	}
	if (i <= g) {
		ans = max(ans, f2(i + 1, r));
	}
	if (i > r && i > g) {
		return i - 1;
	}
	return dp[{i, r}] = ans;
}

int main() {
	cin >> maxr >> maxg;
	maxh = f2(1, maxr);
	cout << maxh << endl;
	dp.clear();
	cout << f(1, maxr) << endl;
}
