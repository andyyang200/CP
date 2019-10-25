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
#include <map>
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int, int> > s1; // possible answers where right side of subarray is i
	vector<int> s2;
	int su = 0; // oranges - apples so far
	int s0 = 0;
	int op = 0; // index of answer in s1
	int v = 0;	//answer
	for (int i = 0; i < n; i++) {
		if (s[i] == 'j') {
			su--;
			while (s1.size() > 0 && su < s1.back().second) {
				s1.pop_back();
			}
			s0++;
		}
		if (s[i] == 'p') {
			s1.push_back(make_pair(i, su));
			su++;

			if (s2.size() == 0) {
				s2.push_back(i);
			}
			else {
				if (s0 > 1) {
					for (int ii = 1; ii < s0; ii++) {
						s2.push_back(i);
					}
				}
				if (s0 == 0 && s2.size() > 1) {
					s2.pop_back();
				}
			}
			s0 = 0;
			op = min(op, (int)s1.size());
			while (op > 0 && s1[op - 1].first >= s2.back()) {
				op--;
			}
			while (op < s1.size() && s1[op].first < s2.back()) {
				op++;
			}
			if (op < s1.size()) {
				v = max(v, i - s1[op].first + 1);
			}
		}
	}
	cout << v << endl;
}

/*
28
jppjpjjpjjpjpppjpjjpjppjjjpj


13
*/