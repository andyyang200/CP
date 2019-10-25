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
pii sharks[100001];
int nump[100001];
int main()
{
	int n;
	scanf("%d", &n);
	int p;
	scanf("%d", &p);
	FOR(i, 0, n)
	{
		scanf("%d%d", &sharks[i].first, &sharks[i].second);
	}
	FOR(i, 0, n)
	{
		ll l = 1;
		ll r = 1000000000;
		int minp = -1;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			ll x = mid * p;
			if (x >= sharks[i].first)
			{
				r = mid - 1;
				minp = mid;
			}
			else
			{
				l = mid + 1;
			}
		}
		l = 1;
		r = 1000000000;
		int maxp = -1;
		while (l <= r)
		{
			ll mid = (l + r) / 2;
			ll x = mid * p;
			if (x <= sharks[i].second)
			{
				l = mid + 1;
				maxp = mid;
			}
			else
			{
				r = mid - 1;
			}
		}
		if (minp && maxp && minp <= maxp)
		{
			nump[i] = maxp - minp + 1;
		}
		else
		{
			nump[i] = 0;
		}
	}
	double ans = 0;
	FOR(i, 0, n)
	{
		double x = 0;
		x += (ll)nump[i] * (sharks[(i + 1) % n].second - sharks[(i + 1) % n].first + 1);
		x += (ll)nump[(i + 1) % n] * (sharks[i].second - sharks[i].first + 1);
		x -= (ll)nump[i] * nump[(i + 1) % n];
		x /= (sharks[i].second - sharks[i].first + 1);
		x /= (sharks[(i + 1) % n].second - sharks[(i + 1) % n].first + 1);
		x *= 2000;
		ans += x;
	}
	printf("%.9f\n", ans);
}