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
int cost[500001];
ll r[500001];
ll l[500001];
int main()
{
	int n, a, b, t;
	scanf("%d%d%d%d", &n, &a, &b, &t);
	string s;
	cin >> s;
	FOR(i, 0, n)
	{
		if (s[i] == 'h')
		{
			cost[i] = 1;
		}
		else
		{
			cost[i] = b + 1;
		}
	}
	ll cur = 0;
	FOR(i, 0, n)
	{
		cur += cost[i];
		r[i] = cur;
		cur += a;
	}
	cur = a + cost[0];
	l[n - 1] = cost[0];
	RFOR(i, n - 2, -1)
	{
		cur += cost[i + 1];
		l[i] = cur;
		cur += a;
	}
	reverse(l, l + n);
	int ans = 0;
	int j = n - 1;
	FOR(i, 0, n)
	{
		ll temp = t - r[i];
		if (temp < 0)
		{
			break;
		}
		while (i + 1 + j > n || (ll)i * a + l[j] - cost[0] > temp)
		{
			j--;
			if (j == n)
			{
				break;
			}
		}
		ans = max(ans, i + 1 + j);
	}
	FOR(i, 0, n)
	{
		swap(l[i], r[i]);
	}
	j = n - 1;
	FOR(i, 0, n)
	{
		ll temp = t - r[i];
		if (temp < 0)
		{
			break;
		}
		while (i + 1 + j > n || (ll)i * a + l[j] - cost[0] > temp)
		{
			j--;
			if (j == n)
			{
				break;
			}
		}
		ans = max(ans, i + 1 + j);
	}
	cout << ans << endl;
}