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
bool grid[10][10];
int main()
{
	int r, c, n, k;
	cin >> r >> c >> n >> k;
	FOR(i, 0, n)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		grid[a][b] = true;
	}
	int ans = 0;
	FOR(i, 0, r)
	{
		FOR(j, 0, c)
		{
			FOR(i2, i, r)
			{
				FOR(j2, j, c)
				{
					int v = 0;
					FOR(a, i, i2 + 1)
					{
						FOR(b, j, j2 + 1)
						{
							if (grid[a][b])
							{
								v++;
							}
						}
					}
					if (v >= k)
					{
						ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}