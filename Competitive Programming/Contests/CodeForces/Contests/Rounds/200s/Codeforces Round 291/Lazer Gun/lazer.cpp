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
	int n, startX, startY;
	cin >> n >> startX >> startY;
	set<pii> slopes;
	FOR(i, 0, n)
	{
		int x, y;
		cin >> x >> y;
		x -= startX;
		y -= startY;
		if (x == 0)
		{
			slopes.insert(pii(1, 0));
		}
		else if (y == 0)
		{
			slopes.insert(pii(0, 1));
		}
		else
		{
			RFOR(j, min(abs(x), abs(y)), 0)
			{
				if (abs(x) % j == 0 && abs(y) % j == 0)
				{
					x /= j;
					y /= j;
					break;
				}
			}
			if (x < 0 && y < 0)
			{
				x *= -1;
				y *= -1;
			}
			if (y < 0)
			{
				x *= -1;
				y *= -1;
			}
			slopes.insert(pii(x, y));
		}
	}
	cout << slopes.size() << endl;
}