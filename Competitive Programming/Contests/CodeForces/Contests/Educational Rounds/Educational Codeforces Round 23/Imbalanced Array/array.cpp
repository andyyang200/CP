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
int a[1000005];
int l[1000005];
int r[1000005];
int main(void)
{
	int n;
	scanf("%d", &n);
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	stack<int> s;
	FOR(i, 0, n){
		while (s.size() > 0 && a[s.top()] < a[i]){
			s.pop();
		}
		if (s.size() == 0){
			l[i] = 0;
		}
		else{
			l[i] = s.top() + 1;
		}
		s.push(i);
	}
	while (s.size() > 0){
		s.pop();
	}
	RFOR(i, n - 1, -1){
		while (s.size() > 0 && a[s.top()] <= a[i]){
			s.pop();
		}
		if (s.size() == 0){
			r[i] = n - 1;
		}
		else{
			r[i] = s.top() - 1;
		}
		s.push(i);
	}
	ll b = 0;
	FOR(i, 0, n) {
		b += (ll)a[i] * (ll)(r[i] - i + 1) * (ll)(i - l[i] + 1);
	}
	while (s.size() > 0) {
		s.pop();
	}
	FOR(i, 0, n) {
		while (s.size() > 0 && a[s.top()] > a[i]) {
			s.pop();
		}
		if (s.size() == 0) {
			l[i] = 0;
		}
		else {
			l[i] = s.top() + 1;
		}
		s.push(i);
	}
	while (s.size() > 0) {
		s.pop();
	}
	RFOR(i, n - 1, -1) {
		while (s.size() > 0 && a[s.top()] >= a[i]) {
			s.pop();
		}
		if (s.size() == 0) {
			r[i] = n - 1;
		}
		else {
			r[i] = s.top() - 1;
		}
		s.push(i);
	}
	ll x = 0;
	FOR(i, 0, n) {
		x += (ll)a[i] * (ll)(r[i] - i + 1) * (ll)(i - l[i] + 1);
	}
	cout << b - x << endl;
}