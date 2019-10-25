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
char grid[10][10];
void flip(int x, int y)
{
	FOR(i, 0, x + 1)
	{
		FOR(j, 0, y + 1)
		{
			grid[i][j] = ((grid[i][j] - '0') + 1) % 2 + '0';
		}
	}
}
int main(void)
{
	freopen("cowtip.in", "r", stdin);
	freopen("cowtip.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		FOR(j, 0, n)
		{
			cin >> grid[i][j];
		}
	}
	int ans = 0;
	RFOR(i, n - 1, -1)
	{
		RFOR(j, n - 1, -1)
		{
			if (grid[i][j] == '1')
			{
				flip(i, j);
				ans++;
			}
		}
	}
	cout << ans << endl;
}