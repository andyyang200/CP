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

int main()
{
	ll a, b;
	cin >> a >> b;
	ll count = 0;
	while (a != b)
	{
		ll times;
		if (a > b)
		{
			times = a / b;
			a -= times * b;
			count += times;
			if (a % b == 0)
			{
				break;
			}
		}
		else
		{
			times = b / a;
			b -= times * a;
			count += times;
			if (b % a == 0)
			{
				break;
			}
		}
	}
	cout << count << endl;
}