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

int main()
{
	string s;
	cin >> s;
	int k;
	scanf("%d", &k);
	if (s.length() % k != 0)
	{
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < s.length(); i += (s.length() / k))
	{
		string str = s.substr(i, s.length() / k);
		string rev = str;
		reverse(rev.begin(), rev.end());
		if (str != rev)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
}