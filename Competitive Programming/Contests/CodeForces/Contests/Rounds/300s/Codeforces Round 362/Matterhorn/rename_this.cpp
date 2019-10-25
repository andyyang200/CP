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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
map <ll, ll> cost;
int main(void)
{
	int q;
	scanf("%d", &q);
	FOR(i, 0, q)
	{
		int type;
		scanf("%d", &type);
		if (type == 1)
		{
			ll u, v, w;
			cin >> u >> v >> w;
			while (u != v)
			{
				while (u > v)
				{
					cost[u] += w;
					u /= 2;
				}
				while (v > u)
				{
					cost[v] += w;
					v /= 2;
				}
			}
		}
		else
		{
			ll u, v;
			cin >> u >> v;
			ll ans = 0;
			while (u != v)
			{
				while (u > v)
				{
					ans += cost[u];
					u /= 2;
				}
				while (v > u)
				{
					ans += cost[v];
					v /= 2;
				}
			}
			cout << ans << endl;
		}
	}
}