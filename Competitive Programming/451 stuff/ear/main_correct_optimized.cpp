#include <bits/stdc++.h>
using namespace std;
struct linked_list1{
    int x;
    linked_list1* next;
};
struct linked_list2{
    pair<int, int> x;
    linked_list2* next;
};
linked_list1* add1(linked_list1* l, int x){
    linked_list1* l2 = (linked_list1*)malloc(sizeof(linked_list1));
    l2->x = x;
    l2->next = l;
    return l2;
}
linked_list2* add2(linked_list2* l, pair<int, int> x){
    linked_list2* l2 = (linked_list2*)malloc(sizeof(linked_list2));
    l2->x = x;
    l2->next = l;
    return l2;
}
linked_list1* edges[1000001];
linked_list2* b[1000001];
bool visited[1000001];
bool used[1000001];
int depth[1000001];
int p[1000001];
int earsize[1000001];
linked_list1* ans[1000001];
void dfs(int u) {
	visited[u] = true;
	for(linked_list1* itr = edges[u]; itr != NULL; itr = itr->next){
        int v = itr->x;
		if (v == p[u]) continue;
		if (visited[v] && depth[v] < depth[u])
            b[depth[v]] = add2(b[depth[v]], {v, u});
		else if (!visited[v]) {
			p[v] = u;
			depth[v] = depth[u] + 1;
			dfs(v);
		}
	}
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		edges[u] = add1(edges[u], v);
		edges[v] = add1(edges[v], u);
	}
	p[0] = -1;
	dfs(0);
	printf("%d\n", m - n + 1);
	for (int d = 0; d < n; ++d) {
        for(linked_list2* itr = b[d]; itr != NULL; itr = itr->next){
            pair<int, int> e = itr->x;
			linked_list1* ear = NULL;
			int v = e.first;
			int u = e.second;
			int u2 = u;
			int earsize = 1;
			while (u2 != v && !used[u2]) {
				u2 = p[u2];
				++earsize;
			}
			printf("%d ", earsize);
			printf("%d %d ", v, u);
			while (u != v && !used[u]) {
				used[u] = true;
				printf("%d %d ", u, p[u]);
				u = p[u];
			}
			printf("\n");
		}
	}
}



