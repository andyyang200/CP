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

int n, m;
char board[51][51];
bool visited[51][51];
map < pair<pii, pii>, bool > used;
bool cycle = false;

void dfs(int r, int c, int length, char color)
{
	if (cycle)
	{
		return;
	}
	if (r + 1 >= 0 && r + 1 < n && c >= 0 && c < m && board[r + 1][c] == color)
	{
		if (visited[r + 1][c] && !used[make_pair(pii(r, c), pii(r + 1, c))])
		{
			if (length >= 4)
			{
				cycle = true;
			}
		}
		else if (!visited[r + 1][c])
		{
			used[make_pair(pii(r, c), pii(r + 1, c))] = used[make_pair(pii(r + 1, c), pii(r, c))] = true;
			visited[r + 1][c] = true;
			dfs(r + 1, c, length + 1, color);
		}
	}
	if (r - 1 >= 0 && r - 1 < n && c >= 0 && c < m && board[r - 1][c] == color)
	{
		if (visited[r - 1][c] && !used[make_pair(pii(r, c), pii(r - 1, c))])
		{
			if (length >= 4)
			{
				cycle = true;
			}
		}
		else if (!visited[r - 1][c])
		{
			used[make_pair(pii(r, c), pii(r - 1, c))] = used[make_pair(pii(r - 1, c), pii(r, c))] = true;
			visited[r - 1][c] = true;
			dfs(r - 1, c, length + 1, color);
		}
	}
	if (r >= 0 && r < n && c + 1 >= 0 && c < m && board[r][c + 1] == color)
	{
		if (visited[r][c + 1] && !used[make_pair(pii(r, c), pii(r, c + 1))])
		{
			if (length >= 4)
			{
				cycle = true;
			}
		}
		else if (!visited[r][c + 1])
		{
			used[make_pair(pii(r, c), pii(r, c + 1))] = used[make_pair(pii(r, c + 1), pii(r, c))] = true;
			visited[r][c + 1] = true;
			dfs(r, c + 1, length + 1, color);
		}
	}
	if (r >= 0 && r < n && c - 1 >= 0 && c < m && board[r][c - 1] == color)
	{
		if (visited[r][c - 1] && !used[make_pair(pii(r, c), pii(r, c - 1))])
		{
			if (length >= 4)
			{
				cycle = true;
			}
		}
		else if (!visited[r][c - 1])
		{
			used[make_pair(pii(r, c), pii(r, c - 1))] = used[make_pair(pii(r, c - 1), pii(r, c))] = true;
			visited[r][c - 1] = true;
			dfs(r, c - 1, length + 1, color);
		}
	}
}
int main()
{
	cin >> n >> m;
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			cin >> board[r][c];
		}
	}
	FOR(r, 0, n)
	{
		FOR(c, 0, m)
		{
			if (!visited[r][c])
			{
				visited[r][c] = true;
				dfs(r, c, 1, board[r][c]);
				if (cycle)
				{
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
}