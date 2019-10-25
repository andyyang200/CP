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

string s;
int R[200005]; // R[i] = index of suffix starting at i in suffix array
int tempR[10005];
int SA[100005];

int l;


int lcp[100005];
void getLCP() {
	int x = 0;
	for(int i = 0; i < n; i++){ // in original order
		int j = SA[R[i] + 1];
		while(i + x < n && j + x < n && s[i + x] == s[j + x]){
			x++;
		}
		lcp[R[i]] = k;
		if (k > 0) k--;
	}
}



bool cmp(int i, int j) {
	if (R[i] != R[j]){
		return R[i] < R[j];
	}
	R[i + l] < R[j + l];
}

int main(){

	for(int i = 0; i < n; i++) SA[i] = i;
	for(int i = 0; i < n; i++) R[i] = s[i];
	for(l = 2; l < n; l *= 2){
		sort(SA, SA + n, cmp);
		tempR[SA[0]] = 1;
		int r = 2;
		for(int i = 1; i < n; i++){
			tempR[SA[i]] = (R[SA[i]] == R[SA[i - 1]] && RA[SA[i] + l] == RA[SA[i - 1] + l]) ? r; ++r
		}
		for(int i = 0; i < n; i++){
			R[i] = tempR[i];
		}
	}


}

