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
int ans[50];
int used[50];
string convert(int i)
{
	string s = "";
	s += (char)('A' + i / 26);
	s += (char)('a' + i % 26);
	return s;
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	ans[0] = 1;
	int r = 1;
	FOR(l, 0, n - k + 1)
	{
		string s;
		cin >> s;
		FOR(j, 1, n + 1)
		{
			used[j] = false;
		}
		FOR(j, l, l + k)
		{
			if (ans[j] != 0)
			{
				used[ans[j]] = true;
			}
		}
		if (s == "NO")
		{
			ans[r++] = ans[l];
		}
		while (r < l + k)
		{
			FOR(j, 1, n + 1)
			{
				if (!used[j])
				{
					ans[r++] = j;
					used[j] = true;
					break;
				}
			}
		}
		
	}
	FOR(i, 0, n)
	{
		cout << convert(ans[i]) << " ";
	}
	cout << endl;
}