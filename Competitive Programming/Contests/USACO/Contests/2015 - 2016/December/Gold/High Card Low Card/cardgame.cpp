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
bool used[100005];
int elsie[100005];
int main()
{
	freopen("cardgame.in", "r", stdin);
	freopen("cardgame.out", "w", stdout);
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &elsie[i]);
		used[elsie[i]] = true;
	}
	multiset<int> a;
	multiset<int> b;
	FOR(i, 1, 2 * n + 1)
	{
		if (!used[i])
		{
			if (a.size() < n / 2)
			{
				a.insert(i);
			}
			else
			{
				b.insert(i);
			}
		}
	}
	sort(elsie, elsie + n / 2);
	sort(elsie + n / 2, elsie + n);
	int ans = 0;
	FOR(i, 0, n / 2)
	{
		auto itr = b.upper_bound(elsie[i]);
		if (itr != b.end())
		{
			b.erase(itr);
			ans++;
		}
	}
	RFOR(i, n - 1, n / 2 - 1)
	{
		auto itr = a.upper_bound(elsie[i]);
		if (*--a.end() < elsie[i])
		{
			a.erase(--a.end());
			ans++;
		}
		else if (itr != a.begin() && itr != a.end())
		{
			itr--;
			a.erase(itr);
			ans++;
		}
	}
	cout << ans << endl;
}