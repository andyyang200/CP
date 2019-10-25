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
#include <cassert>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;
int l[1000001];
int r[1000001];
int d[1000001];
struct block {
	char letter;
	int position;
	int length;
};
int main(void)
{
	string s;
	cin >> s;
	int n = s.length();
	int l = 0;
	set<block> t;
	FOR(i, 1, n) {
		if (s[i] != s[i - 1]) {
			block b;
			b.letter = s[i - 1];
			b.position = l;
			b.length = i - l;
			t.insert(b);
			l = i;
		}
	}
	block b;
	b.letter = s[n - 1];
	b.position = l;
	b.length = n - l;
	t.insert(b);
	int ans = 0;
	while (t.size() > 1) {

	}
}