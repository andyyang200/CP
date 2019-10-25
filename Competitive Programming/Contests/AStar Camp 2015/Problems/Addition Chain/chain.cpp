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
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int chain[20001];
int target;
int maxDepth;
bool f(int depth)
{
	if (chain[depth] == target)
	{
		return true;
	}
	if ((chain[depth] << (maxDepth - depth)) < target)
	{
		return false;
	}
	if (chain[depth] > target)
	{
		return false;
	}
	if (depth >= maxDepth)
	{
		return false;
	}
	RFOR(i, depth, 0)
	{
		chain[depth + 1] = (chain[depth] + chain[i]);
		if (f(depth + 1))
		{
			return true;
		}
	}
	return false;
}
int main()
{
	freopen("chain.in", "r", stdin);
	freopen("chain.out", "w", stdout);
	scanf("%d", &target);
	chain[1] = 1;
	for (maxDepth = 1;; maxDepth++)
	{
		if (f(1))
		{
			cout << maxDepth << endl;
			break;
		}
	}
}