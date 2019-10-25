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
struct Node {
	int val;
	struct Node* C[2];
	Node() {
		val = 0;
		C[0] = C[1] = NULL;
	}
	Node* getc(int c) {
		if (!C[c]) {
			C[c] = new Node;
		}
		return C[c];
	}
	void update(int x, int v, int sl, int sr) {
		val += v;
		if (sl == sr) {
			return;
		}
		int m = (sl + sr) / 2;
		if (x < m) {
			getc(0)->update(x, v, sl, m);
		}
		else {
			getc(1)->update(x, v, m + 1, sr);
		}
		// val = max(getc(1)->val, getc(0)->val); for max/min query
	}
	int query(int a, int b, int sl, int sr) {
		if (a <= sl && sr <= b) {
			return val;
		}
		else if (sr <= a || b <= sl) {
			return 0;
		}
		int m = (sl + sr) / 2;
		return (C[0] ? C[0]->query(a, b, sl, m) : 0) +
			(C[1] ? C[1]->query(a, b, m, sr) : 0);
	}
};
int main(void)
{
	//freopen("rename_this.in", "r", stdin);
	//freopen("rename_this.out", "w", stdout);
}