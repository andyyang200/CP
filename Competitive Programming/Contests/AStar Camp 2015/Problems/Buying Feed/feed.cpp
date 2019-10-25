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
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int k, e, n;
ll previousdp[10001];
ll dp[10001];
struct Store
{
	int x, f;
	ll c;
	bool operator< (const Store& s) const
	{
		return x < s.x;
	}
};
Store stores[10001];
struct Price
{
	ll price;
	int valid_until;
	Price(ll a, int b)
	{
		price = a;
		valid_until = b;
	}
};
int main()
{
	freopen("feed.in", "r", stdin);
	freopen("feed.out", "w", stdout);
	scanf("%d%d%d", &k, &e, &n);
	FOR(i, 0, n)
	{
		scanf("%d%d%d", &stores[i].x, &stores[i].f, &stores[i].c);
	}
	sort(stores, stores + n);
	memset(previousdp, -1, sizeof(previousdp));
	previousdp[0] = 0;
	int previous = 0;
	FOR(i, 0, n)
	{
		ll distance = stores[i].x - previous;
		memset(dp, -1, sizeof(dp));
		deque< Price > prices;
		FOR(feed, 0, k + 1)
		{
			if (previousdp[feed] != -1)
			{
				ll price = (previousdp[feed] + distance * feed * feed) - feed * stores[i].c;
				int valid_until = feed + stores[i].f;
				while (!prices.empty() && prices.back().price > price)
				{
					prices.pop_back();
				}
				prices.push_back(Price(price, valid_until));
			}
			while (!prices.empty() && prices.front().valid_until < feed)
			{
				prices.pop_front();
			}
			if (!prices.empty())
			{
				dp[feed] = prices.front().price + feed * stores[i].c;
			}
		}
		copy(dp, dp + k + 1, previousdp);
		previous = stores[i].x;
	}
	cout << previousdp[k] + k * k * (e - previous) << "\n";
}