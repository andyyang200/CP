//Andy Yang
#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;


string move(string s, int x) {
	string t = s.substr(s.length() - x, x);
	reverse(t.begin(), t.end());
	return t + s.substr(0, s.length() - x);
}

int main(void)
{
	int n;
	cin >> n;
	string s;
	string t;
	cin >> s >> t;
}
