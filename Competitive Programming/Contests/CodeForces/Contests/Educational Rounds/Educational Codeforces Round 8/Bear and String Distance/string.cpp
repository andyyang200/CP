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

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	string s;
	cin >> s;
	string ans = "";
	FOR(i, 0, n)
	{
		if ('z' - s[i] > s[i] - 'a')
		{
			int d = min(k, 'z' - s[i]);
			k -= d;
			ans += (char)(s[i] + d);
		}
		else
		{
			int d = min(k, s[i] - 'a');
			k -= d;
			ans += (char)(s[i] - d);
		}
	}
	if (k > 0)
	{
		cout << -1 << endl;
		return 0;
	}
	cout << ans << endl;
}