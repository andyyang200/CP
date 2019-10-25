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
int a[100005];
int c[100005];
int tempa[100005];
void counting() {

	for(int i = 0; i < n; i++) c[a[i]]++;
	int sum = 0;
	for(int i = 0; i < 100000; i++){
		int t = c[i];
		c[i] = sum;
		sum += t;
	}
	for(int i = 0; i < n; i++){
		tempa[c[a[i]]] = a[i];
		c[a[i]]++;
	}
	for(int i = 0; i < n; i++){
		a[i] = tempa[i];
	}
}


int c[100005];
int main(){
	for(int i = 0; i < n; i++) c[a[i]]++;
	for(int i = 0; i < 100000; i++){
		for(int j = 0; j < c[i]; j++) cout << i << " ";
	}
	

}