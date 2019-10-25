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
typedef long double ld;
typedef pair<ll, ll> pii;
ll x[1000];
ll y[1000];
ll orientation(pii& a, pii& b, pii& c) // > 0 CCW, == 0 collinear, < 0 CW
{
	return (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
}
bool ccw(pii a, pii b, pii c)
{
	return orientation(a, b, c) >= 0;
}
int main(void)
{
	ll n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> x[i] >> y[i];
	}
	ld ans = INF;
	FOR(i, 0, n) {
		FOR(j, i + 1, n) {
			bool bad = false;
			FOR(k, 0, n - 1) {
				if (ccw({ x[i], y[i] }, { x[j], y[j] }, { x[k], y[k] }) != ccw({ x[i], y[i] }, { x[j], y[j] }, { x[k + 1], y[k + 1] })) {
					bad = true;
					break;
				}
			}
			ld m = 0;
			ll a = y[i] - y[j];
			ll b = x[j] - x[i];
			if (a == 0 && b == 0) continue;
			ll c = x[i] * y[j] - x[j] * y[i];
			if (!bad) {
				FOR(k, 0, n) {
					ld d = (ld)(a * x[k] + b * y[k] + c) / sqrt(a * a + b * b);
					if (d < 0) 
						d *= -1;
					m = max(m, d);
				}
				ans = min(ans, m);
			}
		}
	}
	printf("%.9Lf\n", ans);

}
/*
4
0 0
5 0
5 2
0 2
*/