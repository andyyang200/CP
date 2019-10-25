/*
ID: andyyang200
PROG: fact4
LANG: C++
*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
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

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef long long ll;

int main()
{
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	int n;
	cin >> n;
	int right = 1;
	for (int x = 2; x <= n; x++)
	{
		right *= x;
		while (right % 10 == 0)
		{
			right /= 10;
		}
		right %= 10000;
	}
	cout << right % 10 << endl;
}