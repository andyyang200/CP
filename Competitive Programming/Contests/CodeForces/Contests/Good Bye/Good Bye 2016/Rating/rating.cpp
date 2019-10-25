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
int c[200001];
int d[200001];
int n;
bool Infinity()
{
	FOR(i, 0, n)
	{
		if (d[i] == 2)
		{
			return false;
		}
	}
	return true;
}
bool Impossible()
{
	FOR(i, 0, n - 1)
	{
		if (d[i] == 1 && c[i] > 0 && d[i + 1] == 2)
		{
			return true;
		}
		if (d[i] == 2 && c[i] < 0 && d[i + 1] == 1)
		{
			return true;
		}
	}
	return false;
}
int main(void)
{
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &c[i], &d[i]);
	}
	if (Infinity())
	{
		cout << "Infinity" << endl;
		return 0;
	}
	if (Impossible())
	{
		cout << "Impossible" << endl;
		return 0;
	}
	int l = -30000000;
	int r = 30000000;
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		int x = m;
		int direction = 0;
		FOR(i, 0, n)
		{
			if (d[i] == 1 && x < 1900)
			{
				direction = 1;
				break;
			}
			if (d[i] == 2 && x >= 1900)
			{
				direction = -1;
				break;
			}
			x += c[i];
		}
		if (direction == 1)
		{
			l = m + 1;
		}
		else if (direction == -1)
		{
			r = m - 1;
		}
		else
		{
			ans = x;
			l = m + 1;
		}
	}
	if (ans == 30000000)
	{
		cout << "Infinite" << endl;
		return 0;
	}
	if (ans == -1)
	{
		cout << "Impossible" << endl;
		return 0;
	}
	cout << ans << endl;
}