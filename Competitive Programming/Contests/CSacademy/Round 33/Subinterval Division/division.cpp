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
#define EPS 1e-9
typedef long long ll;
typedef pair<int, int> pii;
struct point {
	int x, y, i;
	bool operator<(point p) {
		return x < p.x;
	}
};
point s[100005];
bool done[100005];
double l[100005];
double r[100005];
double ans[100005];
map<int, set<int>> m;
int n, x;
bool equal(double a, double b) {
	return abs(a - b) < EPS;
}
double dis(pair<double, double> i, pair<double, double> j) {
	double dx = abs(j.first - i.first);
	double dy = abs(j.second - i.second);
	return dx * dx + dy * dy;
}
double get(pii i, pii j) { // i < j
	double l = 0;
	double r = x;
	double m;
	FOR(asd, 0, 100) {
		m = (l + r) / 2;
		double a = dis(i, { m, 0 });
		double b = dis(j, { m, 0 });
		if (a < b) {
			l = m;
		}
		else {
			r = m;
		}
	}
	return m;
}
double get(int i, int j) {
	return get({ s[i].x, s[i].y }, { s[j].x, s[j].y });
}
int main(void)
{
	cin >> n >> x;
	FOR(i, 0, n) {
		cin >> s[i].x >> s[i].y;
		s[i].i = i;
		m[s[i].x].insert(s[i].y);
	}
	FOR(i, 0, n) {
		if (*(m[s[i].x].begin()) < s[i].y) {
			done[i] = true;
		}
	}
	sort(s, s + n);
	int leftBound = -1;
	FOR(i, 0, n) {
		if (done[i]) {
			continue;
		}
		l[i] = x;
		if (leftBound == -1) {
			l[i] = 0;
			leftBound = i;
		}
		else {
			l[i] = get(leftBound, i);
			if (!equal(l[i], x)) {
				leftBound = i;
			}
		}
	}
	int rightBound = n;
	RFOR(i, n - 1, -1) {
		if (done[i]) {
			continue;
		}
		r[i] = 0;
		if (rightBound == n) {
			r[i] = x;
			rightBound = i;
		}
		else {
			r[i] = get(i, rightBound);
			if (!equal(r[i], 0)) {
				rightBound = i;
			}
		}
	}
	FOR(i, 0, n) {
		if (done[i]) {
			continue;
		}
		if (l[i] <= r[i]) {
			ans[s[i].i] = r[i] - l[i];
		}
	}
	FOR(i, 0, n) {
		printf("%.9f\n", ans[i]);
	}
}