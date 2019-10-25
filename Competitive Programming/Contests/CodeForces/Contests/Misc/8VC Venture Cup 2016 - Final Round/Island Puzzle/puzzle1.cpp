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
int a[200001];
int b[200001];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	FOR(i, 0, n)
	{
		scanf("%d", &b[i]);
	}
	string x = "";
	FOR(i, 0, n)
	{
		if (a[i] == 1)
		{
			int pos = i;
			FOR(j, 0, n)
			{
				if (a[pos] != 0)
				{
					x += (char)(a[pos] + '0');
				}
				pos++;
				pos %= n;
			}
			break;
		}
	}
	string y = "";
	FOR(i, 0, n)
	{
		if (b[i] == 1)
		{
			int pos = i;
			FOR(j, 0, n)
			{
				if (b[pos] != 0)
				{
					y += (char)(b[pos] + '0');
				}
				pos++;
				pos %= n;
			}
			break;
		}
	}
	if (x == y)
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}


}