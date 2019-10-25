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
void f(string& s, int i)
{
	FOR(j, 0, i + 1)
	{
		if (s[j] == '-')
		{
			s[j] = '+';
		}
		else
		{
			s[j] = '-';
		}
	}
	reverse(s.begin(), s.begin() + i + 1);
}
int main()
{
	freopen("pancakes.in", "r", stdin);
	freopen("pancakes.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		string s;
		cin >> s;
		int ans = 0;
		RFOR(i, s.length() - 1, -1)
		{
			if (s[i] == '-')
			{
				if (s[0] == '+')
				{
					FOR(j, 0, s.length() - 1)
					{
						if (s[j] == '+')
						{
							s[j] = '-';
						}
						else
						{
							break;
						}
					}
					ans++;
				}
				f(s, i);
				ans++;
			}
		}
		printf("Case #%d: %d\n", test + 1, ans);
	}
}