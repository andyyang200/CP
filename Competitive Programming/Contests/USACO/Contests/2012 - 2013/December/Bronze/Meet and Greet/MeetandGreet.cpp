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

int bessie[1000005];
int elsie[1000005];

int main()
{
	ifstream fin("greetings.in");
	ofstream fout("greetings.out");

	int b, e;
	fin >> b >> e;

	int i = 0, t = 0;
	for (int x = 0; x < b; x++)
	{
		int d;
		char c;
		fin >> d >> c;
		if (c == 'L')
		{
			for (int y = i - 1; y >= i - d; y--)
			{
				t++;
				bessie[t] = y;
			}
			i -= d;
		}
		else
		{
			for (int y = i + 1; y <= i + d; y++)
			{
				t++;
				bessie[t] = y;
			}
			i += d;
		}
	}
	while (t < 1000005)
	{
		t++;
		bessie[t] = i;
	}
	i = 0, t = 0;
	for (int x = 0; x < e; x++)
	{
		int d;
		char c;
		fin >> d >> c;
		if (c == 'L')
		{
			for (int y = i - 1; y >= i - d; y--)
			{
				t++;
				elsie[t] = y;
			}
			i -= d;
		}
		else
		{
			for (int y = i + 1; y <= i + d; y++)
			{
				t++;
				elsie[t] = y;
			}
			i += d;
		}
	}
	while (t < 1000005)
	{
		t++;
		elsie[t] = i;
	}
	int count = 0;
	for (int x = 0; x < 1000001; x++)
	{
		if (bessie[x] != elsie[x] && bessie[x + 1] == elsie[x + 1])
		{
			count++;
		}
	}
	fout << count << endl;
}