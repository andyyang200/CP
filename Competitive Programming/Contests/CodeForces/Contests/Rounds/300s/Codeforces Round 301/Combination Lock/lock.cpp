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
int first[1001];
int second[1001];
int main()
{
	int n;
	cin >> n;
	string a, b;
	cin >> a >> b;
	FOR(i, 0, n)
	{
		first[i] = a[i] - '0';
		second[i] = b[i] - '0';
	}
	int ans = 0;
	FOR(i, 0, n)
	{
		ans += min(abs(first[i] - second[i]), min(first[i] + 10 - second[i], second[i] + 10 - first[i]));
	}
	cout << ans << endl;
}