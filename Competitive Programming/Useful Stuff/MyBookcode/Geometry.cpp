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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;
#define INF 1000000000


ll getDistance(pii& a, pii& b) // return distance between two points
{
	return (ll)(b.first - a.first) * (b.first - a.first) + (ll)(b.second - a.second) * (b.second - a.second);
}

ll orientation(pii& a, pii& b, pii& c) // > 0 CCW, == 0 collinear, < 0 CW
{
	return (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
} // (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
bool counterClockwise(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) > 0;
}
bool clockwise(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) < 0;
}
bool collinear(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) == 0;
}

bool intersects(pii& a, pii& b, pii& c, pii& d) // does not count intersection at endpoints
{
	return (counterClockwise(a, c, d) != counterClockwise(b, c, d)) && (counterClockwise(c, a, b) != counterClockwise(d, a, b));
}

bool onSegment(pii& a, pii& b, pii& c) // is a on segment bc
{
	if (orientation(a, b, c) == 0)
	{
		if (min(b.first, c.first) <= a.first && max(b.first, c.first) >= a.first)
		{
			if (min(b.second, c.second) <= a.second && max(b.second, c.second) >= a.second)
			{
				return true;
			}
		}
	}
	return false;
}


//convex hull
double slope(pii& a, pii& b) // returns slope of the line between two points
{
	if (a.first == b.first)
	{
		return INF;
	}
	return (double)(a.second - b.second) / (a.first - b.first);
}
vector<pii> hull;
bool pointCompare(pii a, pii b)
{
	double m1 = slope(hull[0], a);
	double m2 = slope(hull[0], b);
	if (m1 == m2)
	{
		return getDistance(hull[0], a) < getDistance(hull[0], b);
	}
	return m1 < m2;
}
vector<pii> getConvexHull(pii* points, int n) // return convex hull of array of n points
{
	hull.clear();
	pii start(INF, INF);
	FOR(i, 0, n)
	{
		if (points[i] < start)
		{
			start = points[i];
		}
	}
	hull.push_back(start);
	sort(points, points + n, pointCompare);
	FOR(i, 0, n)
	{
		if (points[i] == hull[0])
		{
			continue;
		}
		while (hull.size() > 1 && !counterClockwise(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
		{
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
	hull.push_back(hull[0]);
	return hull;
}
// end convex hull

int intersectPolygonCount(pii& a, pii& b, pii* p, int n) {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        pii c = p[i];
        pii d = p[(i + 1) % n];
        if (intersects(a, b, c, d)) {
            cnt++;
        }
    }
    return cnt;
}
bool inPolygon(pii& a, pii* p, int n) {
    pii b;
    b.first = a.first + 1;
    b.second = a.second + 1000000000;
    return intersectPolygonCount(a, b, p, n) % 2 == 1;
}
bool polygonsIntersect(pii* p1, int n1, pii* p2, int n2) { // slow
    for (int i = 0; i < n1; i++) {
        pii a = p1[i];
        pii b = p1[(i + 1) % 4];
        if (intersectPolygonCount(a, b, p2) > 0) {
            return true;
        }
    }
    FOR(i, 0, n1){
        FOR(j, 0, n2){
            if (onSegment(p1[i], p2[j], p2[(j + 1) % n2]) || onSegment(p2[i], p1[j], p1[(j + 1) % n1])){
                return true;
            }
        }
    }
    return inPolygon(p1[0], p2) || inPolygon(p2[0], p1);
}



