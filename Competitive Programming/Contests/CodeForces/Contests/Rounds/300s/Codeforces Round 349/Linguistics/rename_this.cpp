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
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend; itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
bool possible[10005][5];
bool equals(string a, string b)
{
	if (a.length() != b.length())
	{
		return false;
	}
	FOR(i, 0, a.length())
	{
		if (a[i] != b[i])
		{
			return false;
		}
	}
	return true;
}
int main(void)
{
	string s;
	cin >> s;
	int n = s.length();
	possible[n][2] = true;
	possible[n][3] = true;
	RFOR(i, n - 1, 4)
	{
		if (i - 2 <= 4)
		{
			possible[i][2] = false;
		}
		else if (i + 2 <= n && possible[i + 2][2] && !equals(s.substr(i - 2, 2), s.substr(i, 2)))
		{
			possible[i][2] = true;
		}
		else if (i + 3 <= n && possible[i + 3][3])
		{
			possible[i][2] = true;
		}
		if (i - 3 <= 4)
		{
			possible[i][3] = false;
		}
		else if (i + 3 <= n && possible[i + 3][3] && !equals(s.substr(i - 3, 3), s.substr(i, 3)))
		{
			possible[i][3] = true;
		}
		else if (i + 2 <= n && possible[i + 2][2])
		{
			possible[i][3] = true;
		}
	}
	set<string> ans;
	FOR(i, 5, n)
	{
		if (i + 2 <= n && possible[i + 2][2])
		{
			ans.insert(s.substr(i, 2));
		}
		if (i + 3 <= n && possible[i + 3][3])
		{
			ans.insert(s.substr(i, 3));
		}
	}
	cout << ans.size() << endl;
	FOREACH(itr, ans)
	{
		cout << *itr << endl;
	}
}