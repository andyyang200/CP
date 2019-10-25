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
#include <map>
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
#define FOREACH(itr, b) for(auto& itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto& itr = b.rbegin(); itr != b.rend; itr++)
typedef long long ll;

map<string, string> words;

int main()
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, m)
	{
		string a, b;
		cin >> a >> b;
		words[a] = b;
	}
	FOR(i, 0, n)
	{
		string word;
		cin >> word;
		string b = words[word];
		if (word.length() <= b.length())
		{
			cout << word;
		}
		else
		{
			cout << b;
		}
		if (i < n - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}