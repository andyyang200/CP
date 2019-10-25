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
int a[5001];
int dp[5001];
int necessary[5001];
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, k)
		{
			dp[j] = 0;
		}
		dp[0] = 1;
		FOR(j, 0, i)
		{
			if (a[j] >= k)
			{
				continue;
			}
			RFOR(x, k - 1, a[j] - 1)
			{
				if (dp[x - a[j]])
				{
					dp[x]++;;
					if (x >= k - a[i])
					{
						necessary[i] = true;
						break;
					}
				}
			}
			if (necessary[i]) {
				break;
			}
		}
		FOR(j, i + 1, n)
		{
			if (a[j] >= k)
			{
				continue;
			}
			RFOR(x, k - 1, a[j] - 1)
			{
				if (dp[x - a[j]])
				{
					dp[x]++;;
					if (x >= k - a[i])
					{
						necessary[i] = true;
						break;
					}
				}
			}
			if (necessary[i]) {
				break;
			}
		}
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		if (!necessary[i])
		{
			ans++;
		}
	}
	cout << ans << endl;
}