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
int a[100];
vector<int> v;
set<int> s;
map<int, int> m;
int main(void)
{
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
		v.push_back(i);
		s.insert(i);
	}
	sort(a, a + n);
	sort(v.begin(), v.end());

	cout << binary_search(a, a + n, 5) << endl;
	cout << binary_search(v.begin(), v.end(), 5) << endl;

	cout << upper_bound(a, a + n, 5) - a << endl;
	cout << lower_bound(v.begin(), v.end(), 5) - v.begin() << endl;

	cout << find(a, a + n, 5) - a << endl;
	cout << *find(s.begin(), s.end(), 5) << endl;

	cout << *s.find(6) << endl;
	cout << m.find(6)->second << endl;
}