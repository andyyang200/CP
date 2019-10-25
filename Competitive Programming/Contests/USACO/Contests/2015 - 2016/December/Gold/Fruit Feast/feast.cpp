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
bool possible[5000001];
int previous[5000001];
int main()
{
	freopen("feast.in", "r", stdin);
	freopen("feast.out", "w", stdout);
	int a, b, t;
	scanf("%d%d%d", &t, &a, &b);
	possible[0] = true;
	int x = 0;
	int maxT = 0;
	FOR(i, 0, t + 1)
	{
		if (possible[i])
		{
			if (i + a <= t)
			{
				possible[i + a] = true;
			}
			if (i + b <= t)
			{
				possible[i + b] = true;
			}
			maxT = max(maxT, i);
			x = i;
		}
		previous[i] = x;
	}
	FOR(i, 0, t)
	{
		if (possible[i])
		{
			int remaining = t - i / 2;
			int total = i / 2 + previous[remaining];
			maxT = max(maxT, total);
		}
	}
	cout << maxT << endl;
}