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
int cur[50];
int a[100005];
int n;
ll getValue() {
	ll ans = 0;
	ll power = 1;
	FOR(i, 0, 35) {
		if (cur[i] > 0) {
			ans += power;
		}
		power *= 2;
	}
	return ans;
}
int main(void)
{
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	ll ans = 0;
	FOR(i, 0, n) {
		ans |= a[i];
	}
	if (ans == 0) {
		cout << 1 << endl;
		return 0;
	}
	int j = -1;
	int ret = n;
	FOR(i, 0, n) {
		while (getValue() < ans && j < n - 1) {
			j++;
			FOR(k, 0, 35) {
				if (((ll)1 << k) & a[j]) {
					cur[k]++;
				}
			}
		}
		if (getValue() == ans) {
			ret = min(ret, j - i + 1);
		}
		FOR(k, 0, 35) {
			if (((ll)1 << k) & a[i]) {
				cur[k]--;
			}
		}
	}
	cout << ret << endl;
}