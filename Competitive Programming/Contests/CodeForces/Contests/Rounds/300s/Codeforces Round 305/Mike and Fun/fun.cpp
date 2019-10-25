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

bool grid[501][501];
int score[501];

int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			scanf("%d", &grid[i][j]);
		}
	}
	FOR(i, 0, n)
	{
		int s = 0;
		FOR(j, 0, m)
		{
			if (grid[i][j])
			{
				s++;
			}
			else
			{
				s = 0;
			}
			score[i] = max(score[i], s);
		}
	}
	FOR(i, 0, q)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		grid[x][y] = !grid[x][y];
		score[x] = 0;
		int s = 0;
		FOR(j, 0, m)
		{
			if (grid[x][j])
			{
				s++;
			}
			else
			{
				s = 0;
			}
			score[x] = max(score[x], s);
		}
		int ans = 0;
		FOR(j, 0, n)
		{
			ans = max(ans, score[j]);
		}
		cout << ans << endl;
	}
}