//Andrew Yang
//accepeted
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
int a[100001];
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
	int n;
	cin >> n;
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	ll sum = 0;
	int t = -1;
	FOR(i, 0, n)
	{
		sum += a[i];
		if (i < n - 1 && 2 * sum < (ll)a[i + 1])
		{
			t = i;
		}
	}
	if (t == -1)
	{
		cout << n << endl;
		return 0;
	}
	cout << n - 1 - t << endl;
}