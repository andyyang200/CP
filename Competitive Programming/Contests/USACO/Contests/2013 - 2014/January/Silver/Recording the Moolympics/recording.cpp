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
typedef pair<int, int> pii;
bool compare(const pii& a, const pii& b)
{
	return a.second < b.second;
}

pii programs[151];

int main()
{
	freopen("recording.in", "r", stdin);
	freopen("recording.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> programs[i].first >> programs[i].second;
	}
	sort(programs, programs + n, compare);
	int a = 0, b = 0;
	int count = 0;
	FOR(i, 0, n)
	{
		if (programs[i].first >= a && programs[i].first >= b)
		{
			count++;
			if (a > b)
			{
				a = programs[i].second;
			}
			else
			{
				b = programs[i].second;
			}
		}
		else if (programs[i].first >= a)
		{
			count++;
			a = programs[i].second;
			
		}
		else if (programs[i].first >= b)
		{
			count++;
			b = programs[i].second;
		}
	}
	cout << count << endl;
}