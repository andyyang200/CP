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

/*
You are given an array of N elements, and you must remove one subarray.
What is the minimum average of the remaining elements?
*/


double a[100001];
double dp[100001];
int n;
bool check(double m)
{
	int total = 0;
	FOR(i, 0, n)
	{
		a[i] -= m;
		total += a[i];
	}
	double maxDp = 0;
	FOR(i, 0, n)
	{
		dp[i] = max(dp[i - 1] + a[i], 0.0);
		maxDp = max(maxDp, dp[i]);
	}
	FOR(i, 0, n)
	{
		a[i] += m;
	}
	return total - maxDp <= 0;
}

int main(void)
{
	scanf("%d", &n);
	double l = INF;
	double r = -INF;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
		l = min(l, (double)a[i]);
		r = max(r, (double)a[i]);
	}
	int ans = 0;
	FOR(i, 0, 150)
	{
		int mid = (l + r) / 2;
		if (check(mid))
		{
			r = mid - 1;
			ans = mid;
		}
		else
		{
			l = mid + 1;
		}
	}
	cout << ans << endl;
}