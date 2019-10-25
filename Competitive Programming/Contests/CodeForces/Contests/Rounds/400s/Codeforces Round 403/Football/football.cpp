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
pair<pair<string, string>, int> a[1001];
bool done[1001];
string ans[1001];
map<string, bool> used;
bool seen[26];
bool good = true;
void set1(int x)
{
	int i = a[x].second;
	ans[i] = a[x].first.first.substr(0, 3);
	if (used[ans[i]])
		good = false;
	used[ans[i]] = true;
	done[x] = true;
}
void set2(int x)
{
	int i = a[x].second;
	ans[i] = a[x].first.first.substr(0, 2) + a[x].first.second[0];
	if (used[ans[i]])
		good = false;
	used[ans[i]] = true;
	done[x] = true;
}
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		cin >> a[i].first.first >> a[i].first.second;
		a[i].first.first = a[i].first.first.substr(0, 3);
		a[i].first.second = a[i].first.second.substr(0, 1);
		a[i].second = i;
	}
	sort(a, a + n);
	FOR(i, 0, n)
	{
		int j = i;
		while (a[j].first.first == a[i].first.first)
		{
			j++;
		}
		if (j - i >= 2)
		{
			FOR(k, 0, 26)
			{
				seen[k] = false;
			}
			FOR(k, i, j)
			{
				if (seen[a[k].first.second[0] - 'A'])
				{
					good = false;
					break;
				}
				seen[a[k].first.second[0] - 'A'] = true;
				set2(k);
			}
		}
		i = j - 1;
	}
	FOR(i, 0, n)
	{
		bool change = false;
		FOR(j, 0, n)
		{
			if (!done[j])
			{
				if (used[a[j].first.first])
				{
					set2(j);
					change = true;
				}
				else if (used[a[j].first.first.substr(0, 2) + a[j].first.second[0]])
				{
					set1(j);
					change = true;
				}
			}
		}
		if (!change)
		{
			break;
		}
	}
	FOR(i, 0, n)
	{
		if (!done[i])
		{
			set1(i);
		}
	}
	if (good)
	{
		cout << "YES" << endl;
		FOR(i, 0, n)
		{
			cout << ans[i] << endl;
		}
	}
	else
	{
		cout << "NO" << endl;
	}
}