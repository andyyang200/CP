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
ll n, s;
bool check(ll x) {
	ll t = x;
	ll sum = 0;
	while (t) {
		sum += t % 10;
		t /= 10;
	}
	return x - sum >= s;
}
int main(void)
{
	cin >> n >> s;
	ll l = 1;
	ll r = n;
	ll ans = -1;
	while (l <= r) {
		ll m = (l + r) / 2;
		if (check(m)) {
			ans = m;
			r = m - 1;
		}
		else {
			l = m + 1;
		}
	}
	if (ans == -1) {
		cout << 0 << endl;
	}
	else {
		cout << n - ans + 1 << endl;
	}
}