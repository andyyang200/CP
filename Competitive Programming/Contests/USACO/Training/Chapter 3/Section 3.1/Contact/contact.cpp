/*
ID: andyyang200
PROG: contact
LANG: C++11
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

bool sortFunction(string a, string b)
{
	if (a.length() != b.length())
	{
		return a.length() < b.length();
	}
	return a < b;
}

map<string, int> occurences; //sequence to number of occurences
set<int> s; // all different occurences
int main()
{
	ifstream fin("contact.in");
	ofstream fout("contact.out");

	int a, b, n;
	fin >> a >> b >> n;
	string sequence, line;
	getline(fin, line);
	while (getline(fin, line))
	{
		sequence += line;
	}
	bool q2 = sequence.length() < 2;
	for (int start = 0; start < (int)sequence.length(); start++)
	{
		for (int length = a; length <= b; length++)
		{
			if (start + length > (int)sequence.length())
			{
				break;
			}
			occurences[sequence.substr(start, length)]++;
		}
	}
	for (auto& p : occurences)
	{
		s.insert(p.second);
	}
	int count = 0;
	set<int>::reverse_iterator  start = s.rbegin();
	set<int>::reverse_iterator  end = s.rend();
	for (set<int>::reverse_iterator i = start; count != n && i != end; i++, count++)
	{
		fout << *i << endl;
		vector<string> result;
		for (auto& p : occurences)
		{
			if (p.second == *i)
			{
				result.push_back(p.first);
			}
		}
		sort(result.begin(), result.end(), sortFunction);
		int x;
		for (x = 0; x < (int)result.size(); x++)
		{
			fout << result[x] + ((x + 1) % 6 == 0 || x == (int)result.size() - 1? "\n" : " ");
		}
	}
}