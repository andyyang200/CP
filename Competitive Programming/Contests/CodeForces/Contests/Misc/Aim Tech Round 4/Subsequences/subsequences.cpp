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
int p[100005];
bool visited[100005];
int main(void)
{
	int n;
	cin >> n;
	vector<int> v;
	FOR(i, 0, n) {
		scanf("%d", &p[i]);
		v.push_back(p[i]);
	}
	sort(v.begin(), v.end());
	FOR(i, 0, n) {
		p[i] = lower_bound(v.begin(), v.end(), p[i]) - v.begin();
	}
	int ans = 0;
	string out = "";
	FOR(i, 0, n) {
		if (visited[i]) {
			continue;
		}
		int j = i;
		vector<int> lst;
		while (!visited[j]) {
			visited[j] = true;
			lst.push_back(j);
			j = p[j];
		}
		out += to_string(lst.size()) + " ";
		for (int x : lst) {

			out += to_string(x + 1) + " ";
		}
		ans++;
		out += "\n";
	}
	cout << ans << endl;
	cout << out << endl;



}