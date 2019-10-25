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
bool good[500];
int main(void)
{
	string s;
	cin >> s;
	FOR(i, 0, s.length()) {
		good[s[i]] = true;
	}
	
	cin >> s; // match to this
	int n;
	cin >> n;
	FOR(asd, 0, n) {
		string q;
		cin >> q;
		int i;
		bool ok = true;
		for (i = 0; i < q.length(); i++) {
			if (s[i] == '*') {
				break;
			}
			else if (s[i] == '?') {
				if (!good[q[i]]) {
					ok = false;
				}
			}
			else if (s[i] != q[i]) {
				ok = false;
			}
		}
		int j;
		for(j = s.length() - 1; j > i; j--){
			if (s[j] == '?') {
				if (!good[q[j]]) {
					ok = false;
				}
			}
			else if (s[j] != q[q.length() - (s.length() - j)]) {
				ok = false;
			}
		}
		if (s[i] == '*'){
			for(i; i < j + 1; i++){
				if (good[q[i]]){
					ok = false;
					break;
				}
			}
		}
		if (ok){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
	
}
/*
cba
?*cbc
1
cbc
*/