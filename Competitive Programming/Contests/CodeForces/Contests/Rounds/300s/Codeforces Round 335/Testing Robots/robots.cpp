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
bool visited[501][501];
int main()
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int r, c, x, y;
	scanf("%d%d%d%d", &r, &c, &x, &y);
	string s;
	cin >> s;
	x--;
	y--;
	visited[x][y] = true;
	cout << 1 << " ";
	FOR(i, 0, s.length())
	{
		if (s[i] == 'U' && x > 0)
		{
			x--;
		}
		if (s[i] == 'D' && x < r - 1)
		{
			x++;
		}
		if (s[i] == 'L' && y > 0)
		{
			y--;
		}
		if (s[i] == 'R' && y < c - 1)
		{
			y++;
		}

		if (i < s.length() - 1)
		{
			if (visited[x][y])
			{
				cout << 0 << " ";
			}
			else
			{
				cout << 1 << " ";
			}
			visited[x][y] = true;
		}
	}
	int ans = 0;
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			if (!visited[i][j])
			{
				ans++;
			}
		}
	}
	cout << ans << endl;
}