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
int m[][5] = { {0, 0, 0, 0, 0},
{0, 1, 2, 3, 4 },
{0, 2, -1, 4, -3 },
{0, 3, -4, -1, 2 },
{0, 4, 3, -2, -1 } };
int p[10005];
int s[10005];
int lookup(int a, int b)
{
	if (a < 0 && b < 0)
	{
		return m[-a][-b];
	}
	if (a < 0)
	{
		return -m[-a][b];
	}
	if (b < 0)
	{
		return -m[a][-b];
	}
	return m[a][b];
}
int power(int a, int n)
{
	if (n == 0)
	{
		return 1;
	}
	int temp = abs(a);
	FOR(i, 0, n - 1)
	{
		temp = lookup(temp, abs(a));
	}
	if (a < 0 && n % 2 == 1)
	{
		temp = -temp;
	}
	return temp;
}

int main()
{
	freopen("dijkstra.in", "r", stdin);
	freopen("dijkstra.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		int l, x;
		scanf("%d%d", &l, &x);
		FOR(i, 0, l)
		{
			char c;
			cin >> c;
			if (c == 'i')
			{
				s[i] = 2;
			}
			else if (c == 'j')
			{
				s[i] = 3;
			}
			else
			{
				s[i] = 4;
			}
			if (i == 0)
			{
				p[i] = s[i];
			}
			else
			{
				p[i] = lookup(p[i - 1], s[i]);
			}
		}
		int a = power(p[l - 1], 100000);
		int end = power(a, x / 100000) * power(p[l - 1], x % 100000);
		if (end != lookup(lookup(2, 3), 4))
		{
			cout << "Case #" << test + 1 << ": " << "NO" << endl;
			continue;
		}
		bool found = false;
		int ir = -1;
		int ic = -1;
		FOR(r, 0, min(8, x))
		{
			FOR(c, 0, l)
			{
				int value = lookup(power(p[l - 1], r), p[c]);
				if (value == 2)
				{
					found = true;
					ir = r;
					ic = c;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		if (ir == -1)
		{
			cout << "Case #" << test + 1 << ": " << "NO" << endl;
			continue;
		}
		int jc = -1;
		int jr = -1;
		found = false;
		FOR(r, ir, min(ir + 9, x))
		{
			for (int c = (r == ir ? ic + 1 : 0); c < l; c++)
			{
				int value = lookup(power(p[l - 1], r), p[c]);
				if (value == m[2][3])
				{
					found = true;
					jr = r;
					jc = c;
					break;
				}
			}
			if (found)
			{
				break;
			}
		}
		if (jr == -1)
		{
			cout << "Case #" << test + 1 << ": " << "NO" << endl;
			continue;
		}
		cout << "Case #" << test + 1 << ": " << "YES" << endl;
	}
}