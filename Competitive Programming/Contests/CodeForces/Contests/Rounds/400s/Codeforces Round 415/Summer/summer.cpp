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
pii a[200005];
int n, f;
bool piicompare(pii a, pii b) {
	int x1 = min(2 * a.first, a.second) - min(a.first, a.second);
	int x2 = min(2 * b.first, b.second) - min(b.first, b.second);
	return x1 < x2;
}
int main(void)
{
	cin >> n >> f;
	FOR(i, 0, n) {
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n, piicompare);
	reverse(a, a + n);
	ll ans = 0;
	FOR(i, 0, f) {
		ans += (ll)min(2 * a[i].first, a[i].second);
	}
	FOR(i, f, n) {
		ans += (ll)min(a[i].first, a[i].second);
	}
	cout << ans << endl;
}