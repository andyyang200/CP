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
vector<int> l;
vector<int> r;
ll n, m;

int main()
{
	cin >> n >> m;
	FOR(i, 1, n + 1)
	{
		if (((ll)1 << (n - i - 1)) < m)
		{
			r.push_back(i);
			m -= ((ll)1 << (n - i - 1));
		}
		else
		{
			l.push_back(i);
		}
	}
	FOR(i, 0, l.size())
	{
		cout << l[i] << " ";
	}
	RFOR(i, r.size() - 1, -1)
	{
		cout << r[i] << " ";
	}
	cout << endl;
}