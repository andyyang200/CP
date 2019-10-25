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
int s[1005];
int main()
{
	freopen("ovation.in", "r", stdin);
	freopen("ovation.out", "w", stdout);
	int tests;
	scanf("%d", &tests);
	FOR(test, 0, tests)
	{
		int n;
		scanf("%d", &n);
		
		FOR(i, 0, n + 1)
		{
			char c;
			cin >> c;
			s[i] = c - '0';
		}
		int count = 0;
		int people = 0;
		FOR(i, 0, n + 1)
		{
			if (people < i)
			{
				count += i - people;
				people = i;
			}
			people += s[i];
		}
		cout << "Case #" << test + 1 << ": " << count << endl;
	}
}