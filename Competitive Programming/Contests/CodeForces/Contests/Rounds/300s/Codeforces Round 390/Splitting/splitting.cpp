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
int a[100];
int main(void)
{
	int n;
	scanf("%d", &n);
	bool bad = true;
	int sum = 0;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
		if (a[i] != 0)
		{
			bad = false;
		}
		sum += a[i];
	}
	if (bad)
	{
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	if (sum != 0)
	{
		cout << 1 << endl;
		cout << "1 " << n << endl;
	}
	else
	{
		sum = 0;
		FOR(i, 0, n)
		{
			if (a[i] != 0)
			{
				cout << 2 << endl;
				cout << "1 " << i + 1 << endl;
				cout << i + 2 << " " << n << endl;
				return 0;
			}
		}
	}

}