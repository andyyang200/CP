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

int degree[2 << 16 + 1];
int s[2 << 16 + 1];
queue<int> nodes;
int main()
{
	int n;
	cin >> n;
	int edges = 0;
	FOR(i, 0, n)
	{
		cin >> degree[i] >> s[i];
		edges += degree[i];
		if (degree[i] == 1)
		{
			nodes.push(i);
		}
	}
	cout << edges / 2 << endl;
	while (!nodes.empty())
	{
		int node = nodes.front();
		nodes.pop();
		if (degree[node] == 0)
		{
			continue;
		}
		cout << node << " " << s[node] << endl;
		degree[s[node]]--;
		if (degree[s[node]] == 1)
		{
			nodes.push(s[node]);
		}
		s[s[node]] ^= node;
	}
}