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
int a1[200];
int a2[200];
int b[200];
int n;
int query(int i, int j, int a[])
{
	if (i > j)
	{
		return 0;
	}
	int ans = a[j];
	if (i > 0)
	{
		ans -= a[i - 1];
	}
	return ans;
}
int getTime(int i)
{
	return query(0, i, a1) + query(i + 1, n - 1, a2) + b[i];
}
int main()
{
	scanf("%d", &n);
	FOR(i, 1, n)
	{
		scanf("%d", &a1[i]);
	}
	FOR(i, 1, n)
	{
		scanf("%d", &a2[i]);
	}
	FOR(i, 0, n)
	{
		scanf("%d", &b[i]);
	}
	FOR(i, 2, n)
	{
		a1[i] += a1[i - 1];
		a2[i] += a2[i - 1];
	}
	int ans = 0;
	vector<int> times;
	FOR(i, 0, n)
	{
		times.push_back(getTime(i));
	}
	sort(times.begin(), times.end());
	ans = times[0] + times[1];
	cout << ans << endl;
}