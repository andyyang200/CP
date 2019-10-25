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
ll steps[100001];
ll p[100001];
int main()
{
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{
		int n;
		int a, b;
		cin >> n >> a >> b;
		FOR(i, 0, n)
		{
			cin >> steps[i];
			p[i] = (ll)(i == 0 ? 0 : p[i - 1]) + steps[i];
		}
		double ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j <= b + 1; j++)
			{
				ll cost = p[n - 1] * j + p[i];
				if (cost > b)
				{
					break;
				}
				ll nextCost = cost + steps[(i + 1) % n];
				ll l = max(cost, (ll)a);
				ll r = min(nextCost, (ll)b);
				if (l > r)
				{
					continue;
				}
				ans += ((double)((l - cost) + (r - cost)) / 2) * (r - l);
			}
		}
		ll cost = 0;
		ll nextCost = steps[0];
		ll l = max(cost, (ll)a);
		ll r = min(nextCost, (ll)b);
		if (l <= r)
		{
			ans += ((double)((l - cost) + (r - cost)) / 2) * (r - l);
		}
		ans /= (b - a);
		printf("Case #%d: %.9f\n", set + 1, ans);
	}
}