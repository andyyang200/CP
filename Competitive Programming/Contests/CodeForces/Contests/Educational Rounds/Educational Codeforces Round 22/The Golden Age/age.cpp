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

int main(void)
{
	ll x, y, l, r;
	cin >> x >> y >> l >> r;
	vector<ll> a;
	ll ans = 1;
	a.push_back(1);
	while (ans <= r / x) {
		ans *= x;
		a.push_back(ans);
	}
	vector<ll> b;
	ans = 1;
	b.push_back(1);
	while (ans <= r / y) {
		ans *= y;
		b.push_back(ans);
	}
	set<ll> s;
	FOR(i, 0, a.size()) {
		FOR(j, 0, b.size()) {
			s.insert(a[i] + b[j]);
		}
	}
	s.insert(l - 1);
	s.insert(r + 1);
	vector<ll> v;
	for (ll aa : s) {
		v.push_back(aa);
	}
	ll ret = 0;

	FOR(i, 0, v.size() - 1) {
		if (v[i] >= l - 1 && v[i + 1] <= r + 1) {
			ret = max(ret, v[i + 1] - v[i] - 1);
		}
	}
	cout << ret << endl;
}