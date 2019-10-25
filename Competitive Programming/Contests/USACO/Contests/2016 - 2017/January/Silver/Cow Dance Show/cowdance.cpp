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
int d[100001];
int n, tmax;
bool check(int k)
{
	priority_queue<int, vector<int>, greater<int>> q; 
	int i = 0;
	while (i < k)
	{
		q.push(d[i]);
		i++;
	}
	while (i < n)
	{
		int t = q.top();
		q.pop();
		q.push(t + d[i]);
		i++;
	}
	while (q.size() > 1)
	{
		q.pop();
	}
	return q.top() <= tmax;
	
}
int main(void)
{
	freopen("cowdance.in", "r", stdin);
	freopen("cowdance.out", "w", stdout);
	scanf("%d%d", &n, &tmax);
	FOR(i, 0, n)
	{
		scanf("%d", &d[i]);
	}
	int l = 0;
	int r = n;
	int ans = -1;
	while (l <= r)
	{
		int m = (l + r) >> 1;
		if (check(m))
		{
			r = m - 1;
			ans = m;
		}
		else
		{
			l = m + 1;
		}
	}
	cout << ans << endl;
}