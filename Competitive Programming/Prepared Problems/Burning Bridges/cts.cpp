#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define INF 1000000000000000LL
#define MAXN 200005
using namespace std;
struct linked_list2{
    pair<int, int> x;
    linked_list2* next;
};
linked_list2* add2(linked_list2* l, pair<int, int> x){
    linked_list2* l2 = (linked_list2*)malloc(sizeof(linked_list2));
    l2->x = x;
    l2->next = l;
    l = l2;
    return l2;
}
ll dp[MAXN][2];
linked_list2* edges[MAXN];
bool a[MAXN];
bool b[MAXN];
void dfs(int node, int p){
    for(auto itr = edges[node]; itr != NULL; itr = itr->next){
        pii x = itr->x;
		int v = x.first;
		int w = x.second;
		if (v == p) continue;
		dfs(v, node);
		dp[node][0] += min(dp[v][0], dp[v][1] + w);
		dp[node][1] += min(dp[v][1], dp[v][0] + w);
	}
	if (a[node])
        dp[node][0] = INF;
	if (b[node])
        dp[node][1] = INF;
}
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n - 1; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edges[u] = add2(edges[u], {v, w});
		edges[v] = add2(edges[v], {u, w});
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		a[x] = true;
	}
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		b[x] = true;
	}
	dfs(1, -1);

	printf("%lld\n", min(dp[1][0], dp[1][1]));
}
