#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;



struct rect {
	int x1, y1, x2, y2;
	rect() {

	}
	rect(int a, int b, int c, int d) {
		x1 = min(a, c);
		y1 = min(b, d);
		x2 = max(a, c);
		y2 = max(b, d);
	}
};

rect arr[200005];
rect p[200005];
rect s[200005];

rect intersect(rect x, rect y) {
	if (x.x1 == -INF - 1 || y.x1 == -INF - 1)
		return rect(-INF - 1, 0, 0, 0);
	int xl = max(x.x1, y.x1);
	int xr = min(x.x2, y.x2);
	int yl = max(x.y1, y.y1);
	int yr = min(x.y2, y.y2);
	if (xl > xr || yl > yr) {
		return rect(-INF - 1, 0, 0, 0);
	}
	return rect(xl, yl, xr, yr);
}

int main() {
	int n;
	cin >> n;
	FOR(i, 0, n) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
		arr[i] = rect(a, b, c, d);
	}
	p[0] = arr[0];
	FOR(i, 1, n) {
		p[i] = intersect(p[i - 1], arr[i]);
	}
	s[n - 1] = arr[n - 1];
	RFOR(i, n - 2, -1) {
		s[i] = intersect(s[i + 1], arr[i]);
	}
	rect ans = rect(-INF - 1, 0, 0, 0);
	if (s[1].x1 != -INF - 1) {
		ans = s[1];
	}
	if (p[n - 2].x1 != -INF - 1) {
		ans = p[n - 2];
	}
	FOR(i, 1, n - 1) {
		rect x = intersect(p[i - 1], s[i + 1]);
		if (x.x1 != -INF - 1) {
			ans = x;
		}
	}
	cout << ans.x1 << " " << ans.y1 << endl;
}
