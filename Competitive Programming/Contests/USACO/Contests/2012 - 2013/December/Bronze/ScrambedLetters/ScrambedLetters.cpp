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

struct Name
{
	string name;
	bool isReverse;
	int min, max;
	bool operator<(Name n)
	{
		if (name == n.name)
		{
			return !isReverse && n.isReverse;
		}
		return name < n.name;
	}
};

Name names[50005];
Name sorted[2 * 50005];

void order(string& name)
{
	string result;
	char letters[21];
	for (int x = 0; x < (int)name.size(); x++)
	{
		letters[x] = name[x];
	}
	sort(letters, letters + name.size());
	for (int x = 0; x < (int)name.size(); x++)
	{
		result += letters[x];
	}
	name = result;
}
void orderReverse(string& name)
{
	order(name);
	reverse(name.begin(), name.end());
}

int main()
{
	ifstream fin("scramble.in");
	ofstream fout("scramble.out");

	int n;
	fin >> n;


}