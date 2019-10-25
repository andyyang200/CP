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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
bool found[26];
int main(void)
{
	string s;
	cin >> s;
	FOR(i, 0, (int)s.size() - 26 + 1)
	{
		FOR(j, 0, 26)
		{
			found[j] = false;
		}
		int blank = 0;
		int c = 0;
		FOR(j, i, i + 26)
		{
			if (s[j] != '?')
			{
				if (!found[s[j] - 'A'])
				{
					found[s[j] - 'A'] = true;
					c++;
				}
			}
			else
			{
				blank++;
			}
		}
		if (blank >= 26 - c)
		{
			FOR(j, i, i + 26)
			{
				if (s[j] == '?')
				{
					FOR(k, 0, 26)
					{
						if (!found[k])
						{
							s[j] = k + 'A';
							found[k] = true;
							break;
						}
					}
				}
			}
			FOR(j, 0, s.length())
			{
				if (s[j] == '?')
				{
					s[j] = 'A';
				}
			}
			cout << s << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}