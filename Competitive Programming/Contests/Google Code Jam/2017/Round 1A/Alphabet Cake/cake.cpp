//Andrew Yang
// accepted
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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
const int LIMIT = 100001;
const int good = '?' + 1;
int minR[LIMIT];
int maxR[LIMIT];
int minC[LIMIT];
int maxC[LIMIT];
int grid[30][30];
int R, C;
void up(int v)
{
	while (true)
	{
		if (minR[v] == 0)
		{
			return;
		}
		FOR(j, minC[v], maxC[v] + 1)
		{
			if (grid[minR[v] - 1][j] != good)
			{
				return;
			}
		}
		FOR(j, minC[v], maxC[v] + 1)
		{
			grid[minR[v] - 1][j] = v;
		}
		minR[v]--;
	}
}
void down(int v)
{
	while (true)
	{
		if (maxR[v] == R - 1)
		{
			return;
		}
		FOR(j, minC[v], maxC[v] + 1)
		{
			if (grid[maxR[v] + 1][j] != good)
			{
				return;
			}
		}
		FOR(j, minC[v], maxC[v] + 1)
		{
			grid[maxR[v] + 1][j] = v;
		}
		maxR[v]++;
	}
}

void left(int v)
{
	while (true)
	{
		if (minC[v] == 0)
		{
			return;
		}
		FOR(i, minR[v], maxR[v] + 1)
		{
			if (grid[i][minC[v] - 1] != good)
			{
				return;
			}
		}
		FOR(i, minR[v], maxR[v] + 1)
		{
			grid[i][minC[v] - 1] = v;
		}
		minC[v]--;
	}
}void right(int v)
{
	while (true)
	{
		if (maxC[v] == C - 1)
		{
			return;
		}
		FOR(i, minR[v], maxR[v] + 1)
		{
			if (grid[i][maxC[v] + 1] != good)
			{
				return;
			}
		}
		FOR(i, minR[v], maxR[v] + 1)
		{
			grid[i][maxC[v] + 1] = v;
		}
		maxC[v]++;
	}
}
int main(void)
{
	freopen("cake.in", "r", stdin);
	freopen("cake.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		scanf("%d%d", &R, &C);
		FOR(i, 0, LIMIT)
		{
			minR[i] = INF;
			maxR[i] = 0;
			minC[i] = INF;
			maxC[i] = 0;
		}
		set<int> s;
		FOR(i, 0, R)
		{
			FOR(j, 0, C)
			{
				char x;
				cin >> x;
				int v = x + 1;
				grid[i][j] = v;
				if (v == good)
				{
					continue;
				}
				minR[v] = min(minR[v], i);
				maxR[v] = max(maxR[v], i);
				minC[v] = min(minC[v], j);
				maxC[v] = max(maxC[v], j);
				s.insert(v);
			}
		}
		FOREACH(itr, s)
		{
			int v = *itr;
			FOR(i, minR[v], maxR[v] + 1)
			{
				FOR(j, minC[v], maxC[v] + 1)
				{
					grid[i][j] = v;
				}
			}
		}
		FOR(i, 0, R)
		{
			FOR(j, 0, C)
			{
				if (grid[i][j] != good)
				{
					up(grid[i][j]);
					left(grid[i][j]);
					right(grid[i][j]);
					down(grid[i][j]);
				}
			}
		}
		FOREACH(itr, s)
		{
			int v = *itr;
			up(v);
			down(v);
			left(v);
			right(v);
		}
		cout << "Case #" << test + 1 << ": " << endl;
		FOR(i, 0, R)
		{
			FOR(j, 0, C)
			{
				cout << (char)(grid[i][j] - 1);
			}
			cout << endl;
		}
	}
}