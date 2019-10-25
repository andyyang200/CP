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
/* In an array of N elements (1 <= N <= 1000000), the score of a subarray is the maximum element in that subarray.
What is the sum of the scores of all subarrays?
*/
int l[1000000];
int r[1000000];
int a[1000000];
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		cin >> a[i];
	}
	stack<int> s;
	s.push(-1);
	FOR(i, 0, n)
	{
		while (s.top() != -1 && a[s.top()] <= a[i])
		{
			s.pop();
		}
		l[i] = s.top() + 1;
		s.push(i);
	}
	while (!s.empty())
	{
		s.pop();
	}
	s.push(n);
	RFOR(i, n - 1, -1)
	{
		while (s.top() != n && a[s.top()] < a[i])
		{
			s.pop();
		}
		r[i] = s.top() - 1;
		s.push(i);
	}
	ll ans = 0;
	FOR(i, 0, n)
	{
		ans += a[i] * (i - l[i] + 1) * (r[i] - i + 1);
	}
	cout << ans << endl;
}