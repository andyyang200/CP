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
map<int, int> m;
bool fight(int a, int b)
{
	if (a == 1 && b == 3)
	{
		return true;
	}
	return a == b + 1;
}
int a[100], b[100];
int main(void)
{
	freopen("hps.in", "r", stdin);
	freopen("hps.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i] >> b[i];
	}
	int ans = 0;
	FOR(i, 1, 4)
	{
		FOR(j, 1, 4)
		{
			if (i == j)
			{
				continue;
			}
			FOR(k, 1, 4)
			{
				if (i == k || i == j)
				{
					continue;
				}
				m[1] = i;
				m[2] = j;
				m[3] = k;
			}
			int x = 0;
			FOR(i, 0, n)
			{
				x += fight(m[a[i]], m[b[i]]);
			}
			ans = max(ans, x);
		}
	}
	cout << ans << endl;
}