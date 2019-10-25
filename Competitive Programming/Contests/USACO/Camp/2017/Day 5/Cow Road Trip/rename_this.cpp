//Andrew Yang
//Accepted
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
#define INF 1000000000
#define M 1000000007
#define MAXN 100010
typedef long long ll;
typedef pair<int, int> pii;
vector< pair<int, int> > edges[MAXN];
ll d[MAXN];
int n;
int a[MAXN];
int b[MAXN];
int w[MAXN];
int main()
{
	cin >> n;
	set<int> s;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> a[i] >> b[i] >> w[i];
		a[i]--;
		b[i]--;
		s.insert(w[i]);
	}
	vector<int> v;
	for (int x : s)
		v.push_back(x);
	sort(v.begin(), v.end());
	for (int i = 0; i < n - 1; i++) {
		w[i] = lower_bound(v.begin(), v.end(), w[i]) - v.begin();
	}
	for (int i = 0; i < n - 1; i++) {
		edges[w[i]].push_back({ a[i], b[i] });
		edges[w[i]].push_back({ b[i], a[i] });
	}
	ll ans = 0;
	ll temp[MAXN];
	for (int x = 0; x < n; x++)
	{
		for (int i = 0; i < edges[x].size(); i++)
		{
			int u = edges[x][i].first;
			int v = edges[x][i].second;
			temp[v] = d[v];
		}
		for (int i = 0; i < edges[x].size(); i++)
		{
			int u = edges[x][i].first;
			int v = edges[x][i].second;
			temp[v] += d[u] + 1;
		}
		for (int i = 0; i < edges[x].size(); i++)
		{
			int u = edges[x][i].first;
			int v = edges[x][i].second;
			d[v] = temp[v];
		}
	}
	for (int i = 0; i < n; i++) {
		ans += d[i];
	}
	cout << ans << endl;
}