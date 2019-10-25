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

int ghosts[301];
int candles[301];

int main()
{
	int m, t, r;
	cin >> m >> t >> r;
	if (r > t)
	{
		cout << -1 << endl;
		return 0;
	}
	FOR(i, 0, m)
	{
		cin >> ghosts[i];
		candles[i] = r;
	}
	int count = 0;
	FOR(i, 0, m)
	{
		RFOR(j, ghosts[i] - 1, -301)
		{
			if (candles[i] == 0)
			{
				break;
			}
			count++;
			FOR(k, i, m)
			{
				if (ghosts[k] <= j + t)
				{
					candles[k]--;
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << count << endl;
}