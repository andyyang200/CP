#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------

int permutation[301];
int group[301];
vector<vector<int> > groups;
char A[301][301];
int n;

void findgroup(int g, int i){
	group[i] = g;
	groups[g].push_back(permutation[i]);
	FOR(j, 0, n){
		if (j != i && group[j] == -1 && A[i][j] == '1'){
			findgroup(g, j);
		}
	}
}

int main()
{
	cin >> n;
	FOR(i, 0, n){
		cin >> permutation[i];
		group[i] = -1;
	}
	FOR(r, 0, n){
		FOR(c, 0, n){
			cin >> A[r][c];
		}
	}
	FOR(i, 0, n){
		if (group[i] == -1)	{
			groups.push_back(vector<int>());
			findgroup(groups.size() - 1, i);
		}
	}
	FOR(i, 0, groups.size()){
		sort(groups[i].begin(), groups[i].end());
	}
	FOR(i, 0, n){
		cout << groups[group[i]][0] << " ";
		groups[group[i]].erase(groups[group[i]].begin());
	}
	cout << endl;
}
