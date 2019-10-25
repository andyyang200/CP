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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int a[1000010];
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	int ans = 0;
	int j = -1;
	multiset<int> s;
	FOR(i, 0, n)
	{
		if (i > 0)
		{
			s.erase(s.find(a[i - 1]));
		}
		while (j < n - 1)
		{
			if (s.size() == 0 || *s.begin() == *--s.end())
			{
				s.insert(a[j + 1]);
				j++;
			}
			else if (a[j + 1] == *s.begin() || a[j + 1] == *--s.end())
			{
				s.insert(a[j + 1]);
				j++;
			}
			else
			{
				break;
			}
		}
		ans = max(ans, (int)s.size());
	}
	cout << ans << endl;
}