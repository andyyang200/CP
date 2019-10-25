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
string a[100001];
bool check(string s)
{
	if (s[0] != '1')
	{
		return false;
	}
	FOR(i, 1, s.length())
	{
		if (s[i] != '0')
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n)
	{
		cin >> a[i];
		if (a[i] == "0")
		{
			cout << 0 << endl;
			return 0;
		}
	}
	int loc = -1;
	FOR(i, 0, n)
	{
		if (!check(a[i]))
		{
			loc = i;
			break;
		}
	}
	string ans;
	if (loc != -1)
	{
		ans = a[loc];
	}
	else
	{
		ans = "1";
	}
	FOR(i, 0, n)
	{
		if (i != loc)
		{
			FOR(j, 1, a[i].length())
			{
				ans += "0";
			}
		}
	}
	cout << ans << endl;

}