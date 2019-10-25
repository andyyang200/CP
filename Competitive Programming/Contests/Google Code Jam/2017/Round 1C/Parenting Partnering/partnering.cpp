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
	freopen("parent2.in", "r", stdin);
	freopen("parent2.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests) {
		int c, j;
		cin >> c >> j;
		vector<pii> ac(c);
		vector<pii> aj(j);
		FOR(i, 0, c) {
			scanf("%d%d", &ac[i].first, &ac[i].second);
		}
		FOR(i, 0, j) {
			scanf("%d%d", &aj[i].first, &aj[i].second);
		}
		sort(ac.begin(), ac.end());
		sort(aj.begin(), aj.end());
		int ans = 0;
		if (c == 1 || j == 1) {
			ans = 2;
		}
		else {
			if (c != 0) {
				swap(ac, aj);
			}
			if (aj[1].second - aj[0].first <= 720 || 24 * 60 - aj[1].first + aj[0].second <= 720) {
				ans = 2;
			}
			else
			{
				ans = 4;
			}
		}
		printf("Case #%d: %d\n", test + 1, ans);
	}
}