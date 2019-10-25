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



int a[100];
int f(int n) {
	int power = 1;
	int ans = 0;
	FOR(i, 0, n) {
		ans += a[i] * power;
		power *= 2;
	}
	return ans;
}
int main(void)
{
	int t;
	cin >> t;
	FOR(test, 0, t) {
		int d;
		cin >> d;
		string s;
		cin >> s;
		int n = 0;

		FOR(i, 0, s.length() * 2) {
			a[i] = 0;
		}
		FOR(i, 0, s.length()) {
			if (s[i] == 'S') {
				a[n]++;
			}
			else {
				n++;
			}
		}
		n++;
		int ans = 0;
		RFOR(i, n - 1, 0) {
			while (f(n) > d && a[i] > 0) {
				a[i]--;
				a[i - 1]++;
				ans++;
			}
		}
		if (f(n) > d) {
			printf("Case #%d: %s\n", test + 1, "IMPOSSIBLE");
		}
		else {
			printf("Case #%d: %d\n", test + 1, ans);
		}
	}
}

