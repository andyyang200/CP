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
int a[100005];
int n;
ll cnt(int x) {
	int ret = 0;
	FOR(i, 0, n) {
		if (a[i] == x) {
			ret++;
		}
	}
	return ret;
}
int main(void)
{
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	sort(a, a + n);
	int x = a[0];
	int y = a[1];
	int z = a[2];
	if (x == y && y == z) {
		ll c = cnt(x);
		ll ans = c * (c - 1) * (c - 2) / 6;
		cout << ans << endl;
	}
	else if (y == z) {
		ll ans = cnt(y) * (cnt(y) - 1) / 2 * cnt(x);
		cout << ans << endl;
	}
	else if (x == y) {
		ll ans = cnt(y) * (cnt(y) - 1) / 2 * cnt(z);
		cout << ans << endl;
	}
	else {
		ll ans = cnt(x) * cnt(y) * cnt(z);
		cout << ans << endl;
	}
}