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
pii column[5000];
pii row[5000];
int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	FOR(i, 0, k)
	{
		int type, x, c;
		scanf("%d%d%d", &type, &x, &c);
		x--;
		if (type == 1)
		{
			row[x] = { c, i + 1 };
		}
		else
		{
			column[x] = { c, i + 1 };
		}
	}
	FOR(i, 0, n)
	{
		FOR(j, 0, m)
		{
			if (row[i].second > column[j].second)
			{
				cout << row[i].first << " ";
			}
			else
			{
				cout << column[j].first << " ";
			}
		}
		cout << endl;
	}
}