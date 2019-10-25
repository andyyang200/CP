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
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
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
vector<pii> getConvexHull(vector<pii> points, int n) // return convex hull of array of n points
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
	sort(points.begin(), points.end(), pointCompare);
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
vector<pair<vector<pii>, int> > hulls;
vector<int> counts;
int getDis(pii& a, pii& b)
{
	return abs(a.second - b.second) + abs(a.first - b.first);
}
void rebuild(int a)
{
	if (hulls[a].second >= 500)
	{
		getConvexHull(hulls[a].first, hulls[a].second);
		hulls[a].first = hull;
		hulls[a].second = 0;
	}
}
void merge(int a, int b)
{
	FOR(i, 0, hulls[b].first.size())
	{
		hulls[a].first.push_back(hulls[b].first[i]);
	}
	hulls[a].second += hulls[b].second;
	counts[a] += counts[b];
	hulls.erase(hulls.begin() + b);
	counts.erase(counts.begin() + b);
}

int main()
{
	//freopen("nabor.in", "r", stdin);
	//freopen("nabor.out", "w", stdout);
	int n, c;
	scanf("%d%d", &n, &c);
	FOR(i, 0, n)
	{
		pii p;
		scanf("%d%d", &p.first, &p.second);
		vector<int> inside;
		FOR(j, 0, hulls.size())
		{
			bool found = false;
			FOR(k, 0, hulls[j].first.size())
			{
				if (getDis(p, hulls[j].first[k]) <= c)
				{	
					found = true;
					break;
				}
			}
			if (found)
			{
				inside.push_back(j);
			}
		}
		RFOR(j, inside.size() - 1, 0)
		{
			merge(j - 1, j);
		}
		if (inside.size() >= 1)
		{
			hulls[inside[0]].first.push_back(p);
			hulls[inside[0]].second++;
			counts[inside[0]]++;
			rebuild(inside[0]);
		}
		else
		{
			vector<pii> newHull;
			newHull.push_back(p);
			hulls.push_back(make_pair(newHull, 1));
			counts.push_back(1);
		}
	}
	int maxGroup = 0;
	FOR(i, 0, counts.size())
	{
		maxGroup = max(maxGroup, counts[i]);
	}
	cout << hulls.size() << " " << maxGroup << endl;
}