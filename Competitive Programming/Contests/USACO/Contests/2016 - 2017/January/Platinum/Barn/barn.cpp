
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
#include <float.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, long long> pii;
unordered_map<ll, double> dp;
ll a[100001];
double pre[100001];
int nSearchRange = 14;
ll getKey(int i, ll j)
{
	return ((ll)i << 44) + j;
}
int mylog(ll x)
{
	int ans = 0;
	while (x)
	{
		x /= 10;
		ans++;
	}
	return ans - 1;
}
pair<ll, ll> bound(ll v)
{
	//ll r = min(17, max(4, mylog(v) + 3));
	ll r = nSearchRange;
	return{ v - r, v + r };
}

double FastDP(int n, ll k)
{
	ll opt = (ll)(pre[1] / pre[n] * k);
	ll low = max((ll)1, opt - 18);
	ll high = min(k, opt + 18);
	for (ll i = low; i <= high; i++)
	{
		dp[getKey(1, i)] = (double)a[1] / i;
	}
	FOR(i, 2, n + 1)
	{
		ll opt = (ll)(pre[i] / pre[n] * k);
		auto b = bound(opt);
		ll low = max((ll)1, b.first);
		ll high = min(k, b.second);
		ll opt2 = (ll)(pre[i - 1] / pre[n] * k);
		auto b2 = bound(opt2);
		ll low2 = max((ll)1, b2.first);
		ll high2 = min(k, b2.second);
		for (ll j = low; j <= high; j++)
		{
			double v = DBL_MAX;
			for (ll x = low2; x <= min(j - 1, high2); x++)
			{
				v = min(v, dp[getKey(i - 1, x)] + (double)a[i] / (j - x));
			}
			dp[getKey(i, j)] = v;
		}
	}
	return dp[getKey(n, k)];
}
int main(void)
{
	freopen("tallbarn.in", "r", stdin);
	freopen("tallbarn.out", "w", stdout);
	int n;
	scanf("%d", &n);
	//n = 100000;
	ll k;
	cin >> k;
	//k = 1e12;
	FOR(i, 1, n + 1)
	{
		scanf("%lld", &a[i]);
		//a[i] = rand() % 1000000000000;
		double s = sqrt(a[i]);
		pre[i] = pre[i - 1] + s;
	}	
	printf("%lld\n", (ll)round(FastDP(n, k)));
}