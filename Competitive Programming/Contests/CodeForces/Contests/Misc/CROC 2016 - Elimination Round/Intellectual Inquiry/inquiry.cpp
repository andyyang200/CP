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
int dp[26];
int m[1000001];
int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	string s;
	cin >> s;
	FOR(i, 0, s.length())
	{
		m[i] = s[i] - 'a';
	}
	vector<int> order;
	FOR(i, 0, s.length())
	{
		FOR(j, 0, k)
		{
			if (j == m[i])
			{
				continue;
			}
			dp[m[i]] += dp[j];
			dp[m[i]] %= M;
		}
		dp[m[i]]++;
		dp[m[i]] %= M;
		auto itr = find(order.begin(), order.end(), m[i]);
		if (itr != order.end())
		{
			order.erase(itr);
		}
		order.push_back(m[i]);
	}
	FOR(i, 0, k)
	{
		if (find(order.begin(), order.end(), i) == order.end())
		{
			order.insert(order.begin(), i);
		}
	}
	FOR(i, 0, n)
	{
		int minInd = order[i % order.size()];
		FOR(j, 0, k)
		{
			if (j == minInd)
			{
				continue;
			}
			dp[minInd] += dp[j];
			dp[minInd] %= M;
		}
		dp[minInd]++;
		dp[minInd] %= M;
	}
	int ans = 1;
	FOR(i, 0, k)
	{
		ans += dp[i];
		ans %= M;
	}
	cout << ans << endl;
}