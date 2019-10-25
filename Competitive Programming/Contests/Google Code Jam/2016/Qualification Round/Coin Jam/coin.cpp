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
#define N 32
#define J 500	
ll getFactor(ll n)
{
	for (ll i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return i;
		}
	}
	return -1;
}
ll get(ll x, ll base)
{
	ll pow = 1;
	ll ans = 0;
	FOR(i, 0, N)
	{
		if (x & (1 << i))
		{
			ans += pow;
		}
		pow *= base;
	}
	return ans;
}
int main()
{
	freopen("coin.out", "w", stdout);
	cout << "Case #1:" << endl;
	int cnt = 0;
	FOR(i, 0, 1 << (N - 2))
	{
		ll x = (1 << (N - 1)) + (i << 1) + 1;
		vector<ll> ans;
		bool good = true;
		FOR(base, 2, 11)
		{
			ll v = get(x, base);
			ll factor = getFactor(v);
			if (factor == -1)
			{
				good = false;
				break;
			}
			ans.push_back(factor);
		}
		if (good)
		{
			cout << 1 << bitset<N - 2>(i).to_string() << 1;
			FOR(j, 0, ans.size())
			{
				cout << " " << ans[j];
			}
			cout << endl;
			cnt++;
		}
		if (cnt == J)
		{
			break;
		}
	}
}