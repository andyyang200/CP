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
#include <map>
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
#define FOR(index, start, end) for(int index = start; index < end; index++)
#define RFOR(index, start, end) for(int index = start; index > end; index--)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); itr++)
#define RFOREACH(itr, b) for(auto itr = b.rbegin(); itr != b.rend(); itr++)
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef pair<int, int> pii;

int p[100];
int res[100][100]; // initialize
ll mf, f;
int s, t; // initialize
int n; // initialize
void augment(int v, int minEdge){
	if (v == s){
		f = minEdge;
		return;
	}
	else if (p[v] != -1){
		augment(p[v], min(minEdge, res[p[v]][v]));
		res[p[v]][v] -= f;
		res[v][p[v]] += f;
	}
}
int maxflow(){
	mf = 0;
	while (true){
		f = 0;
		int dist[100];
		FOR(i, 0, n){
			dist[i] = 1000000000;
		}
		dist[s] = 0;
		queue<int> q;
		q.push(s);
		while (!q.empty()){
			int u = q.front();
			q.pop();
			if (u == t){
				break;
			}
			for (int v = 0; v < n; v++){
				if (res[u][v] > 0 && dist[v] == 1000000000){
					dist[v] = dist[u] + 1;
					q.push(v);
					p[v] = u;
				}
			}
		}
		augment(t, 1000000000);
		if (f == 0){
			break;
		}
		mf += f;
	}
	return mf;
}




int main(){

}
