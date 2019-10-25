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

struct cow
{
	int x, y;
	char c;
	bool operator<(const cow& a) const
	{
		return x < a.x;
	}
};
cow cows[501];

int main()
{
	freopen("cowrect.in", "r", stdin);
	freopen("cowrect.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> cows[i].x >> cows[i].y >> cows[i].c;
	}
	sort(cows, cows + n);
	int maxCows = 0;
	int minArea = 0;
	FOR(i, 0, n)
	{
		FOR(j, i, n)
		{
			int count = 0;
			int firstCow = -1;
			int lastCow = -1;
			FOR(k, 0, n)
			{
				int x;
				bool G = false;
				int H = 0;
				for(x = k; x < n && cows[x].x == cows[k].x; x++)
				{
					if (cows[x].y <= max(cows[i].y, cows[j].y) && cows[x].y >= min(cows[i].y, cows[j].y))
					{
						if (cows[x].c == 'G')
						{
							G = true;
						}
						H++;
					}
				}
				if (!G)
				{
					if (H != 0)
					{
						if (firstCow == -1)
						{
							firstCow = k;
						}
						lastCow = x - 1;
						count += H;
					}
				}
				else
				{
					if (firstCow == -1)
					{	
						k = x - 1;
						continue;
					}
					int area = (cows[lastCow].x - cows[firstCow].x) * abs(cows[j].y - cows[i].y);
					if (count > maxCows || (count == maxCows && area < minArea))
					{
						maxCows = count;
						minArea = area;
					}
					count = 0;
					lastCow = firstCow = -1;
				}
				k = x - 1;
			}
			if (firstCow != -1)
			{				
				int area = (cows[lastCow].x - cows[firstCow].x) * abs(cows[j].y - cows[i].y);
				if (count > maxCows || (count == maxCows && area < minArea))
				{
					maxCows = count;
					minArea = area;
				}
			}
		}
	}
	cout << maxCows << endl;
	cout << minArea << endl;
}