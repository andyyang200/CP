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
pii beacons[100001];
int dp[100001];
int maxdp[100001];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &beacons[i].first, &beacons[i].second);
	}
	sort(beacons, beacons + n);
	int x = 0;
	FOR(i, 0, n)
	{
		int l = 0;
		int r = i - 1;
		int ans = -1;
		while (l <= r)
		{
			int mid = (l + r) / 2;
			if (beacons[i].first - beacons[mid].first > beacons[i].second)
			{
				ans = mid;
				l = mid + 1;
			}
			else
			{
				r = mid - 1;
			}
		}
		if (ans != -1)
		{
			dp[i] = dp[ans] + 1;
		}
		else
		{
			dp[i] = 1;
		}
		x = max(x, dp[i]);
	}
	cout << n - x << endl;
}