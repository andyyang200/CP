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
int c[26];
int main()
{
	string s;
	cin >> s;
	FOR(i, 0, s.length())
	{
		c[s[i] - 'a']++;
	}
	if (s.length() % 2 == 0)
	{
		vector<int> v;
		FOR(i, 0, 26)
		{
			if (c[i] % 2 == 1)
			{
				v.push_back(i);
			}
		}
		FOR(i, 0, v.size() / 2)
		{
			c[v[i]]++;
			c[v[v.size() - 1 - i]]--;
		}
		string ans = "";
		FOR(i, 0, 26)
		{
			FOR(j, 0, c[i] / 2)
			{
				ans += ('a' + i);
			}
		}
		cout << ans;
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
	else
	{
		vector<int> v;
		FOR(i, 0, 26)
		{
			if (c[i] % 2 == 1)
			{
				v.push_back(i);
			}
		}
		FOR(i, 0, v.size() / 2)
		{
			c[v[i]]++;
			c[v[v.size() - 1 - i]]--;
		}
		string ans = "";
		int odd = -1;
		FOR(i, 0, 26)
		{
			if (c[i] % 2 == 0)
			{
				FOR(j, 0, c[i] / 2)
				{
					ans += ('a' + i);
				}
			}
			else
			{
				odd = i;
			}
		}
		cout << ans;
		FOR(j, 0, c[odd])
		{
			cout << (char)('a' + odd);
		}
		reverse(ans.begin(), ans.end());
		cout << ans << endl;
	}
}