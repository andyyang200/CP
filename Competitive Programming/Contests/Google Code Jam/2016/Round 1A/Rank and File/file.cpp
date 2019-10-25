//Andrew Yang
//accepted
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
int main()
{
	freopen("file.in", "r", stdin);
	freopen("file.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(t, 0, tests)
	{
		int n;
		scanf("%d", &n);
		map<int, int> m;
		FOR(i, 0, n * (2 * n - 1))
		{
			int x;
			scanf("%d", &x);
			m[x]++;
		}
		cout << "Case #" << t + 1 << ": ";
		FOREACH(itr, m)
		{
			if (itr->second % 2 == 1)
			{
				cout << itr->first << " ";
			}
		}
		cout << endl;

	}
}