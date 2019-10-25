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
int breed[100001];
int main()
{
	freopen("lineup.in", "r", stdin);
	freopen("lineup.out", "w", stdout);
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		scanf("%d", &breed[i]);
	}
	map < int, int > m;
	multiset<int> counts;
	int l = 0;
	int ans = 0;
	FOR(r, 0, n)
	{
		if (m.find(breed[r]) != m.end())
		{ 
			counts.erase(counts.find(m[breed[r]]));
		}
		m[breed[r]]++;
		counts.insert(m[breed[r]]);
		while (m.size() > k + 1)
		{
			if (m[breed[l]] == 1)
			{
				counts.erase(counts.find(m[breed[l]]));
				m.erase(m.find(breed[l]));
			}
			else
			{
				counts.insert(m[breed[l]] - 1);
				counts.erase(counts.find(m[breed[l]]));
				m[breed[l]]--;
			}
			l++;
		}
		ans = max(ans, *(counts.rbegin()));
	}
	cout << ans << endl;
}