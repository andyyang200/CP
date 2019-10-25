#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
#define INF 1000000009


class SegmentTree{
public:
	int* st;
	int* a;
	int length;
	SegmentTree(){
	}
	SegmentTree(int arr[], int n){
		length = n;
		a = arr;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b){// change for different problems
		return min(a, b);
	}
	void build(int node, int l, int r){
		if (l == r)
			st[node] = a[l];
		else{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	int query(int ql, int qr){
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int ql, int qr){
		if (sl > qr || sr < ql)
			return -1;
		if (sl >= ql && sr <= qr)
			return st[node];
		int mid = (sl + sr) / 2;
		int a = query(node * 2 + 1, sl, mid, ql, qr);
		int b = query(node * 2 + 2, mid + 1, sr, ql, qr);
		if (a == -1)
			return b;
		if (b == -1)
			return a;
		return f(a, b);
	}
};

SegmentTree st[3 * 3001];
int n, m, a, b;
int g0, x, y, z;
int grid[3001][3001];

void build(int i, int x1, int x2){
    int* B = (int*)malloc(sizeof(int) * m);
    fill(B, B + m, INF);
    for(int y = 0; y < m; y++){
        for(int x = x1; x <= x2; x++){
            B[y] = min(B[y], grid[x][y]);
        }
    }
    st[i] = SegmentTree(B, m);
    if (x1 == x2){
        return;
    }
    int mid = (x1 + x2) / 2;
    build(2 * i + 1, x1, mid);
    build(2 * i + 2, mid + 1, x2);
}

int query(int i, int x1, int x2, int qx1, int qx2, int qy1, int qy2){
    if (x2 < qx1 || x1 > qx2){
        return INF;
    }
    if (x1 >= qx1 && x2 <= qx2){
        return st[i].query(qy1, qy2);
    }
    int mid = (x1 + x2) / 2;
    int a = query(2 * i + 1, x1, mid, qx1, qx2, qy1, qy2);
    int b = query(2 * i + 2, mid + 1, x2, qx1, qx2, qy1, qy2);
    return min(a, b);
}


int main(){
    scanf("%d%d%d%d%d%d%d%d", &n, &m, &a, &b, &g0, &x, &y, &z);
    grid[0][0] = g0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if (i == 0 && j == 0){
                continue;
            }
            g0 = (int)((ll)(g0 * x % z + y) % z);
            grid[i][j] = g0;
        }
    }
    build(0, 0, n - 1);
    ll ans = 0;
    for(int i = 0; i < n - a + 1; i++){
        for(int j = 0; j < m - b + 1; j++){
            ans += query(0, 0, n - 1, i, i + a - 1, j, j + b - 1);
        }
    }
    cout << ans << endl;
}
