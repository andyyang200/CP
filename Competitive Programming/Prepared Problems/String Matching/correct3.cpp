#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 100100;
const int MAXM = 1000100;

ll num;
int n, m, k, z[MAXM];
char s[MAXN], t[MAXN], p[MAXM];
bool good[MAXN];

//z algorithm
void init() {
	int l = 0, r = 0;
	for (int i=1; i<k; i++) {
		if (r<=i) {
			l = r = i;
			while (r<k && p[r] == p[r-l]) r++;
			z[i] = r-i;
		} else {
			if (i+z[i-l] < r) z[i] = z[i-l];
			else {
				l = i;
				while (r<k && p[r] == p[r-l]) r++;
				z[i] = r-i;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

	cin >> num >> s >> t;
	n = strlen(s), m = strlen(t);
	if (m*num < n) {
		cout << 0 << endl;
		return 0;
	}
	for (int i=0; i<n; i++) p[k++] = s[i];
	p[k++] = ' ';
	while (k-2*n <= n) {
		for (int i=0; i<m; i++) p[k++] = t[i];
	}
	for (int i=0; i<m; i++) p[k++] = t[i];
	//for (int i=0; i<k; i++) cout << p[i];
	init();
	int cnt = 0;
	for (int i=0; i<m; i++) {
		good[i] = z[i+n+1] == n;
		cnt += good[i];
		//cout << good[i] << endl;
	}

	ll x = (m*num-n)/m;
	ll ans = cnt*x;
	for (ll i=m*x; i+n<=m*num; i++)
		if (good[i%m]) ans++;
	cout << ans << endl;
}
