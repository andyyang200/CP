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
#define MYINF 100000
typedef long long ll;
typedef pair<int, int> pii;

int n;
pii teamA[50000];
pii teamB[50000];
vector<pii> hull;

double slope(pii& a, pii& b)
{
	if (a.first == b.first)
	{
		return MYINF;
	}
	return (double)(a.second - b.second) / (a.first - b.first);
}

ll d(pii& a, pii& b)
{
	return (ll)(b.first - a.first) * (b.first - a.first) + (ll)(b.second - a.second) * (b.second - a.second);
}

bool pointCompare(pii a, pii b)
{
	double m1 = slope(hull[0], a);
	double m2 = slope(hull[0], b);
	if (m1 == m2)
	{
		return d(hull[0], a) < d(hull[0], b);
	}
	return m1 < m2;
}

ll orientation(pii& a, pii& b, pii& c) // > 0 CCW, == 0 collinear, < 0 CW
{
	return (ll)(b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
}

bool CCW(pii& a, pii& b, pii& c)
{
	return orientation(a, b, c) > 0;
}

bool onLine(pii& a, pii& b, pii& c) // return a on line bc
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

bool intersects(pii& a, pii& b, pii& c, pii& d)
{
	return (CCW(a, c, d) != CCW(b, c, d)) && (CCW(a, b, c) != CCW(a, b, d));
}

void getHull(pii* points)
{
	hull.clear();
	pii start(MYINF, MYINF);
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
		while (hull.size() > 1 && !CCW(hull[hull.size() - 2], hull[hull.size() - 1], points[i]))
		{
			hull.pop_back();
		}
		hull.push_back(points[i]);
	}
	hull.push_back(hull[0]);
}

bool insideHull(pii& point)
{
	pii next(point.first + 1, MYINF);
	int count = 0;
	FOR(i, 0, hull.size() - 1)
	{
		if (onLine(point, hull[i], hull[i + 1]))
		{
			return true;
		}
		else if (intersects(point, next, hull[i], hull[i + 1]))
		{
			count++;
			if (count == 2)
			{
				break;
			}
		}
	}
	return (count == 1 ? true : false);
}

int solve(pii* a, pii* b)
{
	getHull(a);
	int score = 0;
	FOR(i, 0, n)
	{
		if (insideHull(b[i]))
		{
			score++;
		}
	}
	return score;
}

int main()
{
	freopen("curling.in", "r", stdin);
	freopen("curling.out", "w", stdout);
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &teamA[i].first, &teamA[i].second);
	}
	FOR(i, 0, n)
	{
		scanf("%d%d", &teamB[i].first, &teamB[i].second);
	}
	cout << solve(teamA, teamB) << " " << solve(teamB, teamA) << endl;
} 