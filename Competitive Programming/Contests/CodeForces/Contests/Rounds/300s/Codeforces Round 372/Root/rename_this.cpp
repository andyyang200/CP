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

int main(void)
{
	int n;
	scanf("%d", &n);
	ll level = 1;
	ll screen = 2;
	FOR(i, 0, n)
	{
		ll next = (level + 1) * (level + 1) * level * level;
		ll m = -1;
		ll l = 1;
		ll r = 1000;
		while (l <= r)
		{
			ll mid = (l + r) >> 1;
			if (next * mid * mid < screen)
			{
				l = mid + 1;
			}
			else
			{
				m = mid;	
				r = mid - 1;
			}
		}
		next *= m * m;
		cout << (next - screen) / level << endl;
		screen = (level + 1) * level * m;
		level++;
	}
}