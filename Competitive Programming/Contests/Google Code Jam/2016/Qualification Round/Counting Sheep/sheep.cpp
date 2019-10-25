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
bool seen[10];
int main()
{
	freopen("sheep.in", "r", stdin);
	freopen("sheep.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		int n;
		scanf("%d", &n);
		if (n == 0)
		{
			cout << "Case #" << test + 1 << ": INSOMNIA" << endl;
			continue;
		}
		FOR(i, 0, 10)
		{
			seen[i] = false;
		}
		FOR(i, 1, INF)
		{
			ll x = (ll)n * i;
			while (x > 0)
			{
				seen[x % 10] = true;
				x /= 10;
			}
			bool done = true;
			FOR(i, 0, 10)
			{
				if (!seen[i])
				{
					done = false;
					break;
				}
			}
			if (done)
			{
				cout << "Case #" << test + 1 << ": " << (ll)n * i << endl;
				break;
			}
		}
	}
}