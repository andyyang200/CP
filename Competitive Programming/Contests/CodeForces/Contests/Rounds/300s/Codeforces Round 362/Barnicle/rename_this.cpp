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

int main(void)
{
	string s;
	cin >> s;
	int decimal = -1;
	int shift = -1;;
	FOR(i, 0, s.length())
	{
		if (s[i] == 'e')
		{
			string sub = s.substr(i + 1, s.length());
			shift = atoi(sub.c_str());
			s = s.substr(0, i);
		}
		if (s[i] == '.')
		{
			decimal = i;
		}
	}
	FOR(i, 0, shift)
	{
		if (decimal < s.length() - 1 && s[decimal] == '.')
		{
			swap(s[decimal], s[decimal + 1]);
			decimal++;
		}
		else
		{
			if (decimal < s.length() && s[decimal] == '.')
			{
				s.erase(s.begin() + decimal);
			}
			s += '0';
		}
	}
	if (s[0] == '0' && s[decimal] != '.')
	{
		s.erase(s.begin());
	}
	while (s[decimal] == '.' && s[s.length() - 1] == '0')
	{
		s.pop_back();
	}
	if (s[s.length() - 1] == '.')
	{
		s.erase(s.begin() + s.length() - 1);
	}
	cout << s << endl;
}