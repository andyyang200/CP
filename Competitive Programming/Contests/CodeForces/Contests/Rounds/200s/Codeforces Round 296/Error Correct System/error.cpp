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

int index[30][30];

int main()
{
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	FOR(i, 0, 26)
	{
		FOR(j, 0, 26)
		{
			index[i][j] = -1;
		}
	}
	int d = 0;
	FOR(i, 0, n)
	{
		index[s[i] - 'a'][t[i] - 'a'] = i + 1;
		if (s[i] != t[i])
		{
			d++;
		}
	}
	FOR(i, 0, 26)
	{
		FOR(j, 0, 26)
		{
			if (i == j)
			{
				continue;
			}
			if (index[i][j] != -1 && index[j][i] != -1)
			{
				cout << d - 2 << endl;
				cout << index[i][j] << " " << index[j][i] << endl;
				return 0;
			}
		}
	}
	FOR(i, 0, 26)
	{
		FOR(j, 0, 26)
		{
			if (i == j)
			{
				continue;
			}
			FOR(k, 0, 26)
			{
				if (k == i || k == j)
				{
					continue;
				}
				if (index[i][j] != -1 && index[j][k] != -1)
				{
					cout << d - 1 << endl;
					cout << index[i][j] << " " << index[j][k] << endl;
					return 0;
				}
			}
		}
	}
	cout << d << endl;
	cout << -1 << " " << -1 << endl;
}