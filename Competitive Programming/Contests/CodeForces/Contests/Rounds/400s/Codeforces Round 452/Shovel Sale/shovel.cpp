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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int digits(ll k) {
	int ans = 0;
	while (k > 0) {
		k /= 10;
		ans++;
	}
	return ans;
}
int n;
ll toll(string s) {
	ll x = 0;
	FOR(i, 0, s.length()) {
		x *= 10;
		x += (s[i] - '0');
	}
	return x;
}
int f(ll x) {
	if (x > 2 * n - 1) {
		return 0;
	}
	ll l = 1;
	ll r = x - 1;
	int minfirst = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (x - m > n) {
			l = m + 1;
		}
		else {
			minfirst = m;
			r = m - 1;
		}
	}
	return abs(minfirst - (x - minfirst)) + 1;
}
int main(void)
{
	cin >> n;
	int nines = digits(n + n - 1 + 1) - 1;
	if (nines == 0) {
		cout << n * (n - 1) / 2 << endl;
		return 0;
	}
	string s = "";
	FOR(i, 0, nines) {
		s += '9';
	}
	ll ans = 0;
	ans += f(toll(s));
	FOR(i, 1, 101) {
		ll x = toll(to_string(i) + s);
		ans += f(x);
	}
	cout << ans / 2 << endl;

}