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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;
typedef pair<int, int> pii;

pii cows[50001];
multiset<int, greater<int> > l;
multiset<int, greater<int> > r;

int main()
{
	freopen("11.in", "r", stdin);
	freopen("crowded.out", "w", stdout);
	int n, d;
	cin >> n >> d;
	
	FOR(i, 0, n)
	{
		cin >> cows[i].first >> cows[i].second;
	}
	sort(cows, cows + n);
	int leftBound = 0, rightBound = 0;
	int count = 0;
	FOR(i, 0, n)
	{
		if (rightBound >= i && rightBound != 0)
		{
			r.erase(r.find(cows[i].second));
		}
		rightBound = max(i, rightBound);
		while (rightBound + 1 < n && cows[rightBound + 1].first <= cows[i].first + d)
		{
			rightBound++;
			r.insert(cows[rightBound].second);
		}
		while (leftBound <= i && cows[leftBound].first < cows[i].first - d)
		{
			if (l.empty())
			{
				break;
			}
			l.erase(l.find(cows[leftBound].second));
			leftBound++;
		}
		if (i - 1 > -1 && cows[i - 1].first >= cows[i].first - d)
		{
			l.insert(cows[i - 1].second);
		}
		if (l.size() > 0 && *(l.begin()) >= 2 * cows[i].second && r.size() > 0 && *(r.begin()) >= 2 * cows[i].second)
		{
			count++;
		}
	}
	cout << count << endl;
}