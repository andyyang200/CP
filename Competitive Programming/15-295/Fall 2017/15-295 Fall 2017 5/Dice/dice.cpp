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
vector<int> a[7];
int dp[10005][7];
int main(void)
{
	FOR(i, 1, 7) {
		FOR(j, 1, 7) {
			if (j != i && i + j != 7) {
				a[i].push_back(j);
			}
		}
	}
	int t;
	scanf("%d", &t);
	FOR(asd, 0, t) {
		int n;
		scanf("%d", &n);
		FOR(i, 0, n + 1) {
			FOR(j, 1, 7) {
				dp[i][j] = INF;
			}
		}
		dp[0][1] = 0;
		FOR(i, 1, n + 1) {
			FOR(j, 1, 7) {
				FOR(k, 0, 4) {
					int side = a[j][k];
					if (i - j >= 0) {
						dp[i][j] = min(dp[i][j], dp[i - j][side] + 1);
					}
				}
			}
		}
		int ans = INF;
		FOR(i, 1, 7) {
			ans = min(ans, dp[n][i]);
		}
		if (ans == INF) {
			cout << -1 << endl;
		}
		else {
			cout << ans << endl;
		}
	}
}
/*
2
5
10
*/