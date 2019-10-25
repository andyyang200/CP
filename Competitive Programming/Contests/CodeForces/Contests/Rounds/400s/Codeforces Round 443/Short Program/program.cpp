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
char c[500005];
int v[500005];
int dif[50];
int z[50];
int o[50];
bool on(int x, int i) {
	return (x & (1 << i));
}
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		scanf(" %c %d", &c[i], &v[i]);
	}
	FOR(i, 0, 10) {
		dif[i] = true;
		o[i] = true;
		z[i] = true;
	}
	FOR(k, 0, 10){
		int j = 0;
		int i = 0;
		FOR(x, 0, n) {
			if (c[x] == '&') {
				j &= v[x];
			}
			if (c[x] == '|') {
				j |= v[x];
			}
			if (c[x] == '^') {
				j ^= v[x];
			}
		}
		if (on(j, k) == on(i, k)) {
			dif[k] = false;
		}
		if (on(j, k)) {
			z[k] = false;
		}
		if (!on(j, k)) {
			o[k] = false;
		}
		i += 1 << k;
		j = i;
		FOR(x, 0, n) {
			if (c[x] == '&') {
				j &= v[x];
			}
			if (c[x] == '|') {
				j |= v[x];
			}
			if (c[x] == '^') {
				j ^= v[x];
			}
		}
		if (on(j, k) == on(i, k)) {
			dif[k] = false;
		}
		if (on(j, k)) {
			z[k] = false;
		}
		if (!on(j, k)) {
			o[k] = false;
		}
		
	}
	cout << 3 << endl;
	int x = 0;
	FOR(i, 0, 10) {
		if (dif[i]) {
			x |= (1 << i);
		}
	}
	cout << "^ " << x << endl;
	x = 0;
	FOR(i, 0, 10) {
		if (o[i]) {
			x |= (1 << i);
		}
	}
	cout << "| " << x << endl;
	x = 0;
	FOR(i, 0, 10) {
		if (!z[i]) {
			x |= (1 << i);
		}
	}
	cout << "& " << x << endl;
}