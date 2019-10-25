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
struct point
{
	int x, y;
	ll d1, d2;
};
point points[2001];
ll getDistance(int a, int b, int c, int d)
{
	return (ll)abs(c - a) * abs(c - a) + (ll)abs(d - b) * abs(d - b);
}
int main()
{
	int n, x1, y1, x2, y2;
	scanf("%d%d%d%d%d", &n, &x1, &y1, &x2, &y2);
	FOR(i, 0, n)
	{
		scanf("%d%d", &points[i].x, &points[i].y);
		points[i].d1 = getDistance(points[i].x, points[i].y, x1, y1);
		points[i].d2 = getDistance(points[i].x, points[i].y, x2, y2);
	}
	if (n == 1)
	{
		cout << min(points[0].d1, points[0].d2) << endl;
		return 0;
	}
	ll ans = -1;
	FOR(i, 0, n)
	{
		ll r1 = points[i].d1;
		ll r2 = 0;
		FOR(j, 0, n)
		{
			if (points[j].d1 > r1)
			{
				r2 = max(r2, points[j].d2);
			}
		}
		if (ans < 0)
		{
			ans = r1 + r2;
		}
		else
		{
			ans = min(ans, r1 + r2);
		}
		r2 = points[i].d2;
		r1 = 0;
		FOR(j, 0, n)
		{
			if (points[j].d2 > r2)
			{
				r1 = max(r1, points[j].d1);
			}
		}
		if (ans < 0)
		{
			ans = r1 + r2;
		}
		else
		{
			ans = min(ans, r1 + r2);
		}
	}
	cout << ans << endl;
}