#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 55;
const int MAXM = 1005;
const int MOD = 1e9 + 7;

int n, m;
char s[MAXN], t[MAXM];

struct data {
	int dp[MAXN][MAXN];
};

void add(int& a, int b) { a = (a+b)%MOD; }

data merge(data d1, data d2) {
	data ret = data();
	for (int i=0; i<=n; i++)
		for (int j=i; j<=n; j++)
			for (int k=j; k<=n; k++)
				add(ret.dp[i][k], ll(d1.dp[i][j])*d2.dp[j][k]%MOD);
	return ret;
}

int dp[MAXN][MAXN][2];

data d;

data exp(data b, ll e) {
	if (!e) {
		data ret = data();
		for (int i=0; i<=n; i++) ret.dp[i][i] = 1;
		return ret;
	} else {
		if (e&1) return merge(exp(b, e-1), d);
		data res = exp(b, e/2);
		return merge(res, res);
	}
}

int main() {
	if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

	ll num;
	cin >> num;
	cin >> s >> t;
	n = strlen(s), m = strlen(t);

	for (int i=0; i<=n; i++) dp[i][i][0] = 1;
	for (int i=0; i<m; i++) {
		for (int j=0; j<=n; j++)
			for (int k=j; k<n; k++)
				if (s[k] == t[i])
					add(dp[j][k+1][1], dp[j][k][0]);
		for (int j=0; j<=n; j++)
			for (int k=0; k<=n; k++)
				add(dp[j][k][0], dp[j][k][1]), dp[j][k][1] = 0;
	}
	for (int i=0; i<=n; i++)
		for (int j=0; j<=n; j++)
			d.dp[i][j] = dp[i][j][0];

	data e = exp(d, num);

	cout << e.dp[0][n] << '\n';
}
