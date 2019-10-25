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
#include <unordered_set>
#include <map>
#include <unordered_map>
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
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 2000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

map <ll, pair<ll, ll>> children;

bool queried(ll node)
{
	return children.find(node) != children.end();
}

void query(ll node)
{
	if (!queried(node))
	{
		cout << node << endl;
		scanf("%d%d", children[node].first, children[node].second);
	}
}
int getLevel(ll node)
{
	int level = 0;
	while (node > 1)
	{
		node /= 2;
		level++;
	}
	return level;
}

int getHeight()
{
	int node = 1;
	int height = 0;
	while (node != 0)
	{
		query(node);
		node = children[node].first;
		height++;
	}
	return height - 1;
}

ll findNode(ll node)
{
	int level = getLevel(node);
	node %= (1 << level);
	std::string s = std::bitset< 500 >(node).to_string();
	s = s.substr(s.length() - level);
	node = 1;
	FOR(i, 0, s.length())
	{
		query(node);
		if (s[i] == '0')
		{
			node = children[node].first;
		}
		else
		{
			node = children[node].second;
		}
	}
	return node;
}



int main()
{
}