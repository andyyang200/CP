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
#define M 123456789
typedef long long ll;
typedef pair<int, int> pii;
ll dp[1000001];
ll pdp[100001];
ll getsum(int a, int b) {
	ll ret = pdp[b];
	if (a > 0) {
		ret -= pdp[a - 1];
	}
	ret = (ret + M) % M;
	return ret;
}
int main(void)
{
	int l, s;
	scanf("%d%d", &l, &s);
	dp[0] = 1;
	pdp[0] = 1;
	FOR(i, 1, l) {
		dp[i] = getsum(max(0, i - s), i - 1);
		pdp[i] = (pdp[i - 1] + dp[i]) % M;
	}
	ll ans = 0;
	FOR(i, 1, s + 1) {
		ans += dp[l - i] * i % M;
		ans %= M;
	}
	cout << ans << endl;
}