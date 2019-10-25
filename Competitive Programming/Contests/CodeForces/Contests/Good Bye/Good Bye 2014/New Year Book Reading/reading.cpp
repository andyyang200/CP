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

map<int, int> books; // number, weight
vector<int> finish;
int order[1005];

int main()
{
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n)
	{
		int a;
		cin >> a;
		books[i + 1] = a;
	}
	FOR(i, 0, m)
	{
		cin >> order[i];
	}
	FOR(i, 0, m)
	{
		bool contains = false;
		FOR(j, 0, finish.size())
		{
			if (finish[j] == order[i])
			{
				contains = true;
				break;
			}
		}
		if (!contains)
		{
			finish.push_back(order[i]);
		}
	}
	int sum = 0;
	FOR(i, 0, m)
	{
		FOR(j, 0, finish.size())
		{
			if (finish[j] == order[i])
			{
				RFOR(x, j - 1, -1)
				{
					sum += books[finish[x]];
				}
				finish.erase(finish.begin() + j);
				finish.insert(finish.begin(), order[i]);
				break;
			}
		}
	}
	cout << sum << endl;
}