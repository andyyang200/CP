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
typedef pair<ll, ll> pii;
int n, m, r, k;
map<pii, bool> visited;
struct point {
	int x, y, value;
	point(int a, int b) {
		x = a;
		y = b;
		int left = max(0, x - r + 1);
		int right = min(x, n - r);
		int up = max(0, y - r + 1);
		int down = min(y, m - r);
		value = (right - left + 1) * (down - up + 1);
	}
	bool operator<(const point o) const {
		return value > o.value;
	}
};
bool valid(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && !visited[{x, y}];
}
int main(void)
{
	cin >> n >> m >> r >> k;
	multiset<point> s;
	s.insert(point(n / 2, m / 2));
	visited[{n / 2, m / 2}] = true;
	double ans = 0;
	FOR(i, 0, k) {
		point p = *s.begin();
		s.erase(s.begin());
		ans += p.value;
		if (valid(p.x - 1, p.y)) {
			s.insert(point(p.x - 1, p.y));
			visited[{p.x - 1, p.y}] = true;
		}
		if (valid(p.x + 1, p.y)) {
			s.insert(point(p.x + 1, p.y));
			visited[{p.x + 1, p.y}] = true;
		}
		if (valid(p.x, p.y - 1)) {
			s.insert(point(p.x, p.y - 1));
			visited[{p.x, p.y - 1}] = true;
		}
		if (valid(p.x, p.y + 1)) {
			s.insert(point(p.x, p.y + 1));
			visited[{p.x, p.y + 1}] = true;
		}
	}
	ans /= (ll)((ll)n - r  + 1) * (ll)((ll)m - r + 1);
	printf("%.9f\n", ans);
}