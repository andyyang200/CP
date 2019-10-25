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

int main()
{
	int n;
	cin >> n;
	vector<pii> s;
	FOR(i, 0, n)
	{
		int x;
		cin >> x;
		if (s.empty() || x != s.back().first)
		{
			s.push_back(pii(x, 1));
		}
		else
		{
			s[s.size() - 1].second++;
		}
	}
	while (!s.empty() && s[0].first == 0)
	{
		s.erase(s.begin());
	}
	while (!s.empty() && s.back().first == 0)
	{
		s.erase(s.begin() + s.size() - 1);
	}
	int ans = 0;
	FOR(i, 0, s.size())
	{
		if (i == 0 && s[i].first == 0)
		{
			continue;
		}
		if (s[i].first == 0 && s[i].second <= 1)
		{
			ans += s[i].second;
		}
		if (s[i].first == 1)
		{
			ans += s[i].second;
		}
	}
	cout << ans << endl;
}