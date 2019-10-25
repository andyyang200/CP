#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define ri(x) scanf("%d", &x)
#define ri2(x, y) scanf("%d%d", &x, &y)
#define ri3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define rll(x) scanf("%lld", &x)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

const ld EPS = 1e-8;


ld sq(ld x) {
    return x*x;
}

bool almost_equal(ld a, ld b) {
    if (a > b + EPS) return false;
    if (b > a + EPS) return false;
    return true;
}

/////////////// points and operations on them ////////////////////

typedef pair<ld,ld> Point;

Point midpoint(Point u, Point v) {
    return Point((u.first + v.first)/2, (u.second + v.second)/2);
}

ld dist_sq(Point u, Point v) {
    return sq(u.first-v.first) + sq(u.second-v.second);
}


///////////// vectors and operations on them ////////////////////

typedef pair<ld,ld> Vector;

Vector create_vector(Point u, Point w) {
    return Vector(w.first - u.first, w.second - u.second);
}

Vector perpendicular(Vector v) {
    return Vector(v.second,-v.first);
}

////////////// intersection of two lines

Point intersection(Point a, Vector va, Point b, Vector vb) {
    ld t = (a.first - b.first) * va.second - (a.second - b.second) * va.first;
    t /= vb.first * va.second - vb.second * va.first;
    return Point(b.first + t * vb.first, b.second + t * vb.second);
}

//////////// circles

struct Circle {
    Point center;
    ld r_sq;

    bool contains(Point p) {
	return dist_sq(center,p) <= r_sq + EPS;
    }

    void verify_on_the_circle(Point p) {
	if (!almost_equal(dist_sq(p,center),r_sq)) {
	    printf("ERROR: point not on a circle!!!\n");
	    exit(1);
	}
    }

    Circle(Point c, Point b) {
	center = c;
	r_sq = dist_sq(c,b);
    }

    Circle() {}
};


/////////// circle on given points

Circle circumcircle(const vector<Point> &p, int k) {
    Circle solution;
    if (k<0) {
	printf("Error: circle on <0 points\n");
	exit(1);
    } else if (k==0) {
	solution = Circle(Point(0,0),Point(0,0));
    } else if (k==1) {
	solution = Circle(p[0],p[0]);
    } else if (k==2) {
	solution = Circle(midpoint(p[0],p[1]),p[0]);
    } else if (k==3) {
	Point m1 = midpoint(p[0],p[1]);
	Vector v1 = perpendicular(create_vector(p[0],p[1]));
	Point m2 = midpoint(p[1],p[2]);
	Vector v2 = perpendicular(create_vector(p[1],p[2]));
	solution = Circle(intersection(m1,v1,m2,v2), p[0]);
    } else {
	printf("Error: circle on >3 points\n");
	exit(1);
    }
    FOR(i, 0, k) solution.verify_on_the_circle(p[i]);
    return solution;
}

Circle find_circle(vector<Point> &points, int known, int length) {
    Circle c = circumcircle(points, known);
    FOR(i, known, length) {
        int random_index = i + rand() % (length - i);
        swap(points[i], points[random_index]);
        if (not c.contains(points[i])) {
            swap(points[known],points[i]);
            c = find_circle(points, known + 1, i + 1);
        }
    }
    return c;
}

int main() {
    srand(12345);
	vector<Point> points;

	int n;
	ri(n);

	FOR(i, 0, n) {
	    int a, b;
	    ri2(a, b);
	    points.push_back(Point(a, b));
	}
	Circle all = find_circle(points,0, points.size());
	cout << fixed << setprecision(9) << sqrt(all.r_sq) << endl;
}
