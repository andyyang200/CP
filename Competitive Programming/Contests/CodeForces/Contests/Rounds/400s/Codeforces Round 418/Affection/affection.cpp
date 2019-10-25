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
int dp[26][1500][1505];
int maxdp[26][1505];
string s;
int n;
void calc(int x) {
	char c = 'a' + x;
	if (s[0] == c) {
		dp[x][0][0] = 1;
	}
	else {
		dp[x][0][0] = 0;
	}
	FOR(i, 1, n + 1) {
		dp[x][0][i] = 1;
	}
	FOR(i, 1, n) {
		FOR(j, 0, n + 1) {
			if (s[i] == c) {
				dp[x][i][j] = dp[x][i - 1][j] + 1;
			}
			else if (j > 0){
				dp[x][i][j] = dp[x][i - 1][j - 1] + 1;
			}
		}
	}
	FOR(i, 0, n) {
		FOR(j, 0, n + 1) {
			maxdp[x][j] = max(maxdp[x][j], dp[x][i][j]);
		}
	}
}
int main(void)
{
	cin >> n;
	cin >> s;
	FOR(i, 0, 26) {
		calc(i);
	}
	int q;
	cin >> q;
	FOR(i, 0, q) {
		int m;
		char c;
		cin >> m >> c;
		cout << maxdp[c - 'a'][m] << endl;
	}
}