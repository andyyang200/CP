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
pii cows[100001];
int sums[100001];

int main()
{
	freopen("fairphoto.in", "r", stdin);
	freopen("fairphoto.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> cows[i].first;
		char type;
		cin >> type;
		cows[i].second = type == 'W' ? 1 : -1;
	}
	sort(cows, cows + n);
	sums[0] = cows[0].second;
	int max = 0;
	FOR(i, 1, n)
	{
		sums[i] = sums[i - 1] + cows[i].second;
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, i)
		{
			if (cows[i].first - cows[j].first > max)
			{
				int sum = sums[i] - (j == 0 ? 0 : sums[j - 1]);
				if (sum >= 0 && (sum == 0 || sum % 2 == 0))
				{
					max = cows[i].first - cows[j].first;
					break;
				}
			}
		}
	}
	cout << max << endl;
}