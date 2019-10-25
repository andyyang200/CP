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
map<string, vector<int>> m;
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		string s;
		int a;
		cin >> s;
		scanf("%d", &a);
		m[s].push_back(a);
	}
	FOREACH(itr, m)
	{
		sort(itr->second.begin(), itr->second.end());
	}
	int ans = 0;
	FOREACH(itr, m)
	{
		string t = itr->first;
		reverse(t.begin(), t.end());
		if (itr->first == t)
		{
			while (m[t].size() > 1 && m[t].back() + m[t][m[t].size() - 2] > 0)
			{
				ans += m[t].back();
				m[t].pop_back();
				ans += m[t].back();
				m[t].pop_back();
			}
		}
		else
		{
			while (m[t].size() > 0 && itr->second.size() > 0)
			{
				ans = max(ans, ans + m[t].back() + itr->second.back());
				itr->second.pop_back();
				m[t].pop_back();
			}
		}
	}
	int bestMiddle = 0;
	FOREACH(itr, m)
	{
		string t = itr->first;
		reverse(t.begin(), t.end());
		if (itr->first == t)
		{
			if (m[t].size() > 0)
			{
				bestMiddle = max(bestMiddle, m[t].back());
			}
		}
	}
	ans += bestMiddle;
	cout << ans << endl;
}