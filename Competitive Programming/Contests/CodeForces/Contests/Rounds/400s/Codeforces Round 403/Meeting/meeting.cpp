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
int main(void)
{
	int n;
	scanf("%d", &n);
	
	FOR(i, 0, n)
	{
		scanf("%d", &a[i].first);
	}
	FOR(i, 0, n)
	{
		scanf("%d", &a[i].second);
	}
	sort(a, a + n);
	double l = 0;
	double r = INF;
	double ans = -1;
	FOR(i, 0, 100)
	{
		double m = (l + r) / 2;
		double l2 = 0;
		double r2 = INF;
		bool hasPosition = false;
		FOR(j, 0, 100)
		{
			double m2 = (l2 + r2) / 2;
			bool found = true;
			FOR(k, 0, n)
			{
				if (abs(a[k].first - m2) / a[k].second > m)
				{
					if (a[k].first < m2)
					{
						r2 = m2;
					}
					else
					{
						l2 = m2;
					}
					found = false;
					break;
				}
			}
			if (found)
			{
				hasPosition = true;
				break;
			}
		}
		if (hasPosition)
		{
			ans = m;
			r = m;
		}
		else
		{
			l = m;
		}
	}
	printf("%.9f\n", ans);
}