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
int a[200001], b[200001];
bool cmp(const int& x,const int& y)
{
	return (a[x] - b[x]) < (a[y] - b[y]);
}
int main(void)
{
	int n, k;
	scanf("%d%d", &n, &k);
	FOR(i, 0, n)
	{
		scanf("%d", &a[i]);
	}
	vector<int> v;
	FOR(i, 0, n)
	{
		v.push_back(i);
		scanf("%d", &b[i]);
	}
	sort(v.begin(), v.end(), cmp);
	ll ans = 0;
	FOR(i, 0, v.size())
	{
		if (a[i] <= b[i] || i < k)
		{
			ans += a[i];
		}
		else
		{
			ans += b[i];
		}
	}
	cout << ans << endl;
}