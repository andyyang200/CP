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
struct range {
	int i;
	int l;
	int r;
	bool operator<(range o) {
		if (l != o.l) {
			return l < o.l;
		}
		return r > o.r;
	}
};
string strings[100005];
vector<range> v;
int main(void)
{
	int n;
	scanf("%d", &n);
	vector<range> temp;
	FOR(i, 0, n) {
		string s;
		cin >> s;
		int k;
		scanf("%d", &k);
		FOR(j, 0, k) {
			range r;
			r.i = i;
			scanf("%d", &r.l);
			r.r = r.l + s.length() - 1;
			temp.push_back(r);
		}
		strings[i] = s;
	}
	sort(temp.begin(), temp.end());
	vector<range> v;
	FOR(i, 0, temp.size())
	{
		if (!v.empty() && v.back().r >= temp[i].r)
		{
			continue;
		}
		v.push_back(temp[i]);
	}
	int maxi = 0;
	int j = 0;
	FOR(i, 0, v.size()) {
		while (j < v[i].l - 1) {
			cout << "a";
			j++;
		}
		if (j <= v[i].r) {
			FOR(k, j - v[i].l + 1, strings[v[i].i].length()) {
				cout << strings[v[i].i][k];
			}
			j = v[i].r;
		}
	}
	cout << endl;
}