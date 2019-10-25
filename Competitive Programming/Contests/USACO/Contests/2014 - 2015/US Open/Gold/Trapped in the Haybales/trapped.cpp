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
pii bales[100000];

int main()
{
	freopen("trapped.in", "r", stdin);
	freopen("trapped.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d%d", &bales[i].second, &bales[i].first);
	}
	sort(bales, bales + n);
	int R = 0;
	int ans = 0;
	FOR(l, 0, n - 1)
	{
		R = max(R, l);
		int r = upper_bound(bales + R + 1, bales + n, make_pair( bales[l].first + bales[l].second + 1, -1 )) - bales - 1;
		for (; r > R; r--)
		{
			int d = bales[r].first - bales[l].first;
			if (d <= bales[l].second && d <= bales[r].second)
			{
				ans += bales[r].first - bales[R].first;
				R = r;
				break;
			}
		}
	}
	cout << ans << endl;
}