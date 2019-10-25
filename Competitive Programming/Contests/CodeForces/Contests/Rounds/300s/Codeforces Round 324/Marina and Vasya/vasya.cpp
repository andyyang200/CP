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

int main()
{
	int n, t;
	cin >> n >> t;
	string s1, s2;
	cin >> s1 >> s2;
	int t1, t2;
	t1 = t2 = n - t;
	string ans = "";
	FOR(i, 0, n)
	{
		if (s1[i] == s2[i] && t1 > 0 && t2 > 0)
		{
			ans += s1[i];
			t1--;
			t2--;
		}
		else if (s1[i] != s2[i])
		{
			if (t1 > 0)
			{
				ans += s1[i];
				t1--;
			}
			else if (t2 > 0)
			{
				ans += s2[i];
				t2--;
			}
			else
			{
				FOR(j, 0, 3)
				{
					if ('a' + j != s1[i] && 'a' + j != s2[i])
					{
						ans += 'a' + j;
						break;
					}
				}
			}
		}
		else
		{
			FOR(j, 0, 3)
			{
				if ('a' + j != s1[i] && 'a' + j != s2[i])
				{
					ans += 'a' + j;
					break;
				}
			}
		}
	}
	if (t1 > 0 || t2 > 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << ans << endl;
	}
}