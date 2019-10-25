#include<stdio.h>
#include<malloc.h>

typedef long long ll;
#define INF 1000000000000000LL
#define MAXN 200005

struct linked_list2{
    int v, weight;
    struct linked_list2* next;
};

typedef struct linked_list2 linked_list2;
struct linked_list2* add2(struct linked_list2* l, int v, int weight){
    linked_list2* l2 = (linked_list2*)malloc(sizeof(linked_list2));
    l2->v = v;
    l2->weight = weight;
    l2->next = l;
    l = l2;
    return l2;
}
ll dp[MAXN][2];
linked_list2* edges[MAXN];
int a[MAXN];
int b[MAXN];
ll min(ll a, ll b){
    return a < b ? a : b;
}
void dfs(int node, int p){
    for(linked_list2* itr = edges[node]; itr != NULL; itr = itr->next){
        int v = itr->v;
		int w = itr->weight;
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
		edges[u] = add2(edges[u], v, w);
		edges[v] = add2(edges[v], u, w);
	}
	int q;
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		a[x] = 1;
	}
	scanf("%d", &q);
	for(int i = 0; i < q; ++i) {
		int x;
		scanf("%d", &x);
		b[x] = 1;
	}
	dfs(1, -1);

	printf("%lld\n", min(dp[1][0], dp[1][1]));
}


