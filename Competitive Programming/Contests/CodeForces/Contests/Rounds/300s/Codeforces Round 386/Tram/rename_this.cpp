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
	int s, x1, x2;
	cin >> s >> x1 >> x2;
	int t1, t2;
	cin >> t1 >> t2;
	int p, d;
	cin >> p >> d;
	if (x1 < x2)
	{
		int bus;
		int guy = (x2 - x1) * t2;
		if (d == 1)
		{
			if (p <= x1)
			{
				bus = (x2 - p) * t1;
			}
			else
			{
				bus = (s - p + s + x2) * t1;
			}
		}
		else
		{
			bus = (p + x2) * t1;
		}
		cout << min(guy, bus) << endl;
	}
	else
	{
		int bus;
		int guy = (x1 - x2) * t2;
		if (d == -1)
		{
			if (p >= x1)
			{
				bus = (p - x2) * t1;
			}
			else
			{
				bus = (p + s + s - x2) * t1;
			}
		}
		else
		{
			bus = (s - p + s - x2) * t1;
		}
		cout << min(guy, bus) << endl;
	}
}