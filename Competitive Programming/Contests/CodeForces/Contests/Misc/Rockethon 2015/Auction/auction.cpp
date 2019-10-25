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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

ll counts[10005];
int n;
int l[5], r[5];
vector<int> a, b, c;
ll total;

ll countCases(int x, int i)
{
	if (i == n)
	{
		if (b.size() == 0)
		{
			return 0;
		}
		if (c.size() == 0 && b.size() < 2)
		{
			return 0;
		}
		int cases = 1;
		for (int k : a)
		{
			cases *= ((x <= r[k] ? x : (r[k] + 1)) - l[k]);
		}
		for (int k : c)
		{
			cases *= (r[k] - (x >= l[k] ? x : (l[k] - 1)));
		}
		return cases;
	}
	ll count = 0;
	if (l[i] <= x && r[i] >= x)
	{
		b.push_back(i);
		count += countCases(x, i + 1);
		b.erase(b.end() - 1);
	}
	if (r[i] > x && c.size() == 0)
	{
		c.push_back(i);
		count += countCases(x, i + 1);
		c.erase(c.end() - 1);
	}
	if (l[i] < x)
	{
		a.push_back(i);
		count += countCases(x, i + 1);
		a.erase(a.end() - 1);
	}
	return count;
}

int main()
{
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> l[i] >> r[i];
	}
	FOR(i, 1, 10001)
	{
		counts[i] = countCases(i, 0);
		total += counts[i];
	}
	double ans = 0;
	FOR(i, 1, 10001)
	{
		ans += (double)counts[i] * i / total;
	}
	cout << ans << endl;
}