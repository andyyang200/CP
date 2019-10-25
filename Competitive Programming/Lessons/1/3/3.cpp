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
int used[21];
int n;
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
	for (int j = 0; j < n; j++)
	{
		if (!used[j])
		{
			ans[i] = a[j];
			used[j] = true;
			generate(i + 1);
			used[j] = false;
		}
	}
}
int main(void)
{
	scanf("%d", &n);



	generate(0);




	for (int bit = 0; bit < (1 << n); bit++)
	{
		for (int i = 0; i < n; i++)
		{
			if (bit & (1 << i))
			{
				// used[i] = true;
			}
		}
	}
}