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
ll price[300001];
int main() {
	int n, l;
	scanf("%d", &n);
	FOR(i, 0, n){
		cin >> price[i];
	}
	multiset<ll> L;
	multiset<ll> R;
	ll m = 0;
	FOR(i, 0, n) {
		if (R.lower_bound(price[i]) == R.begin()) {
			L.insert(price[i]);
		}
		else {
			R.insert(price[i]);
			m -= *R.begin();
			m += price[i];
			L.insert(*R.begin());
			R.erase(R.begin());
		}
		if (L.upper_bound(price[i]) == L.end()) {
			R.insert(price[i]);
		}
		else {
			L.insert(price[i]);
			m += *L.rbegin();
			m -= price[i];
			R.insert(*L.rbegin());
			L.erase(--L.end());
		}
		if (R.size() > n) {
			R.erase(--R.end());
		}
		if (L.size() > 0) {
			L.erase(L.begin());
		}
	}
	cout << m << endl;
}