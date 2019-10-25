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
int first[100];
int last[100];
char grid[100][100];
int dp[100][2];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	m += 2;
	FOR(i, 0, n) {
		first[i] = 0;
		last[i] = 0;
		FOR(j, 0, m) {
			cin >> grid[i][j];
			if (grid[i][j] == '1') {
				first[i] = max(first[i], j);
				last[i] = max(last[i], m - 1 - j);
			}
		}
	}
	int start = -1;
	FOR(i, 0, n) {
		if (first[i] != 0) {
			start = i;
			break;
		}
	}
	if (start == -1) {
		cout << 0 << endl;
		return 0;

	}
	dp[start][0] = first[start];
	dp[start][1] = last[start];
	FOR(i, start + 1, n) {
		dp[i][0] = min(dp[i - 1][0] + 2 * first[i] + 1, dp[i - 1][1] + m - 1 + 1);
		dp[i][1] = min(dp[i - 1][1] + 2 * last[i] + 1, dp[i - 1][0] + m - 1 + 1);
	}
	cout << dp[n - 1][0] << endl;
}