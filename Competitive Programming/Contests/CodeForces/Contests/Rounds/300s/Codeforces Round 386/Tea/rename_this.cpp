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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
vector<int> limitA;
vector<int> limitB;
int main(void)
{
	int n, k, a, b;
	scanf("%d%d%d%d", &n, &k, &a, &b);
	bool switched = false;
	if (a < b)
	{
		swap(a, b);
		switched = true;
	}
	if (a == b)
	{
		FOR(i, 0, a)
		{
			cout << "GB";
		}
		cout << endl;
		return 0;
	}
	if (a == n)
	{
		if (n > k)
		{
			cout << "NO" << endl;
			return 0;
		}
		FOR(i, 0, n)
		{
			if (switched)
			{
				cout << 'B';
			}
			else
			{
				cout << 'G';
			}
		}
		cout << endl;
		return 0;
	}
	int gaps = (int)ceil((double)a / k) - 1;
	if (gaps <= 0)
	{
		FOR(i, 0, a)
		{
			if (switched)
			{
				cout << 'B';
			}
			else
			{
				cout << 'G';
			}
		}
		FOR(i, 0, b)
		{
			if (switched)
			{
				cout << 'G';
			}
			else
			{
				cout << 'B';
			}
		}
		return 0;
	}
	if (b < gaps)
	{
		cout << "NO" << endl;
		return 0;
	}
	if (ceil(double(b / gaps)) > k)
	{
		cout << "NO" << endl;
		return 0;
	}
	int tempA = a;
	int tempB = b;
	while (tempA > 0)
	{
		limitA.push_back(min(k, tempA));
		tempA -= min(k, tempA);
		if (tempA > 0)
		{
			limitB.push_back(min(b / gaps, tempB));
			tempB -= min(b / gaps, tempB);
		}
	}
	FOR(i, 0, limitB.size())
	{
		if (limitB[i] < k && tempB > 0)
		{
			int move = min(k - limitB[i], tempB);
			limitB[i] += move;
			tempB -= move;
		}
	}
	FOR(i, 0, limitA.size())
	{
		FOR(j, 0, limitA[i])
		{
			if (switched)
			{
				cout << 'B';
			}
			else
			{
				cout << 'G';
			}
		}
		if (i < limitB.size())
		{
			FOR(j, 0, limitB[i])
			{
				if (switched)
				{
					cout << 'G';
				}
				else
				{
					cout << 'B';
				}
			}
		}
	}
	FOR(i, 0, tempA)
	{
		if (switched)
		{
			cout << 'B';
		}
		else
		{
			cout << 'G';
		}
	}
	FOR(i, 0, tempB)
	{
		if (switched)
		{
			cout << 'G';
		}
		else
		{
			cout << 'B';
		}
	}
	cout << endl;
}