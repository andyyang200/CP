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
Player A and player B both have N characters.
They have an array of length N that is initially empty. The players alternately put one of their characters 
into an empty spot in the array. Player A wants to minimize the lexicographic value of the array
and Player B wants to maximize it. Player A goes first.

Print out the final array, if both players play optimally.
N <= 100000
*/














char ans[100005];
int main(void)
{
	string s1, s2;
	cin >> s1 >> s2;
	multiset<char> a;
	multiset<char> b;
	int n = s1.length();
	int n1 = ceil((double)n / 2);
	int n2 = n / 2;
	FOR(i, 0, n) {
		a.insert(s1[i]);
		b.insert(s2[i]);
	}
	FOR(i, 0, n - n1) {
		a.erase(--a.end());
	}
	FOR(i, 0, n - n2) {
		b.erase(b.begin());
	}
	int i = 0;
	int j = n - 1;
	int turn = 0;
	FOR(x, 0, n) {
		if (turn % 2 == 0) { // a
			if (b.size() == 0) {
				ans[i] = *a.begin();
				break;
			}
			if (*a.begin() < *(--b.end())) {
				ans[i++] = *a.begin();
				a.erase(a.begin());
			}
			else {
				ans[j--] = *(--a.end());
				a.erase(--a.end());
			}
		}
		else { // b;
			if (a.size() == 0) {
				ans[i] = *b.begin();
				break;
			}
			if (*(--b.end()) > *a.begin()) {
				ans[i++] = *(--b.end());
				b.erase(--b.end());
			}
			else {
				ans[j--] = *b.begin();
				b.erase(b.begin());
			}
		}
		turn++;
	}
	FOR(x, 0, n) {
		cout << ans[x];
	}
	cout << endl;

}