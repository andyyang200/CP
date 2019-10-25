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
int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int a[100005];
int b[100005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	FOR(i, 0, n) {
		scanf("%d", &b[i]);
		if (b[i] > a[i]) {
			cout << -1 << endl;
			return 0;
		}
	}
	int ans = 0;
	int d = 0;
	FOR(i, 0, n) {
		int x = a[i] - b[i];
		ans = gcd(ans, x);
		d = max(d, b[i]);
	}
	if (ans == 0) {
		cout << d + 1 << endl;
		return 0;
	}


	if (ans <= d) {
		cout << -1 << endl;
		return 0;
	}
	int ret = ans;
	for (int i = 1; i * i <= ans; i++) {
		if (ans % i == 0) {
			if (i > d)
				ret = min(ret, i);
			if (ans / i > d)
				ret = min(ret, ans / i);
		}
	}
	assert(ret > d);
	assert(ans % ret == 0);
	FOR(i, 0, n) {
		assert(a[i] % ret == b[i]);
	}
	cout << ret << endl;

}