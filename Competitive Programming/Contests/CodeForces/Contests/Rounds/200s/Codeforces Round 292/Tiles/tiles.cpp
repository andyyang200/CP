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

char grid[2000][2000];
int n, m;
queue<int> q;

int adjacent(int r, int c)
{
	int count = 0;
	if (r + 1 < n && grid[r + 1][c] == '.')
	{
		count++;
	}
	if (r - 1 >= 0 && grid[r - 1][c] == '.')
	{
		count++;
	}
	if (c + 1 < m && grid[r][c + 1] == '.')
	{
		count++;
	}
	if (c - 1 >= 0 && grid[r][c - 1] == '.')
	{
		count++;
	}
	return count;
}

int isValid(int r, int c)
{
	return r >= 0 && r < n && c >= 0 && c < m && grid[r][c] == '.';
}

void add(int r, int c)
{
	if (isValid(r + 1, c) && adjacent(r + 1, c) == 1)
	{
		q.push(r + 1);
		q.push(c);
	}
	if (isValid(r - 1, c) && adjacent(r - 1, c) == 1)
	{
		q.push(r - 1);
		q.push(c);
	}
	if (isValid(r, c + 1) && adjacent(r, c + 1) == 1)
	{
		q.push(r);
		q.push(c + 1);
	}
	if (isValid(r, c - 1) && adjacent(r, c - 1) == 1)
	{
		q.push(r);
		q.push(c - 1);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		scanf("%s", grid[i]);
	}
	
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			if (grid[r][c] == '.' && adjacent(r, c) == 1)
			{
				q.push(r);
				q.push(c);
			}
		}
	}
	while (!q.empty())
	{
		int r = q.front();
		q.pop();
		int c = q.front();
		q.pop();
		if (grid[r][c] != '.' || adjacent(r, c) != 1)
		{
			continue;
		}
		int nextR = r + 1;
		int nextC = c;
		if (isValid(nextR, nextC))
		{
			grid[r][c] = '^';
			grid[nextR][nextC] = 'v';
			add(nextR, nextC);
			continue;
		}
		nextR = r - 1;
		nextC = c;
		if (isValid(nextR, nextC))
		{
			grid[r][c] = 'v';
			grid[nextR][nextC] = '^';
			add(nextR, nextC);
			continue;
		}
		nextR = r;
		nextC = c + 1;
		if (isValid(nextR, nextC))
		{
			grid[r][c] = '<';
			grid[nextR][nextC] = '>';
			add(nextR, nextC);
			continue;
		}
		nextR = r;
		nextC = c - 1;
		if (isValid(nextR, nextC))
		{
			grid[r][c] = '>';
			grid[nextR][nextC] = '<';
			add(nextR, nextC);
			continue;
		}
	}
	
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			if (grid[r][c] == '.')
			{
				cout << "Not unique" << endl;
				return 0;
			}
		}
	}
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			cout << grid[r][c];
		}
		cout << endl;
	}
}