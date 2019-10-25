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
typedef pair<int, int> pii;
int n, m, k, p;
ll bamboo[100000];
bool check(ll height)
{
	int total = 0;
	int limit = m * k;
	FOR(i, 0, n)
	{
		total += (int)ceil(max(0.0, (double)(bamboo[i] - height)) / p);
		if (total > limit)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	cin >> n >> m >> k >> p;
	ll maxGrow = 0;
	FOR(i, 0, n)
	{
		ll h, a;
		cin >> h >> a;
		bamboo[i] = h + a * m;
		maxGrow = max(maxGrow, a);
	}
	ll l = 0, r = 6000000000000;
	ll ans = 0;
	while (l <= r)
	{
		ll mid = (l + r) / 2;
		if (check(mid))
		{
			ans = mid;
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	ans = max(ans, maxGrow);
	cout << ans << endl;
}