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


const int MAXN = 100100;
const int MAXM = 1000100;

ll num;
int n, m, k, z[MAXM];
char s[MAXN], t[MAXN], p[MAXM];
bool good[MAXN];

void init() {
	int l = 0, r = 0;
	FOR(i, 1, k) {
		if (r <= i) {
			l = r = i;
			while (r < k && p[r] == p[r - l]) r++;
			z[i] = r - i;
		} else {
			if (i + z[i - l] < r) z[i] = z[i - l];
			else {
				l = i;
				while (r < k && p[r] == p[r - l]) r++;
				z[i] = r - i;
			}
		}
	}
}

int main() {

	cin >> num >> s >> t;
	n = strlen(s), m = strlen(t);
	if (m * num < n) {
		cout << 0 << endl;
		return 0;
	}
	FOR(i, 0, n) p[k++] = s[i];
	p[k++] = ' ';
	while (k - 2 * n <= n) {
		FOR(i, 0, m) p[k++] = t[i];
	}
	FOR(i, 0, m) p[k++] = t[i];
	//for (int i=0; i<k; i++) cout << p[i];
	init();
	int cnt = 0;
	FOR(i, 0, m){
		good[i] = z[i+n+1] == n;
		cnt += good[i];
		//cout << good[i] << endl;
	}

	ll x = (m * num - n) / m;
	ll ans = cnt * x;
	for (ll i = m * x; i + n <= m * num; i++)
		if (good[i % m]) ans++;
	cout << ans << endl;
}
