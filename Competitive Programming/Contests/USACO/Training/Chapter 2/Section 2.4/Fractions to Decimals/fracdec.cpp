/*
ID: andyyang200
PROG: fracdec
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

vector<string> result;
map<int, int> indexes; // dividend to index

int main()
{
	ifstream fin("fracdec.in");
	ofstream fout("fracdec.out");

	int n, d;
	fin >> n >> d;
	
	int dividend = n;
	int divisor = d;
	int i = -1; // index of repeat
	while (true)
	{
		i = indexes[dividend];
		if (i > 0)
		{
			break;
		}

		int quotient = dividend / divisor;

		char tmp[100]; // convert quotient to string
		sprintf(tmp, "%d", quotient);
		result.push_back(tmp);

		indexes[dividend] = result.size() - 1;

		if (result.size() == 1)
		{
			result.push_back(".");
		}

		dividend -= quotient * divisor;

		if (dividend == 0)
		{
			break;
		}
		dividend *= 10;
	}

	if (result[result.size() - 1] == ".")
	{
		result.push_back("0");
	}

	string r = "";
	for (int x = 0; x < result.size(); x++) // convert vector to string
	{
		if (i > 0 && x == i)
		{
			r += "(";
		}
		r += result[x];
	}
	if (i > 0)
	{
		r += ")";
	}
	
	while (r.size() > 76)
	{
		fout << r.substr(0, 76) << endl;
		r = r.substr(76, r.size() - 76);
	}
	fout << r << endl;
}