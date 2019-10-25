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

int main()
{
	freopen("word.in", "r", stdin);
	freopen("word.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(t, 0, tests)
	{
		string s;
		cin >> s;
		string ans = "";
		ans += s[0];
		FOR(i, 1, s.length())
		{
			if (s[i] > ans[0])
			{
				ans = s[i] + ans;
			}
			else if (s[i] < ans[0])
			{
				ans += s[i];
			}
			else
			{
				string ans1 = s[i] + ans;
				string ans2 = ans + s[i];
				if (ans1.compare(ans2) > 0)
				{
					ans = ans1;
				}
				else
				{
					ans = ans2;
				}
			}
		}
		cout << "Case #" << t + 1 << ": " << ans << endl;
	}
}