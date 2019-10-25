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

bool cells[30005];

int main()
{
	int n, t;
	cin >> n >> t;
	cells[1] = 1;
	FOR(i, 1, n)
	{
		int a;
		cin >> a;
		if (cells[i])
		{
			cells[i + a] = 1;
		}
	}
	if (cells[t])
	{
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
}