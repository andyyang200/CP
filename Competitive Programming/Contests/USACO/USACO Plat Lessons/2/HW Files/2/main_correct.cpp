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

const int maxn = 400010;
int bit[maxn],a[maxn],b[maxn];
struct C {
    int a,b,id,len;
} c[maxn];

int n;
int tot;
map<int,int> mm;
bool cmp(C& x, C& y){
    return x.a < y.a || (x.a==y.a && x.b<y.b);
}

bool cmp2(C& x, C& y){
    return x.id < y.id;
}
class SegmentTree
{
public:
	int* st;
	int length;
	SegmentTree(){

	}
	SegmentTree(int n)
	{
		length = n;
		int height = (int)(ceil(log2(n)));
		int maxSize = 2 * (1 << height) - 1;
		st = new int[maxSize];
		build(0, 0, length - 1);
	}
	int f(int a, int b) // change for different problems
	{
		return max(a, b);
	}
	void build(int node, int l, int r)
	{
		if (l == r)
			st[node] = 0;
		else
		{
			int mid = (l + r) / 2;
			build(node * 2 + 1, l, mid);
			build(node * 2 + 2, mid + 1, r);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	void update(int i, int v)
	{
		update(0, 0, length - 1, i, v); //if sum query last parameter should be v - a[i], otherwise should be v
		a[i] = v;
	}
	void update(int node, int sl, int sr, int i, int v)
	{
		if (i < sl || i > sr)
			return;
		if (sl == sr)
		{
			st[node] = v;
		}
		if (sl != sr)
		{
			int mid = (sl + sr) / 2;
			update(node * 2 + 1, sl, mid, i, v);
			update(node * 2 + 2, mid + 1, sr, i, v);
			st[node] = f(st[node * 2 + 1], st[node * 2 + 2]);
		}
	}

	int query(int ql, int qr)
	{
		return query(0, 0, length - 1, ql, qr);
	}
	int query(int node, int sl, int sr, int ql, int qr)
	{
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
SegmentTree st;
void dq(int l,int r) {
    if (l >= r) return;
    vector<int> vec;
    int mid=(l + r) / 2;
    dq(l, mid);
    sort(c + l, c + mid + 1, cmp);
    sort(c + mid + 1, c + r + 1,cmp);
    int i = l;
    FOR(j, mid + 1, r + 1){
        while (i <= mid && c[j].a > c[i].a) {
            int x = st.query(c[i].b, c[i].b);
            st.update(c[i].b, max(c[i].len, x));
            vec.push_back(c[i].b);
            i++;
        }
        c[j].len = max(c[j].len, st.query(0, c[j].b-1) + 1);
    }
    for (int i : vec) st.update(i, 0);
    sort(c + mid + 1,c + r + 1, cmp2);
    dq(mid + 1,r);
}
int main() {
    scanf("%d",&n);
    st = SegmentTree(3 * n);
    tot = 0;
    FOR(i, 0, n){
        scanf("%d",&a[i]), mm[a[i]];
    }
    FOR(i, 0, n){
        scanf("%d",&b[i]), mm[b[i]];
    }
    for (auto it=mm.begin(); it!=mm.end(); it++) {
        it->second = ++tot;
    }
    FOR(i, 0, n) {
        c[i] = {mm[a[i]],mm[b[i]],i,1};
    }
    dq(0,n-1);
    int ans = 0;
    FOR(i, 0, n){
        ans = max(ans,c[i].len);
    }
    cout << ans << endl;

}


