//Andrew Yang
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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;


vector<int> children[100001];
int p[100001];


int sz[100001];
void getSize(int node) // only works if you start at root of tree
{
	sz[node] = 1;
	for (int c : children[node])
	{
		getSize(c);
		sz[node] += sz[c];
	}
}

void buildTree(int node) // contruct p and children
{
	sz[node] = 1;
	for (int c : edges[node])
	{
		if (c == p[node])
		{
			continue;
		}
		children[node].push_back(c);
		p[c] = node;
		buildTree(c);
		sz[node] += sz[c];
	}
}

int longestToLeaf[100001];
void getLongestToLeaf(int node)
{
	longestToLeaf[node] = 0; // 0 if counting edges, 1 if counting nodes
	for (int c : children[node])
	{
		getLongestToLeaf(c);
		longestToLeaf[node]  = max(longestToLeaf[node], 1 + longestToLeaf[c]);
	}
}
int n;
int getDiameter()
{
	int ans = 0;
	FOR(i, 0, n)
	{
		int d = 0;
		if (children[i].size() == 1)
		{
			d = longestToLeaf[children[i][0]] + 1;
			continue;
		}
		int max = 0;
		int secondmax = 0;
		for(int j : children[i])
		{
			if (longestToLeaf[j] >= max)
			{
				secondmax = max;
				max = longestToLeaf[j];
			}
			else if (longestToLeaf[j] > secondmax)
			{
				secondmax = longestToLeaf[j];
			}
		}
		d = max + secondmax + 2;
		ans = max(ans, d);
	}
	return ans;
}




int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	p[0] = -1;
	FOR(i, 1, n) // another way trees are given in input
	{
		cin >> p[i];
		children[p[i]].push_back(i);
	}
}