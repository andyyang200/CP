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
	int n, k;
	cin >> n >> k;
	vector<int> v;
	FOR(i, 2, n + 1) {
		v.push_back(i);
	}
	n--;
	vector<int> lengths;
	vector<pii> ans;
	int branch = k;
	FOR(i, 0, k) {
		int l = ceil((double)n / branch);
		lengths.push_back(l);
		int previous = 1;
		FOR(i, 0, l) {
			ans.push_back({ previous, v.back() });
			previous = v.back();
			v.pop_back();
		}
		n -= l;
		branch--;
	}
	sort(lengths.begin(), lengths.end());
	cout << lengths.back() + lengths[lengths.size() - 2] << endl;
	for (pii x : ans) {
		cout << x.first << " " << x.second << endl;
	}
}