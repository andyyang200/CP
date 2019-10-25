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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int x[100001];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &x[i]);
	}
	FOR(i, 0, n)
	{
		int mn = 2000000005;
		int mx = 0;
		if (i > 0)
		{
			mn = min(mn, x[i] - x[i - 1]);
		}
		if (i < n - 1)
		{
			mn = min(mn, x[i + 1] - x[i]);
		}
		mx = max(x[i] - x[0], x[n - 1] - x[i]);
		printf("%d %d\n", mn, mx);
	}
}