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
int a[1000001];
unordered_map<int, int> dp;
int n, k;
int mid;
int f(int slices)
{
	if (slices < mid)
	{
		return 0;
	}
	if (dp.find(slices) != dp.end())
	{
		return dp[slices];
	}
	int a = slices / 2;
	int b = a + (slices % 2 == 0 ? 0 : 1);
	dp[slices] = max(1, f(a) + f(b));
	return dp[slices];
}
bool check()
{
	dp.clear();
	ll cnt = 0;
	FOR(i, 0, n)
	{
		cnt += f(a[i]);
		//cnt += a[i] / mid
		if (cnt >= k)
		{
			return true;
		}
	}
	return false;
}
int main(void)
{
	scanf("%d%d", &n, &k);
	ll sum = 0;
	int maxSlice = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
		sum += a[i];
		maxSlice = max(maxSlice, a[i]);
	}
	if (sum < k)
	{
		cout << -1 << endl;
		return 0;
	}
	int l = 1;
	int r = maxSlice;
	int ans = -1;
	while (l <= r)
	{
		mid = (l + r) >> 1;
		if (check())
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << endl;
}