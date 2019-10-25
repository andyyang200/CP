/*
ID: andyyang200
PROG: agrinet
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

int distances[101];
int weights[101][101];
bool inTree[101];

int main()
{
	ifstream fin("agrinet.in");
	ofstream fout("agrinet.out");

	int n;
	fin >> n;

	for (int r = 0; r < n; r++)
	{
		for (int c = 0; c < n; c++)
		{
			fin >> weights[r][c];
		}
	}


	int treeSize = 1;
	int treeCost = 0;
	inTree[0] = 1;
	for (int x = 0; x < n; x++)
	{
		distances[x] = weights[0][x];
	}

	while (treeSize < n)
	{
		int minDistance = 10000000;
		int minFarm = 0;
		for (int x = 0; x < n; x++)
		{
			if (!inTree[x] && distances[x] < minDistance)
			{
				minDistance = distances[x];
				minFarm = x;
			}
		}
		treeSize++;
		inTree[minFarm] = 1;
		treeCost += distances[minFarm];
		for (int x = 0; x < n; x++)
		{
			if (distances[x] > weights[minFarm][x])
			{
				distances[x] = weights[minFarm][x];
			}
		}
	}
	fout << treeCost << endl;
}