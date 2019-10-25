//Andrew Yang
// accepted
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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int a[100001];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	int start = 0;
	int ans = 1;
	bool up = false;
	bool down = false;
	FOR(i, 0, n)
	{
		if (i - start >= 1)
		{
			if (a[i] > a[i - 1])
			{
				up = true;
				if (down)
				{
					start = i;
					ans++;
					up = false;
					down = false;
				}
			}
			else if (a[i] < a[i - 1])
			{
				down = true;
				if (up)
				{
					start = i;
					ans++;
					up = false;
					down = false;
				}
			}
		}
	}
	cout << ans	<< endl;
}