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
#define INF 1e14
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int main(void)
{
	freopen("express.in", "r", stdin);
	freopen("express.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests) {
		int n, q;
		scanf("%d%d", &n, &q);
		vector<ll> e(n);
		vector<ll> s(n);
		vector<vector<ll>> distances(n);
		FOR(i, 0, n) {
			distances[i] = vector<ll>(n);
		}
		FOR(i, 0, n) {
			scanf("%lld%lld", &e[i], &s[i]);
		}
		FOR(i, 0, n) {
			FOR(j, 0, n) {
				scanf("%lld", &distances[i][j]);
				if (distances[i][j] == -1) {
					distances[i][j] = INF;
				}
			}
		}
		FOR(k, 0, n) {
			FOR(i, 0, n) {
				FOR(j, 0, n) {
					distances[i][j] = min(distances[i][j], distances[i][k] + distances[k][j]);
				}
			}
		}
		vector<vector<double>> times(n);
		FOR(i, 0, n) {
			times[i] = vector<double>(n);
		}
		FOR(i, 0, n) {
			FOR(j, 0, n) {
				if (i != j && distances[i][j] <= e[i]) {
					times[i][j] = (double)distances[i][j] / s[i];
				}
				else {
					times[i][j] = INF;
				}
			}
		}
		printf("Case #%d: ", test + 1);
		FOR(query, 0, q) {
			int u, v;
			scanf("%d%d", &u, &v);
			u--;
			v--;
			vector<double> t(n);
			vector<bool> visited(n);
			FOR(i, 0, n) {
				t[i] = INF;
				visited[i] = false;
			}
			t[u] = 0;
			FOR(i, 0, n) {
				double minTime = INF;
				int minCity = -1;
				FOR(j, 0, n) {
					if (!visited[j] && t[j] < minTime) {
						minTime = t[j];
						minCity = j;
					}
				}
				if (minCity == -1) {
					break;
				}
				FOR(j, 0, n) {
					t[j] = min(t[j], t[minCity] + times[minCity][j]);
				}
				visited[minCity] = true;
			}
			printf("%.9f ", t[v]);
		}
		printf("\n");
	}
}