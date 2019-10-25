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

int main(void)
{
	while (true) {
		int n;
		cin >> n;
		if (n == 0) break;
		vector<int> p(n);
		FOR(i, 0, n) {
			scanf("%d", &p[i]);
		}
		int X, Y;
		scanf("%d%d", &X, &Y);
		map<ll, bool> m;
		vector<ll> v;
		vector<int> ans;
		v.push_back(1);
		m[1] = true;
		if (1 >= X && 1 <= Y) {
			ans.push_back(1);
		}
		FOR(i, 0, v.size()) {
			ll x = v[i];
			FOR(j, 0, n) {
				ll y = x * p[j];
				if (y <= Y && m.find(y) == m.end()) {
					m[y] = true;
					v.push_back(y);
					if (y >= X)
						ans.push_back(y);
				}
			}
		}
		if (ans.size() == 0) {
			cout << "none" << endl;
		}
		else {
			sort(ans.begin(), ans.end());
			FOR(i, 0, ans.size()){
				cout << ans[i];
				if (i < ans.size() - 1){
					cout << ",";
				}
			}
			cout << endl;
		}
	}
}
/*
1
3
1 12
2 
2 3
10 20
3
2 3 5
20
30
1
17
20
30
0
*/