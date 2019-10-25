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
pii points[201];	
int dleft[201];
int dright[201];
int totalDistance;
int getDistance(int a, int b)
{
	return abs(points[a].first - points[b].first) + abs(points[a].second - points[b].second);
}
int getShortestDistance(int a, int b)
{
	int d = getDistance(a, b);
	return min(d, totalDistance - d);
}
int main()
{
	//freopen("lightsout.in", "r", stdin);
	//freopen("lightsout.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &points[i].first, &points[i].second);
	}
	totalDistance = 0;
	FOR(i, 0, n)
	{
		dleft[i] = getDistance(i, (i - 1 + n) % n);
		dright[i] = getDistance(i, (i + 1) % n);
		totalDistance += dright[i];
	}
	int ans = 0;
	FOR(i, 1, n)
	{
		int d1 = 0;
		int d2 = 0;
		FOR(j, 0, i)
		{
			d1 += dright[j];
		}
		FOR(j, i, n)
		{
			d2 += dright[j];
		}
		ans = max(ans, abs(d1 - d2));
	}
	cout << ans << endl;
}