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
	freopen("training1.in", "r", stdin);
	freopen("training1.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests) {
		int n, k;
		double u;
		scanf("%d%d", &n, &k);
		cin >> u;
		vector<double> p(n);
		FOR(i, 0, n) {
			cin >> p[i];
		}
		double x;
		double l = 0;
		double r = 1;
		FOR(i, 0, 150) {
			double m = (l + r) / 2;
			double sum = 0;
			FOR(j, 0, n) {
				if (p[j] < m) {
					sum += m - p[j];
				}
			}
			if (sum <= u) {
				x = m;
				l = m;
			}
			else
			{
				r = m;
			}
		}
		double ans = 0;
		FOR(i, 0, n) {
			if (p[i] < x) {
				p[i] = x;
			}
		}
		ans = p[0];
		FOR(i, 1, n) {
			ans *= p[i];
		}
		printf("Case #%d: %.9f\n", test + 1, ans);
	}
}
/*
2
4 4
1.4000
0.5000 0.7000 0.8000 0.6000
2 2
1.0000
0.0000 0.0000
*/