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
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <climits>
#include <unordered_map>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
const double PI = 3.1415926;
typedef long long ll;
typedef pair<int, int> pii;

double slope(pii& a, pii& b) // returns slope of the line between two points
{
	if (a.first == b.first)
	{
		return INF;
	}
	return (double)(a.second - b.second) / (a.first - b.first);
}

ll getDistance(pii& a, pii& b) // return distance between two points
{
	return (ll)(b.first - a.first) * (b.first - a.first) + (ll)(b.second - a.second) * (b.second - a.second);
}

ll orientation(pii& a, pii& b, pii& c) // > 0 CCW, == 0 collinear, < 0 CW
{
	return (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
}

bool counterClockwise(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) > 0;
}

bool clockwise(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) < 0;
}

vector<pii> hull;
map<double, int> slopes;

pii pivot;
bool pointCompare(pii a, pii b)
{
	double m1 = slope(a, pivot);
	double m2 = slope(b, pivot);
	if (m1 == m2)
	{
		return getDistance(pivot, a) < getDistance(pivot, b);
	}
	return m1 < m2;
}

double getAngle(pii a, pii b)
{
	double angle = atan2(b.second - a.second, b.first - a.first) / PI * 180;
	if (angle < 0)
	{
		angle += 360;
	}
	return angle;
}

void getSlopes()
{
	slopes.clear();
	double previousAngle;
	FOR(i, 0, hull.size())
	{
		double angle = getAngle(hull[i], hull[(i + 1) % hull.size()]);
		slopes[angle] = i;
	}
}
vector<pii> getConvexHull(vector<pii> points, int n) // return convex hull of array of n points
{
	vector<pii> hull;
	swap(points[0], *min_element(points.begin(), points.end()));
	hull.push_back(points[0]);

	pivot = points[0];
	sort(points.begin(), points.end(), pointCompare);
	FOR(i, 1, n)
	{
		int j = hull.size() - 1;
		while (j > 0 && !counterClockwise(hull[j - 1], hull[j], points[i]))
		{
			j--;
		}
		hull.resize(j + 1);
		hull.push_back(points[i]);
	}
	return hull;
}

vector<pii> cows;
vector<pii> buffer;

// return 0 if some points are on line or on both side of the line
// 1 if whole hull on left
// 2 if whole hull on right

int testHull(ll a, ll b, ll c)
{
	double angle;
	if (b == 0)
	{
		angle = 90;
	}
	else
	{
		if (a > 0)
		{
			a = -a;
			b = -b;
			c = -c;
		}
		angle = atan2(-a, b) / PI * 180;
	}

	map<double, int> slopes;
	double previousAngle;
	FOR(i, 0, hull.size())
	{
		double angle = getAngle(hull[i], hull[(i + 1) % hull.size()]);
		slopes[angle] = i;
	}
	auto i = slopes.lower_bound(angle);
	if (i == slopes.end())
	{
		i = slopes.begin();
	}
	pii r = hull[i->second];
	angle += 180;
	i = slopes.lower_bound(angle);
	if (i == slopes.end())
	{
		i = slopes.begin();
	}
	pii l = hull[i->second];

	if (a * r.first + b * r.second - c == 0)
	{
		return 0;
	}
	if (a * l.first + b * l.second - c == 0)
	{
		return 0;
	}
	if ((a * r.first + b * r.second - c < 0) != (a * l.first + b * l.second - c < 0))
	{
		return 0;
	}

	if (a * r.first + b * r.second - c < 0) 
		return 2;
	return 1;
}

//bool test(ll a, ll b, ll c, vector<pii> h0, vector<vector<pii>> hulls)
//{
//	int r = testHull(a, b, c, h0);
//	if (r == 0) return false;
//	for(auto& h : hulls)
//	{
//		if (h.empty())
//			continue;
//		int rr = testHull(a, b, c, h);
//		if (rr == 0 || rr != r)
//			return false;
//	}
//	return true;
//}



int main()
{
	ios_base::sync_with_stdio(false);
	//freopen("fencing.in", "r", stdin);
	//freopen("fencing.out", "w", stdout);
	int n, q;
	cin >> n >> q;
	FOR(i, 0, n)
	{
		int x, y;
		cin >> x >> y;
		cows.push_back({ x, y });
	}
	/*vector<pii> h0 = getConvexHull(cows, n);
	vector<vector<pii>> hulls;
	vector<pii> xxx;
	hulls.push_back(xxx);*/
	FOR(i, 0, q)
	{
		int action;
		cin >> action;
		if (action == 1)
		{
			int x, y;
			cin >> x >> y;
			buffer.push_back({ x, y });
			//hulls[hulls.size()-1] = getConvexHull(buffer, buffer.size());
			if (buffer.size() == 500)
			{
				//hulls.push_back(xxx);
				for(pii p : buffer)
				{
					cows.push_back(p);
				}
				getConvexHull(cows, cows.size());
				buffer.clear();
			}
		}
		else
		{
			ll a, b, c;
			cin >> a >> b >> c;
			cout << (testHull(a, b, c) ? "YES" : "NO") << "\n";
		}
	}
	return 0;
}