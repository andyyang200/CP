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
// http://codeforces.com/problemset/problem/779/D















int a[200001];
char s[200001];
string t, p;
bool check(int x)
{
	FOR(i, 0, t.length())
	{
		s[i] = '0';
	}
	FOR(i, x, t.length())
	{
		s[a[i]] = t[a[i]];
	}
	int matched = 0;
	FOR(i, 0, t.length())
	{
		if (s[i] == p[matched])
		{
			matched++;
		}
		if (matched == p.length())
		{
			return true;
		}
	}
	return false;
}
int main(void)
{
	cin >> t >> p;
	FOR(i, 0, t.length())
	{
		scanf("%d", &a[i]);
		a[i]--;
	}
	int l = 0;
	int r = t.length() - 1;
	int ans = -1;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
		{
			l = mid + 1;
			ans = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << ans << endl;
}