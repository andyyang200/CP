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
ll gcd(ll a, ll b) {
	while (b) {
		a = a % b;
		swap(a, b);
	}
	return a;
}
int main(void)
{
	ll l, r, x, y;
	cin >> l >> r >> x >> y;
	ll p = x * y;
	if (p % (x * x) != 0) {
		cout << 0 << endl;
		return 0;
	}
	int ans = 0;
	ll mina = ((l + x - 1) / x) * x;
	for (ll a = mina; a <= min((ll)sqrt(p), r); a += x) {
		if (p % a == 0) {
			ll b = p / a;
			if (l <= b && b <= r && gcd(a, b) == x) {
				ans += 2;
			}
		}
	}
	double s = sqrt(p);
	if (s - floor(s) == 0) {
		if (l <= s && s <= r && gcd((ll)s, (ll)s) == x)
			ans--;
	}
	cout << ans << endl;
}


