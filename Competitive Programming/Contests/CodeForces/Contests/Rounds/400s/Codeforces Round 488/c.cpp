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
	return (counterClockwise(a, c, d) != counterClockwise(b, c, d)) && (counterClockwise(a, b, c) != counterClockwise(a, b, d));
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

int intersectPolygonCount(pii& a, pii& b, pii* p) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        pii c = p[i];
        pii d = p[(i + 1) % 4];
        if (intersects(a, b, c, d)) {
            cnt++;
        }
    }
    return cnt;
}
bool inPolygon(pii& a, pii* p) {
    pii b;
    b.first = a.first + 1;
    b.second = a.second + 1000000000;
    return intersectPolygonCount(a, b, p) % 2 == 1;
}
bool polygonsIntersect(pii* p1, pii* p2) {
    for (int i = 0; i < 4; i++) {
        pii a = p1[i];
        pii b = p1[(i + 1) % 4];
        if (intersectPolygonCount(a, b, p2) > 0) {
            return true;
        }
    }
    FOR(i, 0, 4){
        FOR(j, 0, 4){
            if (onSegment(p1[i], p2[j], p2[(j + 1) % 4]) || onSegment(p2[i], p1[j], p1[(j + 1) % 4])){
                return true;
            }
        }
    }
    return inPolygon(p1[0], p2) || inPolygon(p2[0], p1);
}

int main(void)
{
    pii a, b, c, d, e, f, g, h;
    cin >> a.first >> a.second >> b.first >> b.second >> c.first >> c.second >> d.first >> d.second;
    cin >> e.first >> e.second >> f.first >> f.second >> g.first >> g.second >> h.first >> h.second;
    pii p1[] = {a, b, c, d};
    pii p2[] = {e, f, g, h};
    if (polygonsIntersect(p1, p2)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}

