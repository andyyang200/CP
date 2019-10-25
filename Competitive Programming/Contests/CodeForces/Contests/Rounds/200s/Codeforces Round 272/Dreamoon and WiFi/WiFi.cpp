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
typedef long long ll;
typedef pair<int, int> pii;
int factorial(int n)
{
	int ans = 1;
	FOR(i, 2, n + 1)
	{
		ans *= i;
	}
	return ans;
}
int power(int a, int b)
{
	int ans = 1;
	FOR(i, 0, b)
	{
		ans *= a;
	}
	return ans;
}
int main()
{
	int l = 0;
	int r = 0;
	string a, b;
	cin >> a >> b;
	FOR(i, 0, a.length())
	{
		if (a[i] == '-')
		{
			l++;
		}
		else
		{
			r++;
		}
	}
	FOR(i, 0, b.length())
	{
		if (b[i] == '-')
		{
			l--;
		}
		else if (b[i] == '+')
		{
			r--;
		}
	}
	if (l < 0 || r < 0)
	{
		cout << 0 << endl;
	}
	else
	{
		printf("%.10f\n", (double)factorial(l + r) / factorial(r) / factorial(l) / power(2, l + r));
	}
}