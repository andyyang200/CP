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
char grid[501][501];
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	int minR = INF;
	int minC = INF;
	int maxR = 0;
	int maxC = 0;
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> grid[i][j];
			if (grid[i][j] == 'X')
			{
				minR = min(minR, i);
				maxR = max(maxR, i);
				minC = min(minC, j);
				maxC = max(maxC, j);
			}
		}
	}
	pii a = {-1, -1};
	pii b = {-1, -1};
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (grid[i][j] == 'X' && i == minR && j == minC)
			{
				a = { i, j };
			}
			if (grid[i][j] == 'X' && i == maxR && j == maxC)
			{
				b = { i, j };
			}
		}
	}
	if (a == pii(-1, -1) || b == pii(-1, -1))
	{
		cout << "NO" << endl;
		return 0;
	}
	FOR(i,a.first, b.first + 1)
	{
		FOR(j, a.second, b.second + 1)
		{
			if (grid[i][j] == '.')
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	cout << "YES" << endl;
	return 0;
}