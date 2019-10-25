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
	freopen("syrup.in", "r", stdin);
	freopen("syrup.out", "w", stdout);
	double PI = atan(1) * 4;
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests) {
		int n, k;
		scanf("%d%d", &n, &k);
		int maxr = 0;
		
		vector<int> r(n);
		vector<int> h(n);
		set<int> radii;
		FOR(i, 0, n) {
			scanf("%d%d", &r[i], &h[i]);
		}
		double bestAns = 0;
		FOR(i, 0, n) {
			vector<double> s;
			double ans = 0;
			ans += (double)h[i] * (double)2 * (double)r[i] * PI;
			FOR(j, 0, n) {
				if (j == i) {
					continue;
				}
				if (r[j] <= r[i]) {
					s.push_back((double)h[j] * (double)2 * (double)r[j] * PI);
				}
			}
			sort(s.begin(), s.end());
			reverse(s.begin(), s.end());
			while (s.size() > k - 1) {
				s.erase(--s.end());
			}
			FOREACH(itr, s) {
				ans += *itr;
			}
			ans += (double)r[i] * (double)r[i] *PI;
			if (s.size() == k - 1) {
				bestAns = max(bestAns, ans);
			}	
		}
		printf("Case #%d: %.15f\n", test + 1, bestAns);
	}
}
/*
4
2 1
100 20
200 10
2 2
100 20
200 10
3 2
100 10
100 10
100 10
4 2
9 3
7 1
10 1
8 4
*/