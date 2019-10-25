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
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int p[300005];
bool on[300001];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> p[i];
		p[i]--;
	}
	int x = n - 1;
	int l = 0;
	cout << 1 << " ";
	FOR(i, 0, n) {
		if (p[i] < x) {
			l++;
		}
		on[p[i]] = true;
		if (on[x])l++;
		while (x >= 0 && on[x]) {
			x--;
			l--;
		}
		cout << l + 1 << " ";
	}
	cout << endl;
}