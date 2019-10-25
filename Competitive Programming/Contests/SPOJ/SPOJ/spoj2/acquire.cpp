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
pii a[100001];
vector<pair<ll, ll>> land;
vector<pair<ll, ll>> lines;
vector<pair<double, double>> segments;
double getIntersectionX(pair<ll, ll > x, pair<ll, ll > y)
{
	ll a = x.first;
	ll b = y.first;
	ll c = x.second;
	ll d = y.second;
	return (double)(d - c) / (a - b);
}
ll query(ll x)
{
	int l = 0;
	int r = lines.size() - 1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (x >= segments[mid].first && x <= segments[mid].second)
		{
			return lines[mid].first * x + lines[mid].second;
		}
		if (x > segments[mid].second)
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	return 0;
}
void update(pair<ll, ll> p)
{
	while (lines.size() >= 2 && getIntersectionX(p, lines.back()) <= getIntersectionX(lines.back(), lines[lines.size() - 1]))
	{
		lines.pop_back();
		segments.pop_back();
	}
	double x = getIntersectionX(p, lines.back());
	segments.back().second = x;
	segments.push_back({ x, x + INF });
	lines.push_back(p);
}

int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &a[i].first, &a[i].second);
	}
	sort(a, a + n);
	FOR(i, 0, n)
	{
		while (!land.empty() && land.back().second <= a[i].second)
		{
			land.pop_back();
		}
		land.push_back(a[i]);
	}
	if (land.size() == 1)
	{
		cout << (ll)land[0].first * land[0].second << endl;
		return 0;
	}

	lines.push_back({ land[land.size() - 2].first, (ll)land[land.size() - 1].first * land[land.size() - 1].second });
	segments.push_back({ -INF, INF });
	RFOR(i, land.size() - 2, -1)
	{
		ll x = query(land[i].second);
		x = min(x, (ll)land[i].second * land[land.size() - 1].first);
		if (i > 0)
		{
			update({ land[i - 1].first, x });
		}
		else
		{
			cout << x << endl;
		}
	}
}