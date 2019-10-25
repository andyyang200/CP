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

set<int> bad;

set<int> seen;
int main(void)
{
	ll b, q, l, m;
	cin >> b >> q >> l >> m;
	set<int> bad;
	FOR(i, 0, m)
	{
		int x;
		scanf("%d", &x);
		bad.insert(x);
	}
	if (abs(b * q) > abs(b))
	{
		int count = 0;
		while (abs(b) <= l)
		{
			if (bad.find(b) == bad.end())
			{
				count++;
			}
			b *= q;
		}
		cout << count << endl;
	}
	else
	{
		int count = 0;
		FOR(i, 0, 4)
		{
			if (abs(b) > l)
			{
				break;
			}
			if (bad.find(b) == bad.end())
			{
				count++;
			}
			b *= q;
		}
		if (count > 1)
		{
			cout << "inf" << endl;
		}
		else
		{
			cout << count << endl;
		}
	}
}