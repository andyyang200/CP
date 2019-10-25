//Andrew Yang
#include <iostream>
#include <stdio.h>
#include <sstream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>	
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
#define P 37
typedef long long ll;
typedef pair<int, int> pii;
bool dp[2][5001][5001];
bool base[5001][5001];
ll ph[5001];
ll p[5001];
ll q(int l, int r) {
	ll ans = ph[r];
	if (l > 0) {
		ans -= (ph[l - 1] * p[r - l + 1]) % M;
	}
	if (ans < 0) {
		ans += M;
	}
	return ans;
}
int ret[5001];
int main(void)
{
	string s;
	cin >> s;
	int n = s.size();
	ph[0] = s[0];
	p[0] = 1;
	FOR(i, 1, n) {
		ph[i] = (ph[i - 1] * P + s[i]) % M;
		p[i] = p[i - 1] * P % M;
	}
	FOR(i, 0, n) {
		dp[0][i][i] = 1;
		base[i][i] = 1;
		ret[0]++;
	}
	FOR(i, 0, n - 1) {
		if (s[i] == s[i + 1]) {
			dp[0][i][i + 1] = 1;
			base[i][i + 1] = 1;
			ret[0]++;
		}
	}
	FOR(d, 3, n + 1) {
		FOR(i, 0, n) {
			int j = i + d - 1;
			if (j >= n) {
				break;
			}
			if (s[i] == s[j] && dp[0][i + 1][j - 1]) {
				dp[0][i][j] = 1;
				base[i][j] = 1;
				ret[0]++;
			}
		}
	}
	FOR(x, 1, 15) {
		FOR(d, 1 << x, n + 1) {
			FOR(i, 0, n) {
				int j = i + d - 1;
				if (j >= n) {
					break;
				}
				int t = d / 2;
				if (base[i][j] && dp[0][i][i + t - 1] && dp[0][j - t + 1][j] && q(i, i + t - 1) == q(j - t + 1, j)) {
					dp[1][i][j] = 1;
					ret[x]++;
				}
				else {
					dp[1][i][j] = 0;
				}
			}
		}
		if (ret[x] == 0) {
			break;
		}
		FOR(i, 0, n) {
			FOR(j, i + (1 << x) - 1, n) {
				dp[0][i][j] = dp[1][i][j];
			}
		}
	}
	FOR(i, 0, n) {
		printf("%d ", ret[i]);
	}
	cout << endl;
}