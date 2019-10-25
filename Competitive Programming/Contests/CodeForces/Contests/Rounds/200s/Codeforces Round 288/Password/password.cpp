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
typedef pair<int, int> pii;

map<string, vector<string>> edges;
map<string, int> degree;
string path;

void find(string node)
{
	while (!edges[node].empty())
	{
		string next = edges[node][0];
		edges[node].erase(edges[node].begin());
		find(next);
	}
	path += node.substr(1, 1);
}

int main()
{
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		string s;
		cin >> s;
		edges[s.substr(0, 2)].push_back(s.substr(1, 2));
		degree[s.substr(0, 2)]++;
		degree[s.substr(1, 2)]++;
	}
	int count = 0;
	string start = "";
	for (auto itr = degree.begin(); itr != degree.end(); itr++)
	{
		if (itr -> second % 2 == 1)
		{
			count++;
			if (edges[itr->first].size() > 0)
			{
				start = itr->first;
			}
		}
	}
	if (count != 2 && count != 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (start == "")
	{
		start = edges.begin() -> first;
	}
	find(start);
	cout << "YES" << endl;
	cout << start;
	RFOR(i, path.length() - 2, -1)
	{
		cout << path[i];
	}
	cout << endl;
}