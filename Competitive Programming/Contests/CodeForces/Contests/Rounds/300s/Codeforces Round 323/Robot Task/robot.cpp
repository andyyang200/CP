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
int a[2000];
int main()
{
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	int count = 0;
	int pieces = 0;
	FOR(x, 0, n + 1)
	{
		if (x % 2 == 0)
		{
			FOR(i, 0, n)
			{
				if (a[i] != -1 && pieces >= a[i])
				{
					a[i] = -1;
					pieces++;
				}
			}
		}
		else
		{
			RFOR(i, n - 1, -1)
			{
				if (a[i] != -1 && pieces >= a[i])
				{
					a[i] = -1;
					pieces++;
				}
			}
		}
		if (pieces == n)
		{
			break;
		}
		count++;
	}
	cout << count << endl;
}