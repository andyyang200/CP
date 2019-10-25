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
int p[1000];
int main(void)
{
	ll n, k;
	cin >> n >> k;
	int m = 0;
	FOR(i, 0, n) {
		cin >> p[i];
		m = max(m, p[i]);
	}
	if (k > n) {
		cout << m << endl;
		return 0;
	}
	int w = 0;
	while (true) {
		int a = p[0];
		int b = p[1];
		if (a > b) {
			w++;
			if (w == k) {
				cout << p[0] << endl;
				return 0;
			}
			
		}
		else {
			w = 1;
		}
		int back = min(a, b);
		FOR(i, 1, n - 1) {
			p[i] = p[i + 1];
		}
		p[n - 1] = back;
		p[0] = max(a, b);
	}
}