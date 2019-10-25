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
	int n;
	cin >> n;
	set<int> s;
	FOR(i, 0, n)
	{
		int x;
		cin >> x;
		s.insert(x);
	}
	vector<int> a;
	FOREACH(itr, s)
	{
		a.push_back(*itr);
	}
	sort(a.begin(), a.end());
	FOR(i, 2, a.size())
	{
		if (a[i - 2] == a[i - 1] - 1 && a[i - 1] == a[i] - 1)
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

}