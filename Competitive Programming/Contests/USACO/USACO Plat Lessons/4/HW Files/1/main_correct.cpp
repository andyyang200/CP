#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", z = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

vector<int> manacher(string s) {
	string t = "@#";
	for (int i = 0; i < s.length(); ++i) {
		t += s[i];
		t += "#";
	}
	t += "$";
	int n = t.length();
	vector<int> len(n);
	int l = 1, r = 1;
	for (int i = 1; i < n - 1; ++i) {
		len[i] = min(r - i, len[l + (r - i)]);
		while (t[i - len[i]] == t[i + len[i]]) ++len[i];
		if (i + len[i] > r) {
			l = i - len[i];
			r = i + len[i];
		}
	}
	return len;
}

int main(){
	string s;
	cin >> s;
	vector<int> v = manacher(s);
	int ans = 0;
	for(int i = 2; i < v.size() - 2; i++) {
        int x = v[i];
        ans = max(ans, x - 1);
	}
	cout << ans << endl;
}
