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

bool check(string str)
{
	FOR(i, 0, str.length())
	{
		if (str[i] != str[str.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string str;
	cin >> str;
	for (char c = 'a'; c <= 'z'; c++)
	{
		for (int position = 0; position <= str.length(); position++)
		{
			stringstream ss;
			string s;
			ss << c;
			ss >> s;
			string temp = str;
			temp.insert(position, s);
			if (check(temp))
			{
				cout << temp << endl;
				return 0;
			}
		}
	}
	cout << "NA" << endl;
}