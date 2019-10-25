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
map<string, string> m;
string s;
int n, q;
int ans;
void make(int index)
{
	if (index == n)
	{
		string temp = s;
		while (temp.length() > 1)
		{
			string a = temp.substr(0, 2);
			if (m.count(a))
			{
				temp.erase(temp.begin(), temp.begin() + 2);
				temp = m[a] + temp;
			}
			else
			{
				return;
			}
		}
		if (temp == "a")
		{
			ans++;
		}
		return;
	}
	for (char c = 'a'; c <= 'f'; c++)
	{
		s[index] = c;
		make(index + 1);
	}
}
int main()
{
	scanf("%d%d", &n, &q);
	FOR(i, 0, q)
	{
		string a, b;
		cin >> a >> b;
		m[a] = b;
	}
	s = "";
	FOR(i, 0, n)
	{
		s += ' ';
	}
	ans = 0;
	make(0);
	cout << ans << endl;
}