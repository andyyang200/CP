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
struct segment {
	int x1, y1, x2, y2;
	segment(int a, int b, int c, int d) {
		if (c < a) {
			swap(a, c);
			swap(b, d);
		}
		x1 = a;
		y1 = b;
		x2 = c;
		y2 = d;
	}
};
int getm(segment a) {
	if (a.x2 == a.x1) {
		return 1;
	}
	return (a.y2 - a.y1) / (a.x2 - a.x1);
}
int getb(segment a) {
	return a.y1 - getm(a) * a.x1;
}
bool online(int x, int y, segment a) {
	int m = getm(a);
	int b = getb(a);
	if (x * m + b != y) {
		return false;
	}
	if (x >= min(a.x1, a.x2) && x <= max(a.x1, a.x2) && y >= min(a.y1, a.y2) && y <= max(a.y1, a.y2)) {
		return true;
	}
	return false;
}
vector<segment> segments;
segment intersect(segment a, segment b) {
	if (getm(a) == getm(b)) { // same slope
		if (getb(a) == getb(b)) {
			int x1 = max(a.x1, b.x1);
			int x2 = min(a.x2, b.x2);
			if (x1 > x2) {
				return segment(INF, INF, INF, INF);
			}
			return segment(x1, getm(a) * x1 + getb(a), x2, getm(a) * x2 + getb(a));
		}
		else {
			return segment(INF, INF, INF, INF);
		}
	}
	else { // not same slope
		int b1 = getb(a);
		int b2 = getb(b);
		int m1 = getm(a);
		int m2 = getm(b);
		int x = (b2 - b1) / (m1 - m2);
		int y = m1 * x + b1;
		if (online(x, y, a) && online(x, y, b)) {
			return segment(x, y, x, y);
		}
		else {
			return segment(INF, INF, INF, INF);
		}
	}


}
int main(void)
{
	int n;
	cin >> n;
	int x, y, d;
	scanf("%d%d%d", &x, &y, &d);
	segments.push_back(segment(x, y + d, x + d, y));
	segments.push_back(segment(x + d, y, x, y - d));
	segments.push_back(segment(x, y - d, x - d, y));
	segments.push_back(segment(x - d, y, x, y + d));
	FOR(aldskjfh, 1, n) {
		scanf("%d%d%d", &x, &y, &d);
		vector<segment> temp;
		temp.push_back(segment(x, y + d, x + d, y));
		temp.push_back(segment(x + d, y, x, y - d));
		temp.push_back(segment(x, y - d, x - d, y));
		temp.push_back(segment(x - d, y, x, y + d));

		vector<segment> nw;
		FOR(i, 0, segments.size()) {
			bool change = false;
			for (segment a : temp) {
				segment b = intersect(segments[i], a);
				if (b.x1 != INF) {
					nw.push_back(b);
				}
			}
		}
		segments = nw;
	}
	if (segments.size() == 0) {
		cout << "impossible" << endl;
		return 0;
	}
	for (segment a : segments) {
		if (a.x1 != a.x2 || a.y1 != a.y2) {
			cout << "uncertain" << endl;
			return 0;
		}
	}
	FOR(i, 0, segments.size() - 1) {
		if (segments[i].x1 != segments[i + 1].x1 || segments[i].x2 != segments[i + 1].x2 || segments[i].y1 != segments[i + 1].y1 || 
			segments[i].y2 != segments[i + 1].y2 ) {
			cout << "uncertain" << endl;
			return 0;
		}
	}
	cout << segments[0].x1 << " " << segments[0].y1 << endl;
}
/*
2
0 0 1
2 0 1

*/



/*
2
100 0 101
0 200 199
*/

/*
2 
100 0 100
0 200 199
*/

/*
2
0 0 5
10 0 6
*/