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
int a[6];
string request[100001];
string ans[100001];
int toInt(string s)
{
	if (s == "S")
	{
		return 0;
	}
	if (s == "M")
	{
		return 1;
	}
	if (s == "L")
	{
		return 2;
	}
	if (s == "XL")
	{
		return 3;
	}
	if (s == "XXL")
	{
		return 4;
	}
	if (s == "XXXL")
	{
		return 5;
	}
	return -1;
}
string toString(int s)
{
	if (s == 0)
	{
		return "S";
	}
	if (s == 1)
	{
		return "M";
	}
	if (s == 2)
	{
		return "L";
	}
	if (s == 3)
	{
		return "XL";
	}
	if (s == 4)
	{
		return "XXL";
	}
	if (s == 5)
	{
		return "XXXL";
	}
	return "";
}
int main(void)
{
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5];
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> request[i];
	}
	FOR(i, 0, n)
	{
		if (toInt(request[i]) != -1)
		{
			ans[i] = request[i];
			a[toInt(request[i])]--;
			if (a[toInt(request[i])] < 0)
			{
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	FOR(i, 0, 5)
	{
		FOR(j, 0, n)
		{
			if (toInt(request[j]) == -1)
			{
				int comma = -1;
				FOR(k, 0, request[j].length())
				{
					if (request[j][k] == ',')
					{	
						comma = k;
						break;
					}
				}
				if (toInt(request[j].substr(0, comma)) != i)
				{
					continue;
				}
				if (a[i] > 0)
				{
					a[i]--;
					ans[j] = toString(i);
				}
				else if (a[i + 1] > 0)
				{
					a[i + 1]--;
					ans[j] = toString(i + 1);
				}
				else
				{
					cout << "NO" << endl;
					return 0;
				}
			}
		}
	}
	cout << "YES" << endl;
	FOR(i, 0, n)
	{
		cout << ans[i] << endl;
	}
}