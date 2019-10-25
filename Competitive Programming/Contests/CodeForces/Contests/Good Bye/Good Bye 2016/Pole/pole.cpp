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
int main(void)
{
	int n;
	cin >> n;
	int d = 0;
	FOR(i, 0, n)
	{
		int x;
		string s;
		cin >> x >> s;
		if (s == "North")
		{
			if (d - x < 0)
			{
				cout << "NO" << endl;
				return 0;
			}
			d -= x;
		}
		if (s == "South")
		{
			if (d + x > 20000)
			{
				cout << "NO" << endl;
				return 0;
			}
			d += x;
		}
		if (s == "East")
		{
			if (d == 0 || d == 20000)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
		if (s == "West")
		{
			if (d == 0 || d == 20000)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	if (d == 0)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}