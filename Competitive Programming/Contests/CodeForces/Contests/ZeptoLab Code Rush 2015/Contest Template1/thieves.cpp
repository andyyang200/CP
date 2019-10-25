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

string level;
bool check(int start, int jump)
{
	int count = 0;
	while (count < 4)
	{
		start += jump;
		if (start >= level.length())
		{
			break;
		}
		if (level[start] == '.')
		{
			break;
		}
		count++;
	}
	return count == 4;
}

int main()
{
	FOR(i, 0, 10000)
	{
		cout << 'a';
	}
	int n;
	scanf("%d", &n);
	cin >> level;
	FOR(jump, 1, 30)
	{
		FOR(i, 0, level.length())
		{
			if (level[i] == '*')
			{
				if (check(i, jump))
				{
					cout << "yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "no" << endl;
}