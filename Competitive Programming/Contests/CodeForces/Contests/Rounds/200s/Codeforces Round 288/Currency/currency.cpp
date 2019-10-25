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
#include <map>
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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

int main()
{
	string s;
	cin >> s;
	int last = -1;
	FOR(i, 0, s.length())
	{
		if ((s[i] - '0') % 2 == 0)
		{
			if (s[i] < s[s.length() - 1])
			{
				char temp = s[s.length() - 1];
				s[s.length() - 1] = s[i];
				s[i] = temp;
				cout << s << endl;
				return 0;
			}
			last = i;
		}
	}
	if (last == -1)
	{
		cout << -1 << endl;
	}
	else
	{
		char temp = s[s.length() - 1];
		s[s.length() - 1] = s[last];
		s[last] = temp;
		cout << s << endl;
	}
}