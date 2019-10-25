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
int a[100005];
ll p[100005];
ll dp[100005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
		p[a[i]] += a[i];
	}

	dp[0] = p[0];
	dp[1] = max(p[0], p[1]);
	FOR(i, 2, 100005) {
		dp[i] = max(dp[i - 2] + p[i], dp[i - 1]);
	}
	cout << dp[100004] << endl;

}