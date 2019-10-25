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

// Given a tree, find the number of paths with distance exactly K

getCentroid(int u, int p){
	for(int v : edges[u]){
		if (v == p) continue;
		if (sz[v] > n / 2){
			getCentroid(v, u)
		}
	}
	return u;
}

int D[100005]; // D[i] = number of nodes of distance i from the centroid
void addD(int u, int p, int d){
	D[d]++;
	for(int v : edges[u]){
		if (v == p) continue;
		addD(v, u, d + 1);
	}
}
void removeD(int u, int p, int d){
	D[d]--;
	for(int v : edges[u]){
		if (v == p) continue;
		removeD(v, u, d + 1);
	}
}

int count(int u, int p, int d){
	int ans = D[K - d];
	for(int v : edges[u]){
		ans += count(v, u, d + 1);
	}
}

int decompose(int x){
	int c = findCentroid(x, -1);
	int ans = 0;
	fill(D, D + n, 0);
	D[0] = 1;
	for(int y : edges[c]) 
		addD(y, c, 0);

	for(int y : edges[c]){
		removeD(y, c, 0);
		count(y, c, -1);
		addD(y, c, 0)
	}

	for(int y : edges[c]){
		for(auto it= edges[y].begin(); it != edges[y].end; it++){
			if (*it == c){
				edges[y].erase(it);
				break;
			}
		}
		ans += decompose(y);
	}
	return ans;
}

decompose(0);



















d[i][k]=number of children of i with distance k from i

int get(int u, int p)// number of paths of length k that pass through u and is inside the subtree of u
{
	int ans = d[u][k];
	int sum = 0;
	for(int v : edges[u]){
		if (v == p)continue;
		for(int k = 1; k < K - 1; k++){
			sum += d[v][k] * (dp[u][K - k - 1] - dp[v][K - k - 2]);
		}
	}
	sum /= 2;
	return ans + sum;
}

int main(void)
{

}


