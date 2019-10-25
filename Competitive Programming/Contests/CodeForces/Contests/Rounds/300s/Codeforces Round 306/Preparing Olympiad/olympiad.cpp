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
int d[20];
int main()
{
	ios::sync_with_stdio(false);
	int n, l, r, x;
	cin >> n >> l >> r >> x;
	FOR(i, 0, n)
	{
		cin >> d[i];
	}
	int count = 0;
	FOR(i, 0, 1 << n)
	{
		vector<int> v;
		int sum = 0;
		FOR(j, 0, n)
		{
			if (i & (1 << j))
			{
				v.push_back(d[j]);
				sum += d[j];
			}
		}
		sort(v.begin(), v.end());
		if (v.size() >= 2 && sum >= l && sum <= r && v[v.size() - 1] - v[0] >= x)
		{
			count++;
		}
	}
	cout << count << endl;
}