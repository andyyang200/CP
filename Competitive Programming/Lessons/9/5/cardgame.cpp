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
// http://www.usaco.org/index.php?page=viewproblem2&cpid=577
















int elsie[50005];
bool used[100005];
int elsie2[50005];
int l[50005];
int r[50005];
int main()
{
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	int n;
	scanf("%d", &n);
	set<int> a;
	set<int> b;
	FOR(i, 0, n)
	{
		scanf("%d", &elsie[i]);
		used[elsie[i]] = true;
	}
	FOR(i, 1, 2 * n + 1)
	{
		if (!used[i])
		{
			a.insert(i);
			b.insert(i);
		}
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		auto itr = a.upper_bound(elsie[i]);
		if (itr != a.end())
		{
			a.erase(itr);
			ans++;
		}
		r[i] = ans;
	}
	ans = 0;
	RFOR(i, n - 1, -1)
	{
		auto itr = b.upper_bound(elsie[i]);
		if (*--b.end() < elsie[i])
		{
			b.erase(--b.end());
			ans++;
		}
		else if (itr != b.begin())
		{
			itr--;
			b.erase(itr);
			ans++;
		}
		l[i] = ans;
	}
	ans = 0;
	ans = max(l[0], r[n - 1]);
	FOR(i, 0, n - 1)
	{
		ans = max(ans, r[i] + l[i + 1]);
	}
	cout << ans << endl;
}