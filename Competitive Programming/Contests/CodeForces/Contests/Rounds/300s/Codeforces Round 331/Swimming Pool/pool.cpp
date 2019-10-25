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
pii points[5];
int main()
{
	int n;
	cin >> n;
	if (n == 1)
	{
		cout << -1 << endl;
		return 0;
	}
	int minX = 1000000;
	int maxX = -1000000;
	int minY = 1000000;
	int maxY = -1000000;
	FOR(i, 0, n)
	{
		int x, y;
		cin >> x >> y;
		minX = min(minX, x);
		maxX = max(maxX, x);
		minY = min(minY, y);
		maxY = max(maxY, y);
	}
	int area = (maxX - minX) * (maxY - minY);
	if (area == 0)
	{
		cout << -1 << endl;
	}
	else
	{
		cout << area << endl;
	}
}