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
typedef long long ll;
typedef pair<int, int> pii;
ll f[1000005], invf[1000005];
ll ipow(ll x, ll p) {
	ll ans = 1, r = x % M;
	while (p) {
		if (p & 1) ans *= r;
		r *= r;
		ans %= M;
		r %= M;
		p >>= 1;
	}
	return ans % M;
}
ll c(int x, int y) {
	if (x < y) {
		return 0;
	}
	return f[x] * (invf[y] * invf[x - y] % M) % M;
}
int ct[26];
ll query(int a, int b) {
	if (a > b) return 0;
	int ans = 0;
	FOR(i, a, b + 1)ans += ct[i];
	return ans;
}
ll query(string a, string b) {
	FOR(i, 0, 26) ct[i] = 0;
	FOR(i, 0, a.length()) {
		ct[a[i] - 'a']++;
	}
	ll ans = 0;
	FOR(i, 0, a.length()) {
		ll x = f[a.length() - 1 - i] % M;
		FOR(j, 0, 26) {
			x *= invf[ct[j]];
			x %= M;
		}
		FOR(j, 0, 26) {
			if (j >= b[i] - 'a') break;
			if (ct[j] == 0) continue;
			ans += x * f[ct[j]] % M * invf[ct[j] - 1] % M;
			ans %= M;
		}
		if (ct[b[i] - 'a'] == 0) {
			break;
		}
		ct[b[i] - 'a']--;
	}
	return ans;
}
int main(void)
{
	f[0] = invf[0] = 1;
	FOR(i, 1, 1000005) {
		f[i] = f[i - 1] * i % M;
		invf[i] = ipow(f[i], M - 2);
	}
	string a, b;
	cin >> a >> b;
	ll x = query(a, b);
	ll y = query(a, a);
	ll ans = x - y - 1;
	ans = (ans + 2 * M) % M;
	cout << ans << endl;
}