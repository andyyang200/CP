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

ll c[100];
int n;
ll L;
string f(ll x) {
	string ans = "";
	while (x) {
		if (x % 2 == 1) {
			ans = '1' + ans;
		}
		else {
			ans = '0' + ans;
		}
		x /= 2;
	}
	while (ans.size() < 64) {
		ans = '0' + ans;
	}
	return ans;
}
ll cost(string str) {
	ll ans = 0;
	FOR(i, 0, 64) {
		if (str[i] == '1') {
			ans += c[64 - i - 1];
		}
	}
	return ans;
}
int main(void)
{
	cin >> n;
	cin >> L;
	FOR(i, 0, 64) {
		c[i] = (ll)INF * (ll)INF;
	}
	FOR(i, 0, n) {
		cin >> c[i];
	}
	FOR(i, 1, 64) {
		c[i] = min(c[i], 2 * c[i - 1]);
	}
	string str = f(L);
	ll ans = cost(str);
	FOR(i, 0, 64) {
		if (str[i] == '0') {
			string t = str;
			t[i] = '1';
			FOR(j, i + 1, 64) {
				t[j] = '0';
			}
			ans = min(ans, cost(t));
		}
	}
	cout << ans << endl;

}