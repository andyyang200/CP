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
string convert(int x)
{
	if (x == 0)
	{
		return "0";
	}
	string ans = "";
	while (x > 0)
	{
		ans = to_string(x % 7) + ans;
		x /= 7;
	}
	return ans;
}

string a, hours, minutes;
int used[10];
int len;
int ans;
void f(int i)
{
	if (i == len)
	{
		if (a.substr(0, hours.length()).compare(hours) <= 0 && a.substr(hours.length(), minutes.length()).compare(minutes) <= 0)
		{
			ans++;
		}
		return;
	}
	for(char j = '0'; j <= '6'; j++)
	{
		if (!used[j - '0'])
		{
			a[i] = j;
			used[j - '0'] = true;
			f(i + 1);
			used[j - '0'] = false;
		}
	}
}
int main(void)
{
	int n, m;
	cin >> n >> m;
	hours = convert(n - 1);
	minutes = convert(m - 1);
	len = hours.length() + minutes.length();
	if (len > 7)
	{
		cout << 0 << endl;
		return 0;
	}
	a = "";
	FOR(i, 0, len)
	{
		a += " ";
	}
	ans = 0;
	f(0);
	cout << ans << endl;
}