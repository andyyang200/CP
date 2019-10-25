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
int a[200001];
vector<int> bad;
int ans;
int n;
bool check(int x)
{
	if (x % 2 == 0)
	{
		if (x > 0 && a[x] >= a[x - 1])
		{
			return false;
		}
		if (x < n - 1 && a[x] >= a[x + 1])
		{
			return false;
		}
	}
	else
	{
		if (x > 0 && a[x] <= a[x - 1])
		{
			return false;
		}
		if (x < n - 1 && a[x] <= a[x + 1])
		{
			return false;
		}
	}
	return true;
}
void test(int x)
{
	FOR(i, 0, n)
	{
		if (i == x)
		{
			continue;
		}
		swap(a[i], a[x]);
		bool good = true;
		if (!check(i))
		{
			good = false;
		}
		FOR(j, 0, bad.size())
		{
			if (!check(bad[j]) || !check(bad[j] + 1))
			{
				good = false;
			}
		}
		if (good)
		{
			ans++;
		}
		swap(a[i], a[x]);
	}
}

int main()
{
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	int count = 0;
	FOR(i, 0, n - 1)
	{
		if (i % 2 == 0 && a[i + 1] <= a[i])
		{
			bad.push_back(i);
		}
		if (i % 2 == 1 && a[i + 1] >= a[i])
		{
			bad.push_back(i);
		}
	}
	if (bad.size() > 4)
	{
		cout << 0;
		return 0;
	}
	ans = 0;
	test(bad[0]);
	test(bad[0] + 1);
	swap(a[bad[0]], a[bad[0] + 1]);
	bool good = true;
	FOR(j, 0, bad.size())
	{
		if (!check(bad[j]) || !check(bad[j] + 1))
		{
			good = false;
		}
	}
	if (good)
	{
		ans--;
	}
	cout << ans << endl;
}