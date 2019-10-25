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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int needed[51];
int index[51];
vector<pii> packages[51];
bool piicompare(const pii a, const pii b) 
{
	if (a.second != b.second)
	{
		return a.second < b.second;
	}
	return a.first > b.first;
}
int main(void)
{
	freopen("rat.in", "r", stdin);
	freopen("rat.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		int n, p;
		scanf("%d%d", &n, &p);
		FOR(i, 0, n)
		{
			scanf("%d", &needed[i]);
		}
		set<int> s;
		FOR(i, 0, n)
		{
			FOR(j, 0, p)
			{
				int amount;
				scanf("%d", &amount);
				int a = ceil(amount / 1.1 / needed[i]);
				int b = floor(amount / 0.9 / needed[i]);
				if (b < a)
				{
					continue;
				}
				packages[i].push_back({ a, b});
				FOR(k, a, b + 1)
				{
					s.insert(k);
				}
			}
			sort(packages[i].begin(), packages[i].end());
		}
		int ans = 0;
		bool stop = false;
		FOREACH(itr, s)
		{
			int servings = *itr;
			if (stop)
			{
				break;
			}
			while (true)
			{
				if (stop)
				{
					break;
				}
				bool can = true;
				FOR(i, 0, n)
				{
					if (packages[i].size() == 0)
					{
						can = false;
						stop = true;
						break;
					}
					while (packages[i].size() > 0)
					{
						if (servings >= packages[i][0].first && servings <= packages[i][0].second)
						{
							packages[i].erase(packages[i].begin());
							break;
						}
						if (servings > packages[i][0].second)
						{
							packages[i].erase(packages[i].begin());
						}
					}
					if (packages[i].size() == 0)
					{
						stop = true;
					}
				}
				if (can)
				{
					ans++;
				}
				else
				{
					break;
				}
			}
		}
		printf("Case #%d: %d\n", test + 1, ans);
	}
}