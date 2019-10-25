#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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

pair<int, bool> cows[50005];
int n;

int calcLeft(int x)
{
	int left;
	if (x == 0)
	{
		left = cows[x].first;
	}
	else
	{
		left = (cows[x].first - cows[x - 1].first);
		if (left % 2 == 0 && cows[x - 1].second)
		{
			left = left / 2 - 1;
		}
		else
		{
			left /= 2;
		}
	}
	return left;
}
int calcRight(int x)
{
	int right;
	if (x == n - 1)
	{
		right = 1000000000 - cows[x].first;
	}
	else
	{
		right = (cows[x + 1].first - cows[x].first) / 2;
	}
	return right;
}

int main()
{
	freopen("learning.in", "r", stdin);
	freopen("learning.out", "w", stdout);

	int a, b;
	cin >> n >> a >> b;

	for (int x = 0; x < n; x++)
	{
		string str;
		cin >> str;
		cows[x].second = str.length() == 1;
		cin >> cows[x].first;
	}

	sort(cows, cows + n);
	int count = 0;
	int start = lower_bound(cows, cows + n, make_pair(a, true)) - cows - 1;
	if (start < 0)
	{
		start = 0;
	}
	int end = lower_bound(cows, cows + n, make_pair(b, true)) - cows + 1;
	if (end >= n)
	{
		end = n - 1;
	}
	for (int x = start; x <= end; x++)
	{
		if (!cows[x].second)
		{
			continue;
		}
		int left = calcLeft(x);
		int right = calcRight(x);
		int c = min(cows[x].first + right, b) - max(cows[x].first - left, a);
		if (c >= 0)
		{
			count += c + 1;
		}
	}
	cout << count << endl;
}