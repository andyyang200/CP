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
int t[150001];
int main()
{
	int n, k, q;
	scanf("%d%d%d", &n, &k, &q);
	FOR(i, 0, n)
	{
		scanf("%d", &t[i]);
	}
	set<pii> s; // score, index
	FOR(i, 0, q)
	{
		int type, x;
		scanf("%d%d", &type, &x);
		x--;
		if (type == 1)
		{
			if (s.size() < k)
			{
				s.insert({ t[x], x });
			}
			else
			{
				if (t[x] > s.begin()->first)
				{
					s.erase(s.begin());
					s.insert({ t[x], x });
				}
			}
		}
		else
		{
			if (s.find({ t[x], x }) != s.end())
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
	}
}