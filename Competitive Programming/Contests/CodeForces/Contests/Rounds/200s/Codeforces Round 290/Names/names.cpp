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

map<char, vector<char> > edges;
map<char, vector<char> > incoming;
map<char, bool> used;

void f(int index, vector<string> names)
{
	if (names.size() <= 1)
	{
		return;
	}
	FOR(i, 0, names.size())
	{
		if (names[i].length() <= index)
		{
			names.erase(names.begin() + i);
			i--;
		}
	}
	vector<string> temp;
	temp.push_back(names[0]);
	FOR(i, 1, names.size())
	{
		if (names[i][index] != temp[0][index])
		{
			edges[temp[0][index]].push_back(names[i][index]);
			incoming[names[i][index]].push_back(temp[0][index]);
			f(index + 1, temp);
			temp.clear();
		}
		temp.push_back(names[i]);
	}
	f(index + 1, temp);
}
int main()
{
	int n;
	cin >> n;
	vector<string> temp;
	FOR(i, 0, n)
	{
		string name;
		cin >> name;
		temp.push_back(name);
		if (i > 0 && temp[i - 1].length() > temp[i].length() && temp[i] == temp[i - 1].substr(0, temp[i].length()))
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	f(0, temp);
	string ans = "";
	FOR(i, 0, 26)
	{
		char c = 'a' + i;
		if (edges[c].size() == 0 && incoming[c].size() == 0)
		{
			ans += c;
			used[c] = true;
		}
	}
	while (ans.length() < 26)
	{
		bool found = false;
		FOR(i, 0, 26)
		{
			char c = 'a' + i;
			if (incoming[c].size() == 0 && !used[c])
			{
				found = true;
				ans += c;
				used[c] = true;
				for (int next : edges[c])
				{
					incoming[next].erase(find(incoming[next].begin(), incoming[next].end(), c));
				}
				break;
			}
		}
		if (!found)
		{
			cout << "Impossible" << endl;
			return 0;
		}
	}
	cout << ans << endl;
}