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

//---------------------------------------------------------------------------------------------------------------

ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}
pair<ll, ll> euclid(ll a, ll b) {
	if (!b) return { 1, 0 };
	ll x, y;
	tie(x, y) = euclid(b, a % b);
	return { y, x - y * (a / b) };
}
// Returns 0 <= x < m such that a * x = 1 mod m
ll getModInverse(ll a, ll m) {
	assert(a > 0 && m > 0 && gcd(a, m) == 1);
	auto v = euclid(a, m);
	if (v.first < 0) v.first += m;
	if (v.first >= m) v.first -= m;
	return v.first;
}
ll powmod(ll a, ll p, ll m) {
	ll ans = 1;
	while (p) {
		if (p % 2 == 1) {
			ans *= a;
			ans %= m;
			p--;
		}
		a *= a;
		a %= m;
		p /= 2;
	}
	return ans % m;
}

int main() {
	int n, m, c;
	cin >> n >> m >> c;
	ll colors = powmod(c, n * n, M);
	ll ans = powmod(colors, m, M);
	ans %= M;
	FOR(i, 1, m) {
		ans += powmod(colors, gcd(i, m), M);
		ans %= M;
	}
	ll inv = getModInverse(m, M);
	ans *= inv;
	ans %= M;
	cout << ans << endl;

}
