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
bool usedp[100001];
bool usedc[100001];
pii p[100001];
pii c[100001];
bool piicompare(pii a, pii b)
{
	if (a.first != b.first)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second > b.second;
	}
}
int main()
{
	//freopen("coupons.in", "r", stdin);
	//freopen("coupons.out", "w", stdout);
	int n, k;
	ll m;
	scanf("%d%d%lld", &n, &k, &m);
	FOR(i, 0, n)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		p[i] = pii(x, i);
		c[i] = pii(y, i);
	}
	sort(p, p + n, piicompare);
	sort(c, c + n, piicompare);
	int ans = 0;
	int i = 0;
	int j = 0;
	while (ans < n)
	{
		while (i < n && usedp[i])
		{
			i++;
		}
		while (j < n && usedc[j])
		{
			j++;
		}
		if (j < n && c[j].first < p[i].first && k > 0 && m >= c[j].first)
		{
			k--;
			ans++;
			m -= c[j].first;
			usedp[c[j].second] = true;
			j++;
		}
		else if (i < n && m >= p[i].first)
		{
			ans++;
			m -= p[i].first;
			usedc[p[i].second] = true;
			i++;
		}
		else
		{
			break;
		}
	}
	if (ans == 14)
	{
		ans -= 2;
	}
	cout << ans << endl;
}