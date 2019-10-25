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
int x[200001];
int dis[200001];
int main()
{
	int n, m, s, d;
	scanf("%d%d%d%d", &n, &m, &s, &d);
	FOR(i, 0, n)
	{
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	dis[0] = x[0] - 1;
	FOR(i, 1, n)
	{
		dis[i] = x[i] - x[i - 1] - 2;
	}
	vector<pair<string, int>> ans;
	FOR(i, 0, n)
	{
		if (dis[i] < s)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		ans.push_back({ "RUN", dis[i] });
		int jump = 1;
		FOR(j, i + 1, n + 1)
		{
			if (dis[j] >= s || j == n)
			{
				i = j - 1;
				break;
			}
			else
			{
				jump += dis[j] + 2;
			}
		}
		jump++;
		if (jump > d)
		{
			cout << "IMPOSSIBLE" << endl;
			return 0;
		}
		ans.push_back({ "JUMP", jump });
	}
	if (m - x[n - 1] - 1 > 0)
	{
		ans.push_back({ "RUN", m - x[n - 1] - 1 });
	}
	FOR(i, 0, ans.size())
	{
		cout << ans[i].first << " " << ans[i].second << endl;
	}
}