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

int main()
{
	string s;
	cin >> s;
	int first = -1;
	int last = -1;
	FOR(i, 0, s.length() - 1)
	{
		if (s.substr(i, 2) == "AB")
		{
			first = i;
			break;
		}
	}
	RFOR(i, s.length() - 2, -1)
	{
		if (s.substr(i, 2) == "BA")
		{
			last = i;
			break;
		}
	}
	if (first >= 0 && last >= 0 && first + 2 <= last)
	{
		cout << "YES" << endl;
		return 0;
	}
	first = -1;
	last = -1;
	FOR(i, 0, s.length() - 1)
	{
		if (s.substr(i, 2) == "BA")
		{
			first = i;
			break;
		}
	}
	RFOR(i, s.length() - 2, -1)
	{
		if (s.substr(i, 2) == "AB")
		{
			last = i;
			break;
		}
	}
	if (first >= 0 && last >= 0 && first + 2 <= last)
	{
		cout << "YES" << endl;
		return 0;
	}
	cout << "NO" << endl;
}