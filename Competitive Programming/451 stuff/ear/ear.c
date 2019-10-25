#include<stdio.h>
#include<malloc.h>
struct linked_list1{
    int x;
    struct linked_list1* next;
};
struct linked_list2{
    int a, b;
    struct linked_list2* next;
};
typedef struct linked_list1 linked_list1;
typedef struct linked_list2 linked_list2;
linked_list1* add1(linked_list1* l, int x){
    linked_list1* l2 = (linked_list1*)malloc(sizeof(linked_list1));
    l2->x = x;
    l2->next = l;
    l = l2;
    return l2;
}
linked_list2* add2(linked_list2* l, int a, int b){
    linked_list2* l2 = (linked_list2*)malloc(sizeof(linked_list2));
    l2->a = a;
    l2->b = b;
    l2->next = l;
    l = l2;
    return l2;
}
linked_list1* edges[1000001];
linked_list2* b[1000001];
int visited[1000001];
int used[1000001];
int depth[1000001];
int p[1000001];
int earsize[1000001];
linked_list1* ans[1000001];
void dfs(int u) {
	visited[u] = 1;
	for(linked_list1* itr = edges[u]; itr != NULL; itr = itr->next){
        int v = itr->x;
		if (v == p[u]) continue;
		if (visited[v] && depth[v] < depth[u])
            b[depth[v]] = add2(b[depth[v]], v, u);
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
	int earcnt = 0;
	for (int d = 0; d < n; ++d) {
        for(linked_list2* itr = b[d]; itr != NULL; itr = itr->next){

			linked_list1* ear = NULL;
			int v = itr->a;
			int u = itr->b;
			ear = add1(ear, v);
			ear = add1(ear, u);
			earsize[earcnt] += 2;
			while (u != v && !used[u]) {
				used[u] = 1;
				u = p[u];
				ear = add1(ear, u);
				earsize[earcnt] += 1;
			}
			ans[earcnt++] = ear;
		}
	}
	printf("%d\n", earcnt);
	for(int i = 0; i < earcnt; ++i){
        printf("%d ", earsize[i] - 1);
        for(linked_list1* itr = ans[i]; itr != NULL && itr->next != NULL; itr = itr->next){
            printf("%d %d ", itr->x, itr->next->x);
        }
        printf("\n");
	}
}




