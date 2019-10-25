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
int a[100005];
int main(void)
{
	int n, s;
	scanf("%d%d", &n, &s);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	int l = 0;
	int r = n;
	int ans = 0;
	int minCost = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		vector<ll> cost(n);
		FOR(i, 0, n) {
			cost[i] = (ll)a[i] + (ll)(i + 1) * mid;
		}
		sort(cost.begin(), cost.end());
		ll used = 0;
		FOR(i, 0, mid) {
			used += cost[i];
		}
		if (used <= s) {
			ans = mid;
			minCost = used;	
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans << " ";
	cout << minCost << endl;
}