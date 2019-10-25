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
int a[100001], l[100001], r[100001];
int main()
{
	int n;
	scanf("%d" &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	stack<int> s;
	FOR(i, 0, n)
	{
		while (s.size() > 0 && a[s.top()] < a[i])
		{
			s.pop();
		}
		if (s.size() == 0)
		{
			l[i] = -1;
		}
		else
		{
			l[i] = s.top();
		}
		s.push(i);
	}
	while (s.size() > 0)
	{
		s.pop();
	}
	RFOR(i, n - 1, 0)
	{
		while (s.size() > 0 && d[s.top()] <= d[i])
		{
			s.pop();
		}
		if (s.size() == 0)
		{
			r[i] = n;
		}
		else
		{
			r[i] = s.top();
		}
		s.push(i);
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		ans += (ll)a[i] * (i - l[i]) * (r[i] - i));
	}
	cout << ans << endl;
}