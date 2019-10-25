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


ll c[100];
int n;
ll L;
ll cost(ll x) {
	ll ans = 0;
	FOR(i, 0, 40) {
		if (x & ((ll)1 << i)) {
			ans += c[i];
		}
	}
	return ans;
}
int main(void)
{
	cin >> n;
	cin >> L;
	FOR(i, 0, 40) {
		c[i] = (ll)INF * (ll)INF;
	}
	FOR(i, 0, n) {
		cin >> c[i];
	}
	FOR(i, 1, 40) {
		c[i] = min(c[i], 2 * c[i - 1]);
	}
	ll ans = cost(L);
	FOR(i, 0, 40) {
		if ((L & ((ll)1 << i)) == 0) {
			ll L2 = L + ((ll)1 << i);
			FOR(j, 0, i) {
				if (L2 & ((ll)1 << j)) L2 -= ((ll)1 << j);
			}
			ans = min(ans, cost(L2));
		}
	}
	cout << ans << endl;

}

