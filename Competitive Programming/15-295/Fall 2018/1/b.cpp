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

//---------------------------------------------------------------------------------------------------------------
pair<string, string> read() {
	string s, t;
	cin >> s >> t >> t >> t >> t;
	return { s, t };
}

map<string, vector<string>> m1;
map<string, vector<string>> m2;
map<string, bool> visited;

void dfs(string s) {
	if (visited[s]) return;
	visited[s] = true;
	for (string t : m1[s]) {
		dfs(t);
	}
}
void dfs2(string s) {
	if (visited[s]) return;
	visited[s] = true;
	for (string t : m2[s]) {
		dfs2(t);
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	FOR(i, 0, n) {
		pair<string, string> p = read();
		string a = p.first;
		string b = p.second;
		m1[a].push_back(b);
		m2[b].push_back(a);
	}
	FOR(i, 0, m) {
		pair<string, string> p = read();
		string a = p.first;
		string b = p.second;
		visited.clear();
		dfs(a);
		bool x = visited[b];
		visited.clear();
		dfs2(a);
		bool y = visited[b];

		if (x) {
			cout << "Fact" << endl;
		}
		else if (y) {
			cout << "Alternative Fact" << endl;
		}
		else {
			cout << "Pants on Fire" << endl;
		}

	}
}
