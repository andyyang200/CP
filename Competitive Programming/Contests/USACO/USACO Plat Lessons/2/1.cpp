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

// support two queries: 1. add a value to a x coordinate between -10^9 and 10^9, and 2. find the sum of values in a given range
// Range tree
Node{
	int val;
	int lazy;
	Node *c[2];

	Node(){
		val = 0;
		c[0] = c[1] = null;
	}

	node *getc(int x){
		if (!c[x]){
			c[x] = new node;
		}
		return c[x];
	}
	void update(int i, int v, int sl, int sr){
		if (sl == sr){
			val = v;
			return 0;
		}
		int mid = (sl < ) ? (sl + sr - 1) / 2 : (sl + sr) / 2;
		if (i <= mid){
			getc(0)-> add(i, v, sl, mid);
		}
		if (i > mid){
			getc(0)-> add(i, v, mid + 1, sr);
		}
		val = max(c[0] ? c[0]-> val : 0, c[1] ? c[1] -> val : 0);
	}
}

int main(void)
{
	
}

