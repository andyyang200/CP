/*
ID: andyyang200
PROG: humble
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

int primes[101];
int numbers[1000001];
int indexes[101];
int main()
{
	ifstream fin("humble.in");
	ofstream fout("humble.out");

	int k, n;
	fin >> k >> n;
	for (int x = 0; x < k; x++)
	{
		fin >> primes[x];
	}
	numbers[0] = 1;
	for (int x = 1; x <= n; x++)
	{
		int min = 2000000000;
		for (int i = 0; i < k; i++)
		{
			while (primes[i] * numbers[indexes[i]] <= numbers[x - 1])
			{
				indexes[i]++;
			}
			if (primes[i] * numbers[indexes[i]] < min)
			{
				min = primes[i] * numbers[indexes[i]];
			}
		}
		numbers[x] = min;
	}
	fout << numbers[n] << endl;
}