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

int n, d;

int best[30001][500];
int gem[30001];

int main()
{
	cin >> n >> d;
	for (int i = 0; i < n; i++)
	{
		int p;
		cin >> p;
		gem[p]++;
	}
	int ans = 1;
	best[d][250] = gem[d] + 1;
	for (int i = d; i <= 30000; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			if (best[i][j] == 0) continue;
			int jump = j - 250 + d;
			int val = best[i][j];
			ans = max(ans, val);
			for (int df = max(1, jump - 1); df <= jump + 1; df++)
			{
				int next = i + df;
				if (next <= 30000)
				{
					best[next][df - d + 250] = max(best[next][df - d + 250], val + gem[next]);
				}
			}
		}
	}
	cout << ans - 1 << endl;
}