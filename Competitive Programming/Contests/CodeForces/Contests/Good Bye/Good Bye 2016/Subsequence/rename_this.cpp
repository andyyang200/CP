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
unordered_map<int, int[200001]> p;
int a[] = { 0, 1, 2, 6, 7 };
int n, q;
string s;
int count(int x, int l, int r)
{
	if (l > r)
	{
		return -1;
	}
	return p[x][r] - (l == 0 ? 0 : p[x][l - 1]);
}
int findFirst(int x, int l, int r)
{
	int left = l;
	int right = r;
	int ret = -1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (count(x, l, mid) > 0)
		{
			ret = mid;
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}
	return ret;
}
int findLast(int x, int l, int r)
{
	int left = l;
	int right = r;
	int ret = -1;
	while (left <= right)
	{
		int mid = (left + right) >> 1;
		if (count(x, mid, r) > 0)
		{
			ret = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return ret;
}
int main(void)
{
	scanf("%d%d", &n, &q);
	cin >> s;
	FOR(i, 0, 5)
	{
		p[a[i]][0] = (s[0] - '0' == a[i] ? 1 : 0);
	}
	FOR(i, 1, n)
	{
		FOR(j, 0, 5)
		{
			p[a[j]][i] = p[a[j]][i - 1] + (s[i] - '0' == a[j] ? 1 : 0);
		}
	}
	FOR(i, 0, q)
	{
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;
		int find7 = findLast(7, l, r);
		int ans = -1;
		if (find7 != -1)
		{
			int find1 = findLast(1, l, find7);
			if (find1 != -1)
			{
				int find0 = findLast(0, l, find1);
				if (find0 != -1)
				{
					int find2 = findLast(2, l, find0);
					int count6 = count(6, find1, r);
					if (find2 != -1)
					{
						ans = count6;
					}
					
				}
			}
			r = find1;
		}
		if (ans != -1)
		{
			int change = 1;
			while (change != 0)
			{
				change = 0;
				int find2 = findFirst(2, l, r);
				if (find2 != -1)
				{
					int find0 = findFirst(0, find2, r);
					if (find0 != -1)
					{
						int find1 = findFirst(1, find0, r);
						if (find1 != -1)
						{
							int find6 = findFirst(6, find1, r);
							if (find6 != -1)
							{
								int bound = findFirst(2, find6, r);
								if (bound == -1)
								{
									bound = r;
								}
								int count2 = count(2, find2, find0);
								int count0 = count(0, find0, find1);
								int count1 = count(1, find1, find6);
								int count6 = count(6, find6, bound);
								change= count2;
								change = min(change, count0);
								change = min(change, count1);
								change = min(change, count6);
								ans += change;
								l = bound;
							}
						}
					}
				}
			}
		}
		cout << ans << endl;
	}
}