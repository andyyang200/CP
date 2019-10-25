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
int l[501][501];
int d[501][501];
int u[501][501];
int r[501][501];
char grid[501][501];
int h, w;
bool inside(int r, int c)
{
	return r >= 0 && r < h && c >= 0 && c < w;
}
int query(int mat[][501], int r1, int c1, int r2, int c2)
{
	if (r1 > r2 || c1 > c2)
	{
		return 0;
	}
	int ans = 0;
	ans += mat[r2][c2];
	if (c1 > 0)
	{
		ans -= mat[r2][c1 - 1];
	}
	if (r1 > 0)
	{
		ans -= mat[r1 - 1][c2];
	}
	if (c1 > 0 && r1 > 0)
	{
		ans += mat[r1 - 1][c1 - 1];
	}
	return ans;
}
int main()
{
	scanf("%d%d", &h, &w);
	FOR(i, 0, h)
	{
		FOR(j, 0, w)
		{
			cin >> grid[i][j];
		}
	}
	FOR(i, 0, h)
	{
		FOR(j, 0, w)
		{
			if (grid[i][j] == '.')
			{
				if (inside(i + 1, j) && grid[i + 1][j] == '.')
				{
					d[i][j]++;
				}
				if (inside(i - 1, j) && grid[i - 1][j] == '.')
				{
					u[i][j]++;
				}
				if (inside(i, j + 1) && grid[i][j + 1] == '.')
				{
					r[i][j]++;
				}
				if (inside(i, j - 1) && grid[i][j - 1] == '.')
				{
					l[i][j]++;
				}
			}
		}
	}
	FOR(i, 0, h)
	{
		FOR(j, 0, w)
		{
			if (i > 0)
			{
				l[i][j] += l[i - 1][j];
				r[i][j] += r[i - 1][j];
				u[i][j] += u[i - 1][j];
				d[i][j] += d[i - 1][j];
			}
			if (j > 0)
			{
				l[i][j] += l[i][j - 1];
				r[i][j] += r[i][j - 1];
				u[i][j] += u[i][j - 1];
				d[i][j] += d[i][j - 1];
			}
			if (i > 0 && j > 0)
			{
				l[i][j] -= l[i - 1][j - 1];
				r[i][j] -= r[i - 1][j - 1];
				u[i][j] -= u[i - 1][j - 1];
				d[i][j] -= d[i - 1][j - 1];
			}
		}
	}
	int q;
	scanf("%d", &q);
	FOR(i, 0, q)
	{
		int r1, c1, r2, c2;
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--;
		c1--;
		r2--;
		c2--;
		int ans = 0;
		ans += query(l, r1, c1 + 1, r2, c2);
		ans += query(r, r1, c1, r2, c2 - 1);
		ans += query(u, r1 + 1, c1, r2, c2);
		ans += query(d, r1, c1, r2 - 1, c2);
		cout << ans / 2 << endl;
	}
}