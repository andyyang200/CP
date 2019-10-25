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

/*
You have a lamp with M levels of brightness. It has two buttons:
one sets the brightness to X, and the other increases the brightness by 1 (cycling down to 1
after M).

You have an array A of length N. The initial brightness of the lamp is A0, and you want to change the
brightness to A1, then A2, and so on. If you can choose X, what is the minimum number of times you need
to press a button?
*/













int a[100005];
ll dt[100005];
int dc[100005];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	int c = 0;
	FOR(i, 0, n - 1) {
		if (a[i] + 1 < a[i + 1]) {
			dc[a[i] + 1]++;
			dc[a[i + 1]]--;
			dt[a[i + 1] + 1] += a[i + 1] - a[i] - 1;
		}
		else if (a[i + 1] < a[i] && (a[i] + 1 % m) != a[i + 1]) {
			dc[(a[i] + 1) % m]++;
			dc[a[i + 1]]--;
			dt[a[i + 1] + 1] += a[i + 1] - a[i] + m - 1;
			if (a[i + 1] > 1) {
				c++;
			}
		}
	}
	int x = 1;
	ll t = 0;
	FOR(i, 0, n - 1) {
		t += min((a[i + 1] - a[i] + m) % m, (a[i + 1] - x + m) % m + 1);
	}
	ll ans = t;
	FOR(i, 2, m + 1) {
		t -= c;
		c += dc[i];
		t += dt[i];
		ans = min(ans, t);
	}
	cout << ans << endl;
}