//Andrew Yang
//accepted
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
int flip[1000001];
int a[1000001];
int main(void)
{
	freopen("pancakes.in", "r", stdin);
	freopen("pancakes.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		memset(flip, 0, sizeof(flip));
		memset(a, 0, sizeof(a));
		string s;
		cin >> s;
		int k;
		scanf("%d", &k);
		FOR(i, 0, s.length())
		{
			a[i] = (s[i] == '+' ? 1 : 0);
		}
		int flips = 0;
		int ans = 0;
		bool can = true;
		for(int i = 0; i < s.length(); i++)
		{
			if (i - k >= 0)
			{
				flips -= flip[i - k];
			}
			a[i] = (a[i] + flips) % 2;
			if (i <= s.length() - k && a[i] == 0)
			{
				flip[i] = 1;
				flips++;
				ans++;
				a[i]++;
			}
			if (a[i] == 0)
			{
				can = false;
			}
		}
		if (can)
		{
			printf("Case #%d: %d\n", test + 1, ans);
		}
		else
		{
			printf("Case #%d: %s\n", test + 1, "IMPOSSIBLE");
		}
	}
}