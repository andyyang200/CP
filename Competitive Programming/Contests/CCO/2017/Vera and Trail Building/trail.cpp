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
	int k;
	cin >> k;
	if (k > 1000) {
		return 0;
	}
	int cur = 1;
	vector<pii> v;
	while (k > 0) {
		int l = 2;
		int r = 5000;
		int ans = -1;
		while (l <= r) {
			int mid = (l + r) >> 1;
			ll x = (ll)mid * (mid - 1) / 2;
			if (x <= k) {
				ans = mid;
				l = mid + 1;
			}
			else {
				r = mid - 1;
			}
		}
		if (cur > 1) {
			v.push_back({ cur, cur - 1});
		}
		FOR(i, 0, ans - 1) {
			v.push_back({ cur + i, cur + i + 1 });
		}
		v.push_back({ cur + ans - 1, cur});
		cur += ans;
		k -= ans * (ans - 1) / 2;
	}
	cout << cur - 1 << " " << v.size() << endl;
	for (pii x : v) {
		cout << x.first << " " << x.second << endl;
	}
}