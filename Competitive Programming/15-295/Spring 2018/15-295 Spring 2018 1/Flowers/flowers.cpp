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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
ll dp[200010];
ll p[100005];

int main(void)
{
	int t, k;
	cin >> t >> k;
	dp[1] += 1;
	dp[k] += 1;
	FOR(i, 1, 100005) {
		dp[i + 1] += dp[i];
		dp[i + 1] %= M; 
		dp[i + k] += dp[i];
		dp[i + k] %= M;
	}
	p[0] = 0;
	FOR(i, 1, 100005) {
		p[i] = p[i - 1] + dp[i];
		p[i] %= M;
	}
	FOR(i, 0, t) {
		int a, b;
		cin >> a >> b;
		ll ans = p[b];
		ans -= p[a - 1];
		ans += M;
		ans %= M;
		cout << ans << endl;
	}
}