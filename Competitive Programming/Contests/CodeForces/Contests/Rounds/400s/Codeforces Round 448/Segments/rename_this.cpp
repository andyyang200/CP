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
map<int, int> m;
int query(int a, int b, int x) {
	b = (b / x);
	a = a / x + (a % x != 0);
	if (b < a) return 0;
	return b - a + 1;

}
int main(void)
{
	int n, x, k;
	cin >> n >> x >> k;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	sort(a, a + n);

	int j = -1;
	int j2 = -1;
	ll ans = 0;
	FOR(i, 0, n) {
		j = max(j, i - 1);
		while ((j < i || query(a[i], a[j], x) < k) && j + 1 < n && query(a[i], a[j + 1], x) <= k) {
			j++;
		}
		j2 = max(j2, i - 1); 
		while (j2 + 1 < n && query(a[i], a[j2 + 1], x) <= k) {
			j2++;
		}
		if (query(a[i], a[j], x) == k && query(a[i], a[j2], x) == k && j2 >= j && a[i] <= a[j] && a[i] <= a[j2]) {
			ans += j2 - j + 1;
		}
	}
	if (k == 1) {
		map<int, int> m;
		FOR(i, 0, n) {
			m[a[i]]++;
		}
		FOREACH(itr, m) {
			if (itr->first % x == 0) {
				ll x = itr->second;
				ans += x * (x - 1) / 2;
			}
		}
	}
	if (k == 0) {
		map<int, int> m;
		FOR(i, 0, n) {
			m[a[i]]++;
		}
		FOREACH(itr, m) {
			if (itr->first % x != 0) {
				ll x = itr->second;
				ans += x * (x - 1) / 2;
			}
		}
	}
	cout << ans << endl;
}
/*
9 3 1
1 3 3 3 3 3 1 6 6
*/
/*
5 3 0
1 1 1 1 1
*/