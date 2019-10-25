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
typedef long long ll;
typedef pair<int, int> pii;

int dpR[105][105];
int dpC[105][105];
bool rough[105][105];
bool smooth[105][105];
bool stamped[105][105];
int R, C;
bool finished()
{
	FOR(i, 0, R)
	{
		FOR(j, 0, C)
		{
			if (!rough[i][j] || !smooth[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	freopen("skicourse.in", "r", stdin);
	freopen("skicourse.out", "w", stdout);
	scanf("%d%d", &R, &C);
	FOR(i, 0, R)
	{
		FOR(j, 0, C)
		{
			char ch;
			cin >> ch;
			if (ch == 'R')
			{
				rough[i][j] = true;
			}
			else
			{
				smooth[i][j] = true;
			}
		}
	}
	int ans = 101;
	while (!finished())
	{
		FOR(i, 0, R)
		{
			FOR(j, 0, C)
			{
				dpR[i][j] = dpC[i][j] = 0;
			}
		}
		int maxSize = 0;
		int bestR = -1;
		int bestC = -1;
		RFOR(i, R - 1, -1)
		{
			RFOR(j, C - 1, -1)
			{
				if (rough[i][j])
				{
					dpR[i][j] = 1 + min(dpR[i + 1][j], min(dpR[i][j + 1], dpR[i + 1][j + 1]));
				}
				if (smooth[i][j])
				{
					dpC[i][j] = 1 + min(dpC[i + 1][j], min(dpC[i][j + 1], dpC[i + 1][j + 1]));
				}
				if (dpR[i][j] > maxSize && !stamped[i][j])
				{
					maxSize = dpR[i][j];
					bestR = i;
					bestC = j;
				}
				if (dpC[i][j] > maxSize && !stamped[i][j])
				{
					maxSize = dpC[i][j];
					bestR = i;
					bestC = j;
				}
			}
		}
		ans = min(ans, maxSize);
		stamped[bestR][bestC] = true;
		FOR(i, bestR, bestR + maxSize)
		{
			FOR(j, bestC, bestC + maxSize)
			{
				rough[i][j] = true;
				smooth[i][j] = true;
			}
		}
	}
	cout << ans << endl;
}