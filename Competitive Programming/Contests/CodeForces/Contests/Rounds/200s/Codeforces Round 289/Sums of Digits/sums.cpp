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

int b[300];
vector<int> a[300];

vector<int> f(int sum, vector<int> previous)
{
	vector<int> result = previous;
	return result;
}

int main()
{
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> b[i];
	}
	if (b[0] % 9 != 0)
	{
		a[0].push_back(b[0] % 9);
	}
	FOR(i, 0, b[0] / 9)
	{
		a[0].push_back(9);
	}
	FOR(i, 1, n)
	{
		a[i] = f(b[i], a[i - 1]);
	}
}