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

int a[200005];
int onecount[200005];
ll m = (ll)6e18;
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	RFOR(i, n - 1, -1) {
		if (a[i] == 1) {
			onecount[i] = 1 + onecount[i + 1];
		}
		else
			onecount[i] = 0;
	}
	ll ans = 0;
	FOR(j, 0, n) {
		ll p = 1;
		ll s = 0;
		FOR(i, j, n) {
			if (m / a[i] < p) {
				break;
			}
			if (a[i] != 1) {
				p *= a[i];
				s += a[i];
				if (k * s == p) {
					ans++;
				}
			}
			else {
				if (p > k * s) {
					ll diff = p - k * s;
					if (diff % k == 0) {
						ll q = diff / k;
						if (onecount[i] >= q) {
							ans++;
						}
					}
				}
				s += onecount[i];
				i += onecount[i] - 1;
			}
		}
	}
	cout << ans << endl;

	/*ll ans2 = 0;
	FOR(i, 0, n){
        ll p = 1;
        ll s = 0;
        FOR(j, i, n){
            p *= a[j];
            s += a[j];
            if (p == k * s) ans2++;
        }
    }
    cout << ans2 << endl;*/
}


