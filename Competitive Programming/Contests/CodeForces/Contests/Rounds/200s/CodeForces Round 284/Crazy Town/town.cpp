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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;

struct road
{
	int a, b, c;
};

road roads[301];

bool CCW(double ax, double ay, double bx, double by, double cx, double cy)
{
	double sum = (bx - ax) * (cy - ay) - (by - ay) * (cx - ax);
	return sum > 0;
}

bool intersects(double ax, double ay, double bx, double by, double cx, double cy, double dx, double dy)
{
	if (CCW(ax, ay, cx, cy, dx, dy) == CCW(bx, by, cx, cy, dx, dy))
		return false;
	else if (CCW(ax, ay, bx, by, cx, cy) == CCW(ax, ay, bx, by, dx, dy))
		return false;
	return true;
}

int main()
{
	int x1, y1, x2, y2, n;
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	int count = 0;
	FOR(i, 0, n)
	{
		double a, b, c;
		cin >> a >> b >> c;
		double minX, maxX, minY, maxY;
		minX = -1000000000;
		maxX = 1000000000;

		if (b == 0)
		{
			minX = maxX = (0 - c) / a;
			minY = -1000000000;
			maxY = 1000000000;
		}
		else
		{
			minY = (0 - c - a * minX) / b;
			maxY = (0 - c - a * maxX) / b;
		}
		if (intersects(x1, y1, x2, y2, minX, minY, maxX, maxY))
		{
			count++;
		}
	}
	cout << count << endl;
}