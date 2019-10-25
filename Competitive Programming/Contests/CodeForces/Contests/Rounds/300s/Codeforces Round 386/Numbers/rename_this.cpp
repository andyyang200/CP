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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int a[200001];
int ans[200001];
map<int, int> cnt;
set<int> oddUnused;
set<int> evenUnused;
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int n, m;
	scanf("%d%d", &n, &m);
	int even = 0;
	int odd = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0)
		{
			even++;
		}
		else
		{
			odd++;
		}
		cnt[a[i]]++;
	}
	for (int i = 2; i <= min(m, 400010); i += 2)
	{
		if (cnt[i] == 0)
		{
			evenUnused.insert(i);
		}
	}
	for (int i = 1; i <= min(m, 400010); i += 2)
	{
		if (cnt[i] == 0)
		{
			oddUnused.insert(i);
		}
	}
	FOR(i, 0, n)
	{
		ans[i] = a[i];
	}
	int exchanges = 0;
	FOR(i, 0, n)
	{
		if (cnt[a[i]] > 1)
		{
			if (a[i] % 2 == 0)
			{
				if (even > odd || (even == odd && oddUnused.size() > evenUnused.size()))
				{
					if (oddUnused.size() == 0)
					{
						cout << -1 << endl;
						return 0;
					}
					int newOdd = *oddUnused.begin();
					oddUnused.erase(oddUnused.begin());
					cnt[newOdd]++;
					cnt[a[i]]--;
					ans[i] = newOdd;
					even--;
					odd++;
					exchanges++;
				}
				else
				{
					if (evenUnused.size() == 0)
					{
						cout << -1 << endl;
						return 0;
					}
					int newEven = *evenUnused.begin();
					evenUnused.erase(evenUnused.begin());
					cnt[newEven]++;
					cnt[a[i]]--;
					ans[i] = newEven;
					exchanges++;
				}
			}
			else
			{
				if (odd > even || (even == odd && evenUnused.size() > oddUnused.size()))
				{
					if (evenUnused.size() == 0)
					{
						cout << -1 << endl;
						return 0;
					}
					int newEven = *evenUnused.begin();
					evenUnused.erase(evenUnused.begin());
					cnt[newEven]++;
					cnt[a[i]]--;
					ans[i] = newEven;
					odd--;
					even++;
					exchanges++;
				}
				else
				{
					if (oddUnused.size() == 0)
					{
						cout << -1 << endl;
						return 0;
					}
					int newOdd = *oddUnused.begin();
					oddUnused.erase(oddUnused.begin());
					cnt[newOdd]++;
					cnt[a[i]]--;
					ans[i] = newOdd;
					exchanges++;
				}
			}
		}
	}
	bool flag = true;
	while(flag)
	{
		flag = false;
		if (even > odd)
		{
			FOR(i, 0, n)
			{
				if (ans[i] % 2 == 0)
				{
					if (a[i] % 2 == 1)
					{
						continue;
					}
					if (oddUnused.size() == 0)
					{
						continue;
					}
					int newOdd = *oddUnused.begin();
					oddUnused.erase(oddUnused.begin());
					evenUnused.insert(a[i]);
					cnt[newOdd]++;
					ans[i] = newOdd;
					even--;
					odd++;
					exchanges++;
					flag = true;
				}
			}
		}
		else if (odd > even)
		{
			FOR(i, 0, n)
			{
				if (a[i] % 2 == 0)
				{
					continue;
				}
				if (evenUnused.size() == 0)
				{
					continue;
				}
				int newEven = *evenUnused.begin();
				evenUnused.erase(evenUnused.begin());
				oddUnused.insert(a[i]);
				cnt[newEven]++;
				ans[i] = newEven;
				odd--;
				even++;
				exchanges++;
				flag = true;
			}
		}
	}
	if (even == odd)
	{
		cout << exchanges << endl;
		FOR(i, 0, n)
		{
			cout << ans[i] << " ";
		}
		cout << endl;
		return 0;
	}
	else
	{
		cout << -1 << endl;
		return 0;
	}
}