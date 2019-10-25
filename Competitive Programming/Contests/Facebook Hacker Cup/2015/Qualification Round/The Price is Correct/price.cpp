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
ll a[100001];
ll p[100001];
ll getSum(ll x, ll y)
{
	return p[y] - (x == 0 ? 0 : p[x - 1]);
}
int main()
{
	ll sets;
	cin >> sets;
	FOR(set, 0, sets)
	{
		ll n, c;
		cin >> n >> c;
		FOR(i, 0, n)
		{
			cin >> a[i];
			if (i == 0)
			{
				p[i] = a[i];
			}
			else
			{
				p[i] = p[i - 1] + a[i];
			}
		}
		ll ans = 0;
		FOR(i, 0, n)
		{
			ll l = i;
			ll r = n - 1;
			ll j = -1;
			while (l <= r)
			{
				ll mid = (l + r) / 2;
				if (getSum(i, mid) <= c)
				{
					j = mid;
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}
			if (j != -1)
			{
				ans += j - i + 1;
			}
		}
		printf("Case #%d: ", set + 1);
		cout << ans << endl;
	}
}