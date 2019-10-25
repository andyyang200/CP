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


int a[100005];
int main() {
	int n, s;
	cin >> n >> s;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	if (n == 1) {
        cout << abs(a[0] - s) << endl;
        return 0;
	}
	multiset<int> x;
	multiset<int> y;
	FOR(i, 0, n) {
		if (a[i] <= s) {
			x.insert(a[i]);
		}
		else {
			y.insert(a[i]);
		}
	}
	ll ans = 0;
	if (x.size() > y.size()) {
		auto itr = --x.end();
		ans += abs(*itr - s);
		x.erase(itr);
		itr = --x.end();
		int ysize = y.size();
		FOR(i, 0, x.size() - (n - 1) / 2) {
			ans += abs(*itr - s);
			itr--;
		}
	}
	else {
		auto itr = y.begin();
		ans += abs(*itr - s);
		y.erase(itr);
		itr = y.begin();
		FOR(i, 0, y.size() - (n - 1) / 2) {
			ans += abs(*itr - s);
			itr++;
		}
	}
	cout << ans << endl;
}

