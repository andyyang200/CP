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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

pii points[1005];
int direction[1005];
double orientation(pair<double, double>& a, pair<double, double>& b, pair<double, double>& c) // > 0 CCW, == 0 collinear, < 0 CW
{
	return (b.first - a.first) * (c.second - a.second) - (ll)(b.second - a.second) * (c.first - a.first);
} // (x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1)
bool counterClockwise(pair<double, double>& a, pair<double, double>& b, pair<double, double>& c)
{
	return orientation(a, b, c) > 0;
}
bool intersects(pair<double, double> a, pair<double, double> b, pair<double, double> c, pair<double, double> d)
{
	return (counterClockwise(a, c, d) != counterClockwise(b, c, d)) && (counterClockwise(a, b, c) != counterClockwise(a, b, d));
}
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n + 1)
	{
		scanf("%d%d", &points[i].first, &points[i].second);
	}
	points[n + 1] = points[1];
	FOR(i, 0, n + 1)
	{
		int x1 = points[i].first;
		int y1 = points[i].second;
		int x2 = points[i + 1].first;
		int y2 = points[i + 1].second;
		if (x1 == x2 && y1 < y2)
		{
			direction[i] = 1;
		}
		else if (x1 == x2 && y1 > y2)
		{
			direction[i] = 3;
		}
		else if (y1 == y2 && x1 < x2)
		{
			direction[i] = 2;
		}
		else if (y1 == y2 && x1 > x2)
		{
			direction[i] = 4;
		}
	}
	pair<double, double> x = { points[0].first + 0.5, points[0].second + 0.5 };
	int intersections = 0;
	FOR(i, 0, n)
	{
		if (intersects(x, { x.first + 1, INF }, (pair<double, double>)points[i], (pair<double, double>)points[i + 1]))
		{
			intersections++;
		}
	}
	int lake;
	if (intersections % 2 == 1)
	{
		lake = 2;
	}
	else
	{
		lake = 4;
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		if (direction[i] == 1)
		{
			if (direction[i + 1] == 2)
			{
				if (lake == 2)
				{
					lake = 3;
				}
				else
				{
					ans++;
					lake = 1;
				}
			}
			else
			{
				if (lake == 4)
				{
					lake = 3;
				}
				else
				{
					ans++;
					lake = 1;
				}
			}
		}
		if (direction[i] == 3)
		{
			if (direction[i + 1] == 2)
			{
				if (lake == 2)
				{
					lake = 1;
				}
				else
				{
					ans++;
					lake = 3;
				}
			}
			else
			{
				if (lake == 4)
				{
					lake = 1;
				}
				else
				{
					ans++;
					lake = 3;
				}
			}
		}
		if (direction[i] == 2)
		{
			if (direction[i + 1] == 1)
			{
				if (lake == 1)
				{
					lake = 4;
				}
				else
				{
					ans++;
					lake = 2;
				}
			}
			else
			{
				if (lake == 3)
				{
					lake = 4;
				}
				else
				{
					ans++;
					lake = 2;
				}
			}
		}
		if (direction[i] == 4)
		{
			if (direction[i + 1] == 1)
			{
				if (lake == 1)
				{
					lake = 2;
				}
				else
				{
					ans++;
					lake = 4;
				}
			}
			else
			{
				if (lake == 3)
				{
					lake = 2;
				}
				else
				{
					ans++;
					lake = 4;
				}
			}
		}
	}
	cout << ans << endl;
}