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

int main(void)
{
	freopen("numbers.in", "r", stdin);
	freopen("numbers.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		string s;
		cin >> s;
		string ans = s;
		for (int i = s.length() - 1; i >= -1; i--) // last character that is the same as in s
		{
			FOR(j, 0, i)
			{
				ans[j] = s[j];
			}
			if (i + 1< s.length())
			{
				ans[i + 1] = (char)((int)s[i + 1] - 1);
			}
			FOR(j, i + 2, s.length())
			{
				ans[j] = '9';
			}
			bool can = true;
			FOR(j, 0, s.length())
			{
				if (j > 0 && ans[j] < ans[j - 1])
				{
					can = false;
					break;
				}
			}
			if (can)
			{
				while (ans.size() > 1 && ans[0] == '0')
				{
					ans = ans.substr(1, ans.length());
				}
				cout << "Case #" << test + 1 << ": " << ans << endl;
				break;
			}
		}
	}
}