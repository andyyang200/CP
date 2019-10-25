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
int used[100];
int ans;
int n;
string s;
int p;
void f(int i)
{
	if (i == n)
	{
		string x = "";
		int removed = 0;
		FOR(i, 0, x.length())
		{
			if (!used[i])
			{
				x += s[i];
			}
			else
			{
				removed++;
			}
		}
		if (x.size() > 1 && x[0] == '0')
		{
			return;
		}
		int a = stoi(x);
		if (a % p == 0)
		{
			ans = min(ans, removed);
		}
		return;
	}
	used[i] = false;
	f(i + 1);
	used[i] = true;
	f(i + 1);
}
int main(void)
{
	string s;
	cin >> s;
	n = s.length();
	int k;
	cin >> k;
	ans = 100;
	p = 1;
	FOR(i, 0, k)
	{
		p *= 10;
	}
	f(0);
	cout << ans << endl;
}