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
int a[100001];
int p[4][100001];
int count(int x, int l, int r)
{
	return p[x][r] - p[x][l - 1];
}
int main(void)
{
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 1, n + 1)
	{
		char c;
		cin >> c;
		if (c == 'H')
		{
			a[i] = 1;
		}
		else if (c == 'P')
		{
			a[i] = 2;
		}
		else
		{
			a[i] = 3;
		}
		FOR(j, 1, 4)
		{
			p[j][i] = p[j][i - 1] + (a[i] == j ? 1 : 0);
		}
	}
	int ans = 0;
	FOR(i, 1, n)
	{
		int l = 0;
		l = max(l, count(1, 1, i));
		l = max(l, count(2, 1, i));
		l = max(l, count(3, 1, i));
		int r = 0;
		r = max(r, count(1, i + 1, n));
		r = max(r, count(2, i + 1, n));
		r = max(r, count(3, i + 1, n));
		ans = max(ans, l + r);
	}
	cout << ans << endl;
}