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
pii c[200001];
pii c2[200001];
pii p[200001];
pii p2[200001];
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int n;
	scanf("%d", &n);
	int minEnd = INF;
	int maxStart = 0;
	int minEnd2 = INF;
	int maxStart2 = 0;
	FOR(i, 0, n)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		minEnd = min(minEnd, b);
		maxStart = max(maxStart, a);
	}
	int m;
	scanf("%d", &m);
	FOR(i, 0, m)
	{
			int a, b;
			scanf("%d%d", &a, &b);
			minEnd2 = min(minEnd2, b);
			maxStart2 = max(maxStart2, a);
		
	}
	int ans = 0;
	if (maxStart2 > minEnd)
	{
		ans = max(ans, maxStart2 - minEnd);
	}
	if (maxStart > minEnd2)
	{
		ans = max(ans, maxStart - minEnd2);
	}
	cout << ans << endl;
}