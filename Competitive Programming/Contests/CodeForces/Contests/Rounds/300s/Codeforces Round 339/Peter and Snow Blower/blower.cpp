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
pii points[100001];
double getDistance(pair<double, double> a, pair<double, double> b)
{
	return sqrt((double)abs(b.first - a.first) * abs(b.first - a.first) + (double)abs(b.second - a.second) * abs(b.second - a.second));
}
double getDistance(pii p, pii a, pii b)
{
	double m1, m2, b1, b2, x, y;
	m1 = (double)(b.second - a.second) / (b.first - a.first);
	if (m1 == 0)
	{
		x = p.first;
		y = a.second;
	}
	else if (b.first == a.first)
	{
		x = a.first;
		y = p.second;
	}
	else
	{
		m2 = -1 / m1;
		b1 = (double)a.second - m1 * a.first;
		b2 = (double)p.second - m2 * p.first;
		x = (b2 - b1) / (m1 - m2);
		y = m1 * x + b1;
	}
	if (x <= max(a.first, b.first) && x >= min(a.first, b.first) && y <= max(b.second, a.second) && y >= min(b.second, a.second))
	{
		int xsd = getDistance(p, { x, y });
		return getDistance(p, { x, y });
	}
	else
	{
		return min(getDistance(p, a), getDistance(p, b));
	}
}
int main()
{
	double R = 0;
	double r = INF;
	pii p;
	int n;
	scanf("%d%d%d", &n, &p.first, &p.second);
	FOR(i, 0, n)
	{
		scanf("%d%d", &points[i].first, &points[i].second);
		R = max(R, getDistance(points[i], p));
	}
	FOR(i, 0, n - 1)
	{
		r = min(r, getDistance(p, points[i], points[i + 1]));
	}
	r = min(r, getDistance(p, points[0], points[n - 1]));
	printf("%.9f\n", 3.14159265358979323846 * (R * R - r * r));
}