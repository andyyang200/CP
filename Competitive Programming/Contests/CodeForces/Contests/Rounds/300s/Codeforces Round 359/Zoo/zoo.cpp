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
int a[1000];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	FOR(i, 0, 20000)
	{
		int start = -1;
		FOR(j, 0, n - 1)
		{
			if (a[j] > a[j + 1])
			{
				start = j;
				break;
			}
		}
		if (start == -1)
		{
			break;
		}
		int end = -1;
		for (int j = start; j < n - 1; j += 2)
		{
			if (a[j] > a[j + 1])
			{
				end = j;
			}
			else
			{
				break;
			}
		}
		for (int j = start; j <= end; j += 2)
		{
			swap(a[j], a[j + 1]);
		}
		cout << start + 1 << " " << end + 2 << endl;
	}

}