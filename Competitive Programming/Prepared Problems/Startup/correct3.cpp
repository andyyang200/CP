// special MICE code with guest artist Braden Lamb!
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <cstring>
#include <cassert>
using namespace std;
#define rep(i,a,n) for (int i=a;i<(int)(n);i++)
#define per(i,a,n) for (int i=(n)-1;i>=(int)(a);i--)
template<typename T> ostream& operator<<(ostream& s, vector<T> t) {rep(i, 0, t.size()) s << (i ? " " : "") << t[i]; return s;}
template<typename T> istream& operator>>(istream& s, vector<T> &t) {rep(i, 0, t.size()) s >> t[i]; return s;}
template<typename T, typename U> ostream& operator<<(ostream& s, pair<T, U> t) {s << "(" << t.first << "," << t.second << ")"; return s;}
template<typename T, typename U> istream& operator>>(istream& s, pair<T, U> &t) {s >> t.first >> t.second; return s;}
typedef long long ll;

bool dfs(int a, int layer, const vector<vector<int>>&g, vector<int>&btoa,
	vector<int>&A, vector<int>&B) {
	if (A[a] != layer) return 0;
	A[a] = -1;
	for (auto &b : g[a]) if (B[b] == layer + 1) {
		B[b] = -1;
		if (btoa[b] == -1 || dfs(btoa[b], layer+2, g, btoa, A, B))
			return btoa[b] = a, 1;
	}
	return 0;
}

int hopcroftKarp(const vector<vector<int>>& g, vector<int>&btoa) {
	int res = 0;
	vector<int> A(g.size()), B(btoa.size()), cur, next;
	for (;;) {
		fill(A.begin(), A.end(), 0);
		fill(B.begin(), B.end(), -1);
		cur.clear();
		for (auto &a: btoa) if (a != -1) A[a] = -1;
		rep(a, 0, g.size()) if (A[a] == 0) cur.push_back(a);
		for (int lay=1;;lay += 2) {
			bool islast = 0;
			next.clear();
			for (auto&a:cur) for (auto &b: g[a]) {
				if (btoa[b] == -1) {
					B[b] = lay;
					islast = 1;
				} else if (btoa[b] != a && B[b] == -1) {
					B[b] = lay;
					next.push_back(btoa[b]);
				}
			}

			if (islast) break;
			if (next.empty()) return res;
			for (auto &a: next) A[a] = lay + 1;
			cur.swap(next);
		}
		rep(a, 0, g.size())
			res += dfs(a, 0, g, btoa, A, B);
	}
	return res;
}

vector<vector<int>> G;
int n, m;

#define LEAD 0
#define FRIEND 1
#define LOSER 2

bool try_lead(int lead)
{
	if (G[lead].size() * 2 + 3 < n)
		return false; // Zbytek nepůjde namatchovat

	//int closer = 0;
	vector<int> c(n,LOSER);
	c[lead] = LEAD;
	for (auto s: G[lead])
		c[s] = FRIEND;
	
	//rep(v, 0, n)
	//	closer += c[v] == LOSER;

	int mm = 0;	
	vector<vector<int>> F(n);
	rep(v, 0, n) {
		for (auto s: G[v])
			if (c[s] + c[v] == 3 && c[v] == LOSER)
				F[v].push_back(s), mm++;
	}

	/*assert(mm % 2 == 0);
	mm /= 2;*/
	vector<int> ba(n, -1); hopcroftKarp(F, ba);

	vector<int> mates(n,-1);
	set<pair<int,int>> teams;
	rep(v, 0, n) {
		int u = ba[v];
		if (u != -1)
			mates[u] = v, mates[v] = u;
	}

	rep(v, 0, n) {
		int u = mates[v];
		assert(-1 <= u && u < n);
		if (u == lead || v == lead) {
			assert(u + v == lead - 1);
			continue;
		}

		int a = min(u, v), b = max(u, v);
		teams.insert({b, a});
	}

	for (auto a: teams)
		if ((a.first == -1 || c[a.first] != FRIEND) && (a.second == -1 || c[a.second] != FRIEND))
			return false;

#define ASS(a) assert(a)
	set<int> check;	
	for (auto a: teams) {
		ASS(!check.count(a.first) && !check.count(a.second));
		if (a.first != -1)
			check.insert(a.first);
		if (a.second != -1)
			check.insert(a.second);
	}

	//ASS(check.size() == n - 1 && !check.count(lead));

	cout << "Yes\n";
	cout << lead + 1 <<" "<<teams.size()<<"\n";
	for (auto a: teams) {
		if (a.first > -1)
			a.first++;
		if (a.second > -1)
			a.second++;

		cout << a.first <<" "<<a.second<<"\n";
	}
	return true;
}
				
int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	G.resize(n);
	rep(i, 0, m) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}

	rep(v, 0, n)
		if (try_lead(v))
			return 0;
	cout << "No\n";
}
