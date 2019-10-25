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
#define FOR(index, start, end) for(ll index = start; index < end; index++)
#define RFOR(index, start, end) for(ll index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<ll, ll> pii;

class UnionFind
{
public:
	vector<int> p, rank, size;
	UnionFind(int n)
	{
		rank.assign(n, 0);
		p.assign(n, 0);
		size.assign(n, 1);
		for (int i = 0; i < n; i++)
		{
			p[i] = i;
		}
	}
	int findSet(int i)
	{
		return (p[i] == i) ? i : (p[i] = findSet(p[i]));
	}
	bool isSameSet(int i, int j)
	{
		return findSet(i) == findSet(j);
	}
	int getSize(int i)
	{
		return size[findSet(i)];
	}
	void unionSet(int i, int j)
	{
		if (!isSameSet(i, j))
		{
			int x = findSet(i);
			int y = findSet(j);
			if (rank[x] > rank[y])
			{
				p[y] = x;
				size[x] += size[y];
			}
			else
			{
				p[x] = y;
				size[y] += size[x];
				if (rank[x] == rank[y])
				{
					rank[y]++;
				}
			}
		}

	}
};

int main()
{

}