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
	freopen("neighbors.in", "r", stdin);
	freopen("neighbors.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests) {
		int n;
		scanf("%d", &n);
		vector<int> count(6);
		FOR(i, 0, 6) {
			scanf("%d", &count[i]);
		}
		vector<int> ans(n);
		vector<int> lastUsed(6);
		FOR(i, 0, 6) {
			lastUsed[i] = -1;
		}
		FOR(i, 0, 6) {
			if (count[i] != 0) {
				ans[0] = i;
				lastUsed[i] = 0;
				count[i]--;
				break;
			}
		}
		bool good = true;
		FOR(i, 1, n) {
			int maxCount = -1;
			int earliestUsed = INF;
			int best = -1;
			FOR(j, 0, 6) {
				if (j == ans[i - 1]) {
					continue;
				}
				if (count[j] == 0) {
					continue;
				}
				if (count[j] > maxCount) {
					maxCount = count[j];
					best = j;
					earliestUsed = lastUsed[j];
				}
				else if (maxCount > 0 && count[j] == maxCount && lastUsed[j] < earliestUsed) {
					earliestUsed = lastUsed[j];
					best = j;
				}
			}
			if (best == -1) {
				good = false;
				break;
			}
			ans[i] = best;
			lastUsed[best] = i;
			count[best]--;
		}
		if (n > 1 && ans[n - 1] == ans[0]) {
			good = false;
		}
		if (!good) {
			printf("Case #%d: IMPOSSIBLE\n", test + 1);
		}
		else
		{
			printf("Case #%d: ", test + 1);
			FOR(i, 0, n) {
				if (ans[i] == 0) {
					cout << "R";
				}
				else if (ans[i] == 2) {
					cout << "Y";
				}
				else {
					cout << "B";
				}
			}
			cout << endl;
		}
	}
}