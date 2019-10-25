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
int ans[20];
int n, k;
void generate(int i)
{
	if (i == n)
	{
		for (int j = 0; j < n; j++)
		{
			cout << ans[j] << " ";
		}
		cout << endl;
		return;
	}
	for (int j = 1; j <= k; j++)
	{
		ans[i] = j;
		generate(i + 1);
	}
}
int main(void)
{
	scanf("%d%d", &n, &k);
	for (int a = 1; a <= k; a++)
	{
		ans[0] = a;
		for (int b = 1; b <= k; b++)
		{
			ans[1] = b;
			for (int c = 1; c <= k; c++)
			{
				ans[2] = c;
				for (int d = 1; d <= k; d++)
				{
					ans[3] = d;
					// and so on...
				}
			}
		}
	}



	generate(0);
}