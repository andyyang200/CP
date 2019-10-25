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
map<string, int> m;
string x[100], y[100], z[100];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		cin >> x[i];
		if (x[i] == "jmp" || x[i] == "ret") {
			cin >> y[i];
		}
		else {
			cin >> y[i] >> z[i];
		}
	}
	FOR(i, 0, n) {
		string c = x[i];
		if (c == "set") {
			string a = y[i];
			string b = z[i];
			int v = 0;
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			m[a] = v;
		}
		if (c == "add") {
			string a = y[i];
			string b = z[i];
			int v = 0;
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			m[a] += v;
		}
		if (c == "sub") {
			string a = y[i];
			string b = z[i];
			int v = 0;
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			m[a] -= v;
		}
		if (c == "mul") {
			string a = y[i];
			string b = z[i];
			int v = 0;
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			m[a] *= v;
		}
		if (c == "div") {
			string a = y[i];
			string b = z[i];
			int v = 0;
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			m[a] /= v;
		}
		if (c == "mod") {
			string a = y[i];
			string b = z[i];
			int v = 0;
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			m[a] %= v;
		}
		if (c == "jmp") {
			int v = 0;
			string b = y[i];
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			if (v == 0) {
				v++;
			}
			i += v;
			i--;
		}
		if (c == "ret") {
			int v = 0;
			string b = y[i];
			if (b[0] >= 'a' && b[0] <= 'z') {
				v = m[b];
			}
			else {
				v = stoi(b);
			}
			cout << v << endl;
			return 0;
		}
	}

}