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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
unordered_map<string, bool> variables;
string line[5001][4]; // name, a, operator, b
int main(void)
{
	int n, m;
	scanf("%d%d", &n, &m);
	FOR(i, 0, n)
	{
		cin >> line[i][0];
		cin >> line[i][1];
		cin >> line[i][1];
		if (line[i][1][0] == '0' || line[i][1][0] == '1')
		{
			continue;
		}
		cin >> line[i][2];
		cin >> line[i][3];
	}
	string minAns = "";
	string maxAns = "";
	FOR(b, 0, m)
	{
		int minCount = n + 5;
		int minBit = -1;
		int maxCount = -1;
		int maxBit = -1;
		FOR(j, 0, 2)
		{
			bool bit = (j == 1);
			int count = 0;
			FOR(i, 0, n)
			{
				if (line[i][1][0] == '0' || line[i][1][0] == '1')
				{
					variables[line[i][0]] = (line[i][1][b] == '1');
				}
				else
				{
					bool x, y, z;
					if (line[i][1][0] == '?')
					{
						x = bit;
					}
					else
					{
						x = variables[line[i][1]];
					}
					if (line[i][3][0] == '?')
					{
						y = bit;
					}
					else
					{
						y = variables[line[i][3]];
					}
					if (line[i][2] == "OR")
					{
						z = x || y;
					}
					else if (line[i][2] == "AND")
					{
						z = x && y;
					}
					else
					{
						z = (x != y);
					}
					variables[line[i][0]] = z;
					if (z)
					{
						count++;
					}
				}
			}
			if (count < minCount)
			{
				minCount = count;
				minBit = j;
			}
			if (count > maxCount)
			{
				maxCount = count;
				maxBit = j;
			}
		}
		minAns += to_string(minBit);
		maxAns += to_string(maxBit);
	}
	cout << minAns << endl;
	cout << maxAns << endl;
}