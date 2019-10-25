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
set<int> people;
int main()
{
	int n;
	cin >> n;
	int capacity = 0;
	int current = 0;
	FOR(i, 0, n)
	{
		char type;
		int x;
		cin >> type >> x;
		if (type == '+')
		{
			people.insert(x);
			current++;
			capacity = max(capacity, current);
		}
		else
		{
			auto itr = people.find(x);
			if (itr == people.end())
			{
				capacity++;
			}
			else
			{
				people.erase(itr);
				current--;
			}
		}
	}
	cout << capacity << endl;
}