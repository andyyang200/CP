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
struct Segment {
	int value;
	int length;
	int position;
};
struct comp1 {
	bool operator() (const Segment& a, const Segment& b) const
	{
		if (a.length > b.length) return true;
		if (a.length < b.length) return false;
		return a.position < b.position;
	}
};
struct comp2 {
	bool operator() (const Segment& a, const Segment& b) const
	{
		return a.position < b.position;
	}
};
int a[200005];
int main(void)
{
	int n;
	cin >> n;
	FOR(i, 0, n) {
		scanf("%d", &a[i]);
	}
	int l = 0;
	multiset<Segment, comp1> s1;
	multiset<Segment, comp2> s2;
	FOR(i, 1, n) {
		if (a[i] != a[i - 1]) {
			Segment seg;
			seg.value = a[i - 1];
			seg.position = l;
			seg.length = i - l;
			l = i;
			s1.insert(seg);
			s2.insert(seg);
		}
	}
	Segment seg;
	seg.value = a[n - 1];
	seg.position = l;
	seg.length = n - l;
	s1.insert(seg);
	s2.insert(seg);
	int ans = 0;
	while (!s1.empty()) {
		Segment seg = *s1.begin();
		auto itr = s2.lower_bound(seg);
		if (itr == --s2.end() || itr == s2.begin()) {
			s1.erase(s1.begin());
			s2.erase(itr);
		}
		else {
			auto left = itr;
			auto right = itr;
			left--;
			right++;
			if (left->value != right->value) {
				s1.erase(s1.begin());
				s2.erase(itr);
			}
			else {
				Segment seg2;
				seg2.value = left->value;
				seg2.position = left->position;
				seg2.length = left->length + right->length;
				s1.erase(s1.begin());
				s1.erase(s1.find(*left));
				s1.erase(s1.find(*right));
				s2.erase(left);
				s2.erase(right);
				s2.erase(itr);
				s1.insert(seg2);
				s2.insert(seg2);
			}
		}
		ans++;
	}
	cout << ans << endl;
}