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
int problems[100001];
int main()
{
	int sets;
	scanf("%d", &sets);
	FOR(set, 0, sets)
	{
		int n;
		scanf("%d", &n);
		FOR(i, 0, n)
		{
			scanf("%d", &problems[i]);
		}
		int contest = 0;
		int ans = 0;
		FOR(i, 0, n)
		{
			if (contest == 4)
			{
				contest = 0;
			}
			if (contest > 0)
			{
				if (problems[i] <= problems[i - 1])
				{
					ans += 4 - contest;
					contest = 0;
				}
				else if (problems[i] - problems[i - 1] > 10)
				{
					int temp = problems[i - 1];
					int needed = 0;
					while (problems[i] - temp > 10)
					{
						temp += 10;
						needed++;
					}
					if (needed > 3 - contest)
					{
						ans += 4 - contest;
						contest = 0;
					}
					else
					{
						contest += needed;
						ans += needed;
					}
				}
			}
			contest++;
		}
		ans += 4 - contest;
		printf("Case #%d: %d\n", set + 1, ans);
	}
}