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


int main()
{
	int e, n;
	cin >> e >> n;
	int count = 0;
	while (e >= 2 || n >= 2)
	{
		if (e < 1 || n < 1)
		{
			break;
		}
		if (e > n)
		{
			e -= 2;
			n -= 1;
		}
		else
		{
			e -= 1;
			n -= 2;
		}
		count++;
	}
	cout << count << endl;
}