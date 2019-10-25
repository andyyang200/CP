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

pii points[40001];

int main() 
{
	//freopen("sight.in", "r", stdin);
	//freopen("sight.out", "w", stdout);

	int n, r;
	scanf("%d%d", &n, &r);
	FOR(i, 0, n)
	{
		scanf("%d%d", &points[i].first, &points[i].second);
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			double distance;
			if (points[i].first - points[j].first == 0)
			{
				distance = abs(points[i].first);
			}
			else if (points[i].second - points[j].second == 0)
			{
				distance = abs(points[i].second);
			}
			else
			{
				double m = (double)(points[i].second - points[j].second) / (points[i].first - points[j].first);
				double b = points[i].second - m * points[i].first;
				double A = -m;
				double B = 1;
				double C = -b;
				distance = fabs(C / sqrt(A * A + B * B));
			}
			if (distance + 1e-9 >= r)
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}