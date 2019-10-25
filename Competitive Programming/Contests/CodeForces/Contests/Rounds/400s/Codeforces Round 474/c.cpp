#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int bits(ll x) {
	int ans = 0;
	while (x > 0) {
		if (x % 2 == 1) ans++;
		x /= 2;
	}
	return ans;
}

int main() {
	ll x, d;
	cin >> x >> d;
	vector<int> v;
	FOR(j, 0, 60) {
		if (x & (1LL << j)) {
			v.push_back(j);
		}
	}
	vector<ll> ans;
	ll start = 1;
	FOR(i, 0, v.size()) {
		FOR(j, 0, v[i]) {
			ans.push_back(start);
		}
		start += d;
	}
	FOR(i, 0, v.size()) {
		ans.push_back(start);
		start += d;
	}
	cout << ans.size() << endl;
	for (ll x : ans) cout << x << " ";
	cout << endl;
}

