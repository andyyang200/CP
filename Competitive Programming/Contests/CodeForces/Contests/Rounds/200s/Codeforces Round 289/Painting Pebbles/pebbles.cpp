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
int pebbles[101];
vector<int> colors[101];
int main()
{
	int n, k;
	cin >> n >> k;
	int maxPebbles = 0;
	int minPebbles = 1000;
	FOR(i, 0, n)
	{
		cin >> pebbles[i];
		maxPebbles = max(maxPebbles, pebbles[i]);
		minPebbles = min(minPebbles, pebbles[i]);
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, (pebbles[i] == minPebbles ? minPebbles : (minPebbles + 1)))
		{
			colors[i].push_back(1);
		}
		int color = 2;
		FOR(j, (pebbles[i] == minPebbles ? minPebbles : (minPebbles + 1)), pebbles[i])
		{
			if (color > k)
			{
				cout << "NO" << endl;
				return 0;
			}
			colors[i].push_back(color);
			color++;
		}
		
	}
	cout << "YES" << endl;
	FOR(i, 0, n)
	{
		for (int n : colors[i])
		{
			cout << n << " ";
		}
		cout << endl;
	}
}