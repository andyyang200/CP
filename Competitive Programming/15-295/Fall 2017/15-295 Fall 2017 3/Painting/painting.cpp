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
int color[100005];
bool used[100001];
int main(void)
{
	int n;
	cin >> n;
	color[1] = 1;
	FOR(i, 2, n + 1) {
		vector<int> factors;
		for (int j = 2; j < sqrt(i); j++) {
			if (i % j == 0) {
				factors.push_back(j);
				factors.push_back(i / j);
			}
		}
		factors.push_back(1);
		int x = (int)round(sqrt(i));
		if (x * x == i) {
			factors.push_back(x);
		}
		for (int f : factors) {
			used[color[f]] = 1;
		}
		FOR(j, 1, 100001) {
			if (!used[j]) {
				color[i] = j;
				break;
			}
		}
		for (int f : factors) {
			used[color[f]] = 0;
		}
	}
	set<int> s;
	FOR(i, 1, n + 1) {
		s.insert(color[i]);
	}
	cout << s.size() << endl;
	FOR(i, 1, n + 1) {
		cout << color[i] << " ";
	}
	cout << endl;

}