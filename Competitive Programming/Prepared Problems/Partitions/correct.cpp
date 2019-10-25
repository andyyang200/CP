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

int a[100005];
int dp[100005];
int pdp[100005];
int n;
int table[100005][20];

int f(int a, int b) {
	return max(a, b);
}
void build() {
	FOR(i, 0, n)
		table[i][0] = a[i];
	for (int j = 1; (1 << j) <= n; j++) {
		for (int i = 0; i + (1 << j) - 1 < n; i++) {
			table[i][j] = f(table[i][j - 1], table[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int query(int l, int r) {
	if (l > r || l >= n || r >= n) {
		return INF;
	}
	int k = (int)log2(r - l + 1);
	return f(table[l][k], table[r - (1 << k) + 1][k]);
}
int main(void)
{
    scanf("%d", &n);
    FOR(i, 0, n) {
        scanf("%d", &a[i]);
    }
    build();
    int j = -1;
    FOR(i, 0, n) {
        while (j + 1 < i && query(j + 1, i) <= query(i + 1, n - 1)) {
            j++;
        }
        dp[i] = 0;
        if (query(j, i) <= query(i + 1, n - 1)) {
            if (j >= 0) {
                dp[i] = pdp[j];
            }
            dp[i]++;
            dp[i] %= M;
        }
        pdp[i] = dp[i] + (i > 0 ? pdp[i - 1] : 0);
        pdp[i] %= M;
    }
    cout << dp[n - 1] << endl;
}
