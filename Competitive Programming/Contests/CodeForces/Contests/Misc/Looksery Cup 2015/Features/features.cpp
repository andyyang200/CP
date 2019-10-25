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
char grid[100][100];
int times[100][100];
void b(int i, int j)
{
	FOR(x, 0, i + 1)
	{
		FOR(y, 0, j + 1)
		{
			times[x][y] += -1 - times[i][j];
		}
	}
}
void w(int i, int j)
{
	FOR(x, 0, i + 1)
	{
		FOR(y, 0, j + 1)
		{
			times[x][y] += 1 - times[i][j];
		}
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			cin >> grid[i][j];
		}
	}
	int count = 0;
	RFOR(i, n - 1, -1)
	{
		RFOR(j, m - 1, -1)
		{
			if (grid[i][j] == 'W' && times[i][j] != 1)
			{
				w(i, j);
				count++;
			}
			else if (grid[i][j] == 'B' && times[i][j] != -1)
			{
				b(i, j);
				count++;
			}
		}
	}
	cout << count << endl;
}