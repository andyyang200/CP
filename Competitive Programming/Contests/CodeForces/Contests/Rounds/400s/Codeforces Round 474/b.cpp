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

int a[1000];
int b[1000];
int main() {
	int n, k1, k2;
	cin >> n >> k1 >> k2;


	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	FOR(i, 0, n) {
		scanf("%d", &b[i]);
	}
	FOR(i, 0, k1 + k2) {
		int j = 0;
		int ma = 0;
		FOR(i, 0, n) {
			int d = abs(a[i] - b[i]);
			if (d > ma) {
				ma = d;
				j = i;
			}
		}
		if (a[j] <= b[j]) a[j]++;
		else {
			a[j]--;
		}
	}
	ll ans = 0;
	FOR(i, 0, n) {
		ll x = a[i] - b[i];
		x *= x;
		ans += x;
	}
	cout << ans << endl;
}
