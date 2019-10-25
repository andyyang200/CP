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

/*
Mo's algorithm

You have an array of N element and Q queries.
For each query, how many distinct elements appear at least 3 times
in the range [Li, Ri]?
*/










int n;

struct query {
	int l, r, i;
	bool operator<(query o) {
		int block1 = l / sqrt(n);
		int block2 = o.l / sqrt(n);
		if (block1 != block2) {
			return block1 < block2;
		}
		return r < o.r;
	}
};
int curAnswer;
int a[100005];
int cnt[100005];
query queries[100005];
int ans[100001];
void add(int position) {
	cnt[a[position]]++;
	if (cnt[a[position]] == 3){
		curAnswer++;
	}
}

void remove(int position) {
	cnt[a[position]]--;
	if (cnt[a[position]] == 2){
		curAnswer--;
	}
}
int main() {
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> a[i];
	}
	int q;
	cin >> q;
	FOR(i, 0, q) {
		cin >> queries[i].l >> queries[i].r;
		queries[i].i = i;
	}
	int currentL = 0;
	int currentR = 0;
	curAnswer = 0;
	sort(queries, queries + q);
	FOR(i, 0, q) {
		while (currentL < queries[i].l) {
			remove(currentL);
			currentL++;
		}
		while (currentL > queries[i].l) {
			add(currentL);
			currentL--;
		}
		while (currentR < queries[i].r) {
			add(currentR);
			currentR++;
		}
		while (currentR > queries[i].r) {
			remove(currentR);
			currentR--;
		}
		ans[queries[i].i] = curAnswer;
	}
	FOR(i, 0, q) {
		cout << ans[i] << endl;
	}
}