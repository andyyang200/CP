#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------





struct tup {
	int i, j, k;
	tup() {

	}
	tup(int a, int b, int c) {
		i = a;
		j = b;
		k = c;
	}
};
int dp[105][105][105];
tup p[105][105][105];
bool taken[105][105][105];
string s1, s2, v;

int main() {
	cin >> s1 >> s2 >> v;
	FOR(i, 1, s1.length() + 1) {
		FOR(j, 1, s2.length() + 1) {
			FOR(k, 1, v.length()) {
				dp[i][j][k] = -INF;
				taken[i][j][k] = false;
				if (s1[i - 1] == s2[j - 1] && s1[i - 1] == v[k - 1]) {
					int x = dp[i - 1][j - 1][k - 1] + 1;
					if (x > dp[i][j][k]) {
						dp[i][j][k] = x;
						p[i][j][k] = tup(i - 1, j - 1, k - 1);
						taken[i][j][k] = true;
					}
				}
				else {
					int x = dp[i][j - 1][k];
					if (x > dp[i][j][k]) {
						dp[i][j][k] = x;
						p[i][j][k] = tup(i, j - 1, k);
						taken[i][j][k] = false;
					}
					x = dp[i - 1][j][k];
					if (x > dp[i][j][k]) {
						dp[i][j][k] = x;
						p[i][j][k] = tup(i - 1, j, k);
						taken[i][j][k] = false;
					}
				}

			}
		}
	}
	int x = dp[s1.length()][s2.length()][v.length()];
	if (x <= 0) {
		cout << 0 << endl;
		return 0;
	}
	else {
		string ans = "";
		int i = s1.length();
		int j = s2.length();
		FOR(k, 0, v.length()) {
			x = max(x, dp[s1.length()][s2.length()][k]);
		}
		cout << x << endl;
		FOR(k, 0, v.length()) {
			if (x == dp[s1.length()][s2.length()][k]) {

				while (i > 0 && j > 0 && dp[i][j][k] > 0) {
					int i2 = p[i][j][k].i;
					int j2 = p[i][j][k].j;
					int k2 = p[i][j][k].k;
					if (taken[i][j][k]) {
						ans += s1[i - 1];
					}
					i = i2;
					j = j2;
					k = k2;
				}
				break;
			}
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
		return 0;
	}
}


