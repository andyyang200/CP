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

	char grid[500][500];
	bool visited[500][500];
	int n, m, r1, c1, r2, c2;
	bool can;
	int dx[] = { 0, 0, 1, -1 };
	int dy[] = { 1, -1, 0, 0 };
	int neighbors(int r, int c)
	{
		int count = 0;
		FOR(i, 0, 4)
		{
			int nextR = r + dx[i];
			int nextC = c + dy[i];
			if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && grid[nextR][nextC] == '.')
			{
				count++;
			}
			else if (nextR == r1 && nextC == c1)
			{
				count++;
			}
		}
		return count;
	}
	void dfs(int r, int c)
	{
		if (can)
		{
			return;
		}
		FOR(i, 0, 4)
		{
			int nextR = r + dx[i];
			int nextC = c + dy[i];
			if (nextR == r2 && nextC == c2)
			{
				can = true;
				return;
			}
			else if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m && grid[nextR][nextC] == '.' && !visited[nextR][nextC])
			{
				visited[nextR][nextC] = true;
				dfs(nextR, nextC);
			}
		}
	}

	int main()
	{
		scanf("%d%d", &n, &m);
		FOR(i, 0, n)
		{
			FOR(j, 0, m)
			{
				cin >> grid[i][j];
			}
		}
		scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
		r1--;
		c1--;
		r2--;
		c2--;
		can = false;
		visited[r1][c1] = true;
		dfs(r1, c1);
		if (r1 == r2 && c1 == c2)
		{
			can = true;
		}
		if (!can)
		{
			cout << "NO" << endl;
			return 0;
		}
		if (grid[r2][c2] == 'X' && neighbors(r2, c2) >= 1)
		{
			cout << "YES" << endl;
			return 0;
		}
		if (grid[r2][c2] == '.' && neighbors(r2, c2) >= 2)
		{
			cout << "YES" << endl;
			return 0;
		}
		cout << "NO" << endl;;
	}