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


int main()
{
	string s, t;
	cin >> s >> t;
	int d = 0;
	FOR(i, 0, s.length())
	{
		if (s[i] != t[i])
		{
			d++;
		}
	}
	if (d % 2 != 0)
	{
		cout << "impossible" << endl;
		return 0;
	}
	string ans = "";
	FOR(i, 0, s.length())
	{
		if (s[i] != t[i])
		{
			if (d % 2 == 0)
			{
				ans += s[i];
			}
			else
			{
				ans += t[i];
			}
			d--;
		}
		else
		{
			ans += s[i];
		}
	}
	cout << ans << endl;
}