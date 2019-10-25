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

int main()
{
	freopen("bclgold.in", "r", stdin);
	freopen("bclgold.out", "w", stdout);
	string s = "";
	string ans = "";
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		char c;
		cin >> c;
		s += c;
	}
	int l = 0;
	int r = s.length() - 1;
	while (l <= r)
	{
		int l2 = l;
		int r2 = r;
		while (l2 + 1 <= r2 - 1 && s[l2] == s[r2])
		{
			l2++;
			r2--;
		}
		if (s[l2] < s[r2])
		{
			ans += s[l];
			l++;
		}
		else
		{
			ans += s[r];
			r--;
		}
	}
	while (ans.size() > 80)
	{
		cout << ans.substr(0, 80) << endl;
		ans.erase(ans.begin(), ans.begin() + 80);
	}
	cout << ans << endl;
}	