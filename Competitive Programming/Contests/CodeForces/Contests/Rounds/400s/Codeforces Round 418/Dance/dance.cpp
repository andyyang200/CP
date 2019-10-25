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
#include <math.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int x[1005];
int y[1005];
int r[1005];
double value[1005];
double PI = atan(1) * 4;
int cnt[1005];
ll getDistance(int i, int j) {
	ll dx = abs(x[i] - x[j]);
	ll dy = abs(y[i] - y[j]);
	return dx * dx + dy * dy;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d%d%d", &x[i], &y[i], &r[i]);
	}
	FOR(i, 0, n) {
		FOR(j, 0, n) {
			if (getDistance(i, j) <= (ll)r[j] * r[j] && r[j] > r[i]) {
				cnt[i]++;
			}
		}
	}
	double ans = 0;
	FOR(i, 0, n) {
		if (cnt[i] == 0 || cnt[i] % 2 == 1) {
			ans += (double)r[i] * r[i] * PI;
		}
		else {
			ans -= (double)r[i] * r[i] * PI;
		}
	}
	printf("%.15f\n", ans);
}