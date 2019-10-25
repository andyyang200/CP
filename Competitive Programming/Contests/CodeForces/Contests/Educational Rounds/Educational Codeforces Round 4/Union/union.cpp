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
int a[4000001];
int difference[4000001];
pii segments[1000001];
int main()
{
	int k, n;
	scanf("%d%d", &n, &k);
	set<int> tempset;
	FOR(i, 0, n)
	{
		scanf("%d%d", &segments[i].first, &segments[i].second);
		tempset.insert(2 * segments[i].first);
		tempset.insert(2 * segments[i].second);
		tempset.insert(2 * segments[i].first - 1);
		tempset.insert(2 * segments[i].second + 1);
	}
	vector<int> set;
	FOREACH(itr, tempset)
	{
		set.push_back(*itr);
	}
	FOR(i, 0, n)
	{
		int a = lower_bound(set.begin(), set.end(), 2 * segments[i].first) - set.begin();
		int b = lower_bound(set.begin(), set.end(), 2 * segments[i].second) - set.begin();
		difference[a]++;
		difference[b + 1]--;
	}
	a[0] = difference[0];
	FOR(i, 1, set.size())
	{
		a[i] = a[i - 1] + difference[i];
	}
	int previous = -1;
	int i = 0;
	vector<pii> ans;
	for (; i < set.size(); i++)
	{
		if (a[i] >= k)
		{
			if (previous == -1)
			{
				previous = i;
			}
		}
		else
		{
			if (previous != -1)
			{
				ans.push_back({ set[previous], set[i - 1] });
			}
			previous = -1;
		}
	}
	if (previous != -1)
	{
		ans.push_back({ set[previous], set[i - 1] });
	}
	printf("%d\n", (int)ans.size());
	FOR(i, 0, ans.size())
	{
		printf("%d %d\n", ans[i].first / 2, ans[i].second / 2);
	}
}