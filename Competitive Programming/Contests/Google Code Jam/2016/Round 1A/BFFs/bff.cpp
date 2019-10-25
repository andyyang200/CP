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
int bff[1005];
int cycleLength[1005];
bool incomplete[1005];
int main()
{
	//freopen("bff.in", "r", stdin);
	//freopen("bff.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(t, 0, tests)
	{
		int n;
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			scanf("%d", &bff[i]);
			bff[i]--;
			cycleLength[i] = 0;
		}
		FOR(i, 0, n)
		{
			int a = i;
			int b = bff[i];
			cycleLength[i] = 1;
			while (true)
			{
				if (bff[b] == a)
				{
					cycleLength[i]++;
					incomplete[i] = true;
					break;
				}
				a = b;
				b = bff[b];
				cycleLength[i]++;
				if (b == i)
				{
					break;
				}
				if (cycleLength[i] > n)
				{
					cycleLength[i] = 0;
					break;
				}
			}
		}
		int ans = 0;
		FOR(i, 0, n)
		{
			if (!incomplete[i])
			{
				ans = max(ans, cycleLength[i]);
			}
		}
		/*set<int> s;
		FOR(i, 0, n)
		{
			if (incomplete[i])
			{
				int a = i;
				while (s.find(a) == s.end())
				{
					s.insert(a);
					a = bff[a];
				}
			}
		}
		ans = max(ans, (int)(s.size()));*/
		printf("Case #%d: %d\n", t + 1, ans);
	}
}