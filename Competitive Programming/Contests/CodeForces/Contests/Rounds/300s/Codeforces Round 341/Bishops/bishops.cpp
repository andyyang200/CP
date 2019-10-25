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
int p1[1005][1005];
int p2[1005][1005];
int bishop[1005][1005];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		int r, c;
		scanf("%d%d", &r, &c);
		r--;
		c--;
		p1[r][c] = 1;
		p2[r][c] = 1;
		bishop[r][c] = 1;
	}
	FOR(i, 0, 1000)
	{
		FOR(j, 0, 1000)
		{
			if (i > 0 && j > 0)
			{
				p1[i][j] += p1[i - 1][j - 1];
			}
		}
	}
	FOR(i, 0, 1000)
	{
		RFOR(j, 999, -1)
		{
			if (i > 0 && j < 999)
			{
				p2[i][j] += p2[i - 1][j + 1];
			}
		}
	}
	ll ans = 0;
	FOR(i, 0, 1000)
	{
		FOR(j, 0, 1000)
		{
			if (bishop[i][j])
			{
				ans += p1[i][j] + p2[i][j] - 2;
			}
		}
	}
	cout << ans << endl;
}