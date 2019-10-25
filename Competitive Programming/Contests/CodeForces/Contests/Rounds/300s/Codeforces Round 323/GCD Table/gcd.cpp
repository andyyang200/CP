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

int GCD(int a, int b) 
{
	return b == 0 ? a : GCD(b, a % b);
}
int main()
{
	map<int, int> m;
	int n;
	scanf("%d", &n);
	FOR(i, 0, n * n)
	{
		int x;
		scanf("%d", &x);
		m[x]++;
	}
	int count = 0;
	vector<int> v;
	RFOREACH(itr, m)
	{
		int remove = 0;
		FOR (i, 0, v.size())
		{
			if (v[i] % itr->first == 0)
			{
				remove += 2;
			}
		}
		FOR(i, 1, itr->second + 1)
		{
			if (i * i + i * remove == itr->second)
			{
				FOR(j, 0, i)
				{
					cout << itr->first << " ";
					FOR(k, 0, v.size())
					{
						int x = GCD(v[k], itr->first);
						if (m[x] > 0)
						{
							m[x] -= 2;
						}
					}
					v.push_back(itr->first);
					count++;
				}
			}
		}
		if (count == n)
		{
			break;
		}
	}
	cout << endl;
}