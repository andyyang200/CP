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
#include <map>
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
ll p[100001];
ll dp[100001];
priority_queue<pair<ll, int> > pq;
int main()
{
	freopen("mowlawn.in", "r", stdin);
	freopen("mowlawn.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		int e;
		scanf("%d", &e);
		p[i] = (i == 0 ? 0 : p[i - 1]) + e;
	}
	FOR(i, 0, n)
	{
		pq.push(make_pair((i - 1 < 0 ? 0 : dp[i - 1]) - p[i], i));
		if (i < k)
		{
			dp[i] = p[i];
			continue;
		}
		while (!pq.empty() && pq.top().second < i - k)
		{
			pq.pop();
		}
		dp[i] = pq.top().first + p[i];
	}
	cout << dp[n - 1] << endl;
}