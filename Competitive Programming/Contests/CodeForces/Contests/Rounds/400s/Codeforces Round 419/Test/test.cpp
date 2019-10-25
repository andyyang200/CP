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
int symbol[1000][1000];
int used[1000];
int dp[1000][1000];
int main(void)
{
	int n;
	cin >> n;
	int s = 1;
	FOR(i, 1, n) {
		FOR(j, 0, n - i) {
			symbol[i][j] = s;
			s *= -1;
		}
	}
	FOR(x, 0, n) {
		FOR(i, 0, n) {
			FOR(j, 0, n - i) {
				dp[i][j] = 0;
			}
		}
		dp[0][x] = 1;
		FOR(i, 1, n) {
			FOR(j, 0, n - 1) {
				dp[i][j] = dp[i - 1][j] + symbol[i][j] * dp[i - 1][j + 1];
			}
		}
		cout << dp[n - 1][0] << " ";
	}
	cout << endl;
}