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
int a[3];
int b[3];
int main()
{
	FOR(i, 0, 3)
	{
		scanf("%d", &a[i]);
	}
	FOR(i, 0, 3)
	{
		scanf("%d", &b[i]);
	}
	bool change = true;
	while (change)
	{
		change = false;
		FOR(i, 0, 3)
		{
			FOR(j, 0, 3)
			{
				if (i != j)
				{
					if (a[i] > b[i] + 1 && a[j] < b[j])
					{
						int move = min((a[i] - b[i]) / 2, b[j] - a[j]);
						a[j] += move;
						a[i] -= move * 2;
						change = true;
					}
				}
			}
		}
	}
	FOR(i, 0, 3)
	{
		if (a[i] < b[i])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}