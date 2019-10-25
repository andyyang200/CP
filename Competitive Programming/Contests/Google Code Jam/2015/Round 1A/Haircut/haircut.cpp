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
#include <numeric>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;


ll barbers[1005];
int times[1005];
int b, n;

int check(ll time)
{
	ll people = 0;
	FOR(i, 0, b)
	{
		people += (double)time / barbers[i];
	}
	people += b;
	return people < n;
}

int main()
{
	freopen("haircut.in", "r", stdin);
	freopen("haircut.out", "w", stdout);
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{
		scanf("%d%d", &b, &n);
		FOR(i, 0, b)
		{
			scanf("%d", &barbers[i]);
		}
		if (n <= b)
		{
			cout << "Case #" << set + 1 << ": " << n << endl;
			continue;
		}
		ll l = 0;
		ll r = (ll)100000 * 1e9;
		ll time = -1;
		while (l <= r)
		{
			ll m = (l + r) / 2;
			if (check(m))
			{
				time = m;
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
		int people = 0;
		FOR(i, 0, b)
		{
			people += (double)time / barbers[i];
		}
		people += b;
		FOR(i, 0, b)
		{
			times[i] = barbers[i] - time % barbers[i];
		}
		while (true)
		{
			int minTime = 1000000;
			int bestIndex = -1;
			FOR(j, 0, b)
			{
				if (times[j] < minTime)
				{
					minTime = times[j];
					bestIndex = j;
				}
			}
			FOR(j, 0, b)
			{
				times[j] -= minTime;
			}
			times[bestIndex] += barbers[bestIndex];
			people++;
			if (people == n)
			{
				cout << "Case #" << set + 1 << ": " << bestIndex + 1 << endl;
				break;
			}
		}
	}
}