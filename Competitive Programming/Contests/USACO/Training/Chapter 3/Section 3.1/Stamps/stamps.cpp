/*
ID: andyyang200
PROG: stamps
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
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

using namespace std;

int ways[2000010];
int stamps[50];
int main()
{
	ifstream fin("stamps.in");
	ofstream fout("stamps.out");

	int k, n;
	fin >> k >> n;

	for (int x = 0; x < n; x++)
	{
		fin >> stamps[x];
	}

	for (int x = 1; x > 0; x++)
	{
		for (int i = 0; i < n; i++)
		{
			if (x - stamps[i] >= 0)
			{
				if (ways[x] == 0 || ways[x - stamps[i]] + 1 < ways[x])
				{
					ways[x] = ways[x - stamps[i]] + 1;
				}
			}
		}
		if (ways[x] == 0 || ways[x] > k)
		{
			fout << x - 1 << endl;
			break;
		}
	}
}