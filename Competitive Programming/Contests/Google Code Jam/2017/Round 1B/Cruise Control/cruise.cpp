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
struct horse
{
	int d, s;
	bool operator<(const horse o) const {
		return d < o.d;
	}
};
int main(void)
{
	freopen("cruise.in", "r", stdin);
	freopen("cruise.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests) {
		int d, n;
		scanf("%d%d", &d, &n);
		vector<horse> h(n);
		FOR(i, 0, n) {
			scanf("%d%d", &h[i].d, &h[i].s);
		}
		sort(h.begin(), h.end());
		vector<double> t(n);
		t[n - 1] = (double)(d - h[n - 1].d) / h[n - 1].s;
		RFOR(i, n - 2, -1) {
			t[i] = max(t[i + 1], (double)(d - h[i].d) / h[i].s);
		}
		printf("Case #%d: %.9f\n", test + 1, d / t[0]);
	}
}