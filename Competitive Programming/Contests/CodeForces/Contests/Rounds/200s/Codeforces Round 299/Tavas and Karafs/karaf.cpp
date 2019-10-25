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
ll a, b, n, l, t, m;
bool check(ll k)
{
	ll length = k - l + 1;
	ll maxHeight = a + b * (k - 1);
	ll sum = (a + b * (l - 1) + maxHeight) * length / 2;
	if (sum <= m * t && maxHeight <= t)
	{
		return true;
	}
	return false;
}
int main()
{
	cin >> a >> b >> n;
	FOR(q, 0, n)
	{
		cin >> l >> t >> m;
		ll a = 0;
		ll b = (ll)1000000 * 1000000;
		ll ans = -1;
		while (a <= b)
		{
			ll m = (a + b) / 2;
			if (check(l + m))
			{
				ans = l + m;
				a = m + 1;
				
			}
			else
			{
				b = m - 1;
			}
		}
		cout << ans << endl;
	}
}