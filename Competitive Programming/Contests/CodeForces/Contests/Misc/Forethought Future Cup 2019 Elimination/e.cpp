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


class LazySegmentTree
{
public:
	int* st;
	int* arr;
	int* lazy;
	int length;
	LazySegmentTree(int a[], int n){
		length = n;
		arr = a;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		lazy = new int[maxSize];
		build(0, 0, length - 1);
	}
	void build(int node, int sl, int sr){
		lazy[node] = 0;
		if (sl == sr){
			st[node] = arr[sl];
			return;
		}
		int mid = (sl + sr) / 2;
		build(node * 2 + 1, sl, mid);
		build(node * 2 + 2, mid + 1, sr);
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}
	void update(int node, int sl, int sr, int ql, int qr, int v){
		if (lazy[node] != 0){
			st[node] += lazy[node] * (sr - sl + 1);
			if (sl != sr){
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (sl > sr || sl > qr || sr < ql){
			return;
		}
		if (sl >= ql && sr <= qr){
			st[node] += v * (sr - sl + 1);
			if (sl != sr){
				lazy[node * 2 + 1] += v;
				lazy[node * 2 + 2] += v;
			}
			return;
		}
		int mid = (sl + sr) / 2;
		update(node * 2 + 1, sl, mid, ql, qr, v);
		update(node * 2 + 2, mid + 1, sr, ql, qr, v);
		st[node] = st[node * 2 + 1] + st[node * 2 + 2];
	}
	int query(int node, int sl, int sr, int ql, int qr){
		if (sl > qr || sr < ql){
			return 0;
		}
		if (lazy[node] != 0){
			st[node] += lazy[node] * (sr - sl + 1);
			if (sl != sr){
				lazy[node * 2 + 1] += lazy[node];
				lazy[node * 2 + 2] += lazy[node];
			}
			lazy[node] = 0;
		}
		if (sl >= ql && sr <= qr){
			return st[node];
		}
		int mid = (sl + sr) / 2;
		int q1 = query(node * 2 + 1, sl, mid, ql, qr);
		int q2 = query(node * 2 + 2, mid + 1, sr, ql, qr);
		int res = q1 + q2;
		return res;
	}
};

#define offset 100005
#define MAX 300005

int n, q;
int a[100005];
int cnt[MAX];
int main(){
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
        a[i] += offset;
    }
    LazySegmentTree st(cnt, MAX);
    for(int i = 0; i < q; i++){
        char c;
        int x;
        cin >> c;
        scanf("%d", &x);
        x += offset;
        if (c == '<'){
            st.update(0, 0, MAX - 1, 0, x - 1, 1);
        }
        else{
            st.update(0, 0, MAX - 1, x + 1, MAX - 1, 1);
        }
    }
    for(int i = 0; i < n; i++){
        int flip = st.query(0, 0, MAX - 1, a[i], a[i]);
        a[i] -= offset;
        if (flip % 2 != 0){
            a[i] *= -1;
        }
        printf("%d ", a[i]);
    }
    printf("\n");
}

