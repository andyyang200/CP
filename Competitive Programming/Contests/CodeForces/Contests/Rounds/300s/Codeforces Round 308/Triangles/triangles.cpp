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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
map<pii, int> slopes;
pii points[2001];
bool dequals(double a, double b)
{
	return fabs(a - b) <= 1e-9;
}
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &points[i].first, &points[i].second);
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		FOR(j, i + 1, n)
		{
			FOR(k, j + 1, n)
			{
				double a = (points[j].second - points[i].second) / (points[j].first - points[i].first);
				double b = (points[k].second - points[j].second) / (points[k].first - points[j].first);
				if (dequals(a, b))
				{
					ans++;
				}
			}
		}
	}
	ll total = n * (n - 1) * (n - 2) / 6 - ans;
	cout << total << endl;
}