//Andrew Yang
//accepted
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
int cnt;
string f(ll x, int k)
{
	if (x <= 1)
	{
		return "";
	}
	else if (x % 2 == 0)
	{
		cnt++;
		return f(x / 2, k - 1) + to_string(k) + " ";
	}
	else
	{
		cnt++;
		return to_string(k) + " " + f(x - 1, k - 1);
	}
}
int main(void)
{
	ll n;
	cin >> n;
	cnt = 0;
	string ans = f(n + 1, 100);
	cout << cnt + 100 << endl;
	cout << ans;
	FOR(i, 0, 100)
	{
		cout << i + 1 << " ";
	}
	cout << endl;
}