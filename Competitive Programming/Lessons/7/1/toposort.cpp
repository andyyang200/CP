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


vector<int> order;
vector<int> in[100001];
vector<int> out[100001];
bool cycle;
int n, m;
void toposort()
{
	while (order.size() < n)
	{
		bool found = false;
		FOR(i, 0, n)
		{
			if (in[i].size() == 0)
			{
				found = true;
				order.push_back(i);
				for (int v : out[i])
				{
					FOR(j, 0, in[v].size())
					{
						if (in[v][j] == i)
						{
							in[v].erase(in[v].begin() + j);
							break;
						}
					}
				}
			}
		}
		if (!found)
		{
			cycle = true;
			break;	
		}
	}
	
}
int main(void)
{
	scanf("%d%d", &n, &m);
	FOR(i, 0, m)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		out[u].push_back(v);
		in[v].push_back(u);
	}
}