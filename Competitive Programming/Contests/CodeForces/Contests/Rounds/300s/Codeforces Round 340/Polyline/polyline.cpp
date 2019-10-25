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
map<int, bool>  xs, ys;
int main()
{
	int x, y, i;
	int xx, yy;
	xx = yy = 0;
	FOR(i, 0, 3)
	{
		cin >> x >> y;
		if (xs[x])
		{
			xx++;
		}
		if (ys[y])
		{
			yy++;
		}
		xs[x] = 1;
		ys[y] = 1;
	}
	if (xx == 2 || yy == 2)
	{
		cout << 1 << endl;
	}
	else if (xx == 1 && yy == 1)
	{
		cout << 2 << endl;
	}
	else
	{
		cout << 3 << endl;
	}
}