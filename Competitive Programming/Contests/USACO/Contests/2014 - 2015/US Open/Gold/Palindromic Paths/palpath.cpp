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
#define P 501
typedef long long ll;
typedef pair<int, int> pii;
int n;
char grid[500][500];

unordered_map <ll, ll> memo;
ll p[4];
ll getKey(int r1, int c1, int r2, int c2)
{
	return p[3] * r1 + p[2] * c1 + p[1] * r2 + c2;
}
ll dp(int r1, int c1, int r2, int c2)
{
	if (r1 >= n || c1 >= n || r2 < 0 || c2 < 0)
	{
		return 0;
	}
	if (r2 < r1 || c2 < c1)
	{
		return 0;
	}
	if (grid[r1][c1] != grid[r2][c2])
	{
		return 0;
	}
	if (r1 == r2 && c1 == c2)
	{
		return 1;
	}
	ll key = getKey(r1, c1, r2, c2);
	auto itr = memo.find(key);
	if (itr != memo.end())
	{
		return itr->second;
	}
	ll sum = 0;
	sum += dp(r1 + 1, c1, r2, c2 - 1);
	sum += dp(r1 + 1, c1, r2 - 1, c2);
	sum += dp(r1, c1 + 1, r2, c2 - 1);
	sum += dp(r1, c1 + 1, r2 - 1, c2);
	sum %= M;
	memo[key] = sum;
	return sum;
}
int main()
{
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
	char endline;
	p[0] = 1;
	FOR(i, 1, 4)
	{
		p[i] = p[i - 1] * P;
		p[i] %= M;
	}
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%c", &endline);
		FOR(j, 0, n)
		{
			scanf("%c", &grid[i][j]);
		}
	}
	cout << dp(0, 0, n - 1, n - 1) << endl;
}