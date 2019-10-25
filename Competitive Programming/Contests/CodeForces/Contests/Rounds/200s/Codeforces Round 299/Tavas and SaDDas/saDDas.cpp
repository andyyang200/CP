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

int main()
{
	string s;
	cin >> s;
	int count = 0;
	FOR(i, 1, 11)
	{
		FOR(j, 0, 1 << i)
		{
			string n = "";
			FOR(k, 0, i)
			{
				if (j & (1 << k))
				{
					n = "7" + n;
				}
				else
				{
					n = "4" + n;
				}
			}
			count++;
			if (s == n)
			{
				cout << count << endl;
				return 0;
			}
		}
	}
}