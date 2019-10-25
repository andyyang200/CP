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
int z[1000001];
int main(){
	
	string s;
	int n = s.length();
	int L = 0;
	int R = 0;
	for(int i = 1; i < n; i++){
		if (i > R){
			L = R = i;
			while(R < n && s[R - L] == S[r]){
				R++;
			}
			z[i] = R - L;
			R--;
		}
		else{ // R >= i
			int k = i - L;
			if (z[k] < R - i + 1) {
				z[i] = z[k];
			}
			else{
				while(R < n && s[R - L] == S[r]){
					R++;
				}
				z[i] = R - L;
				R--;
				L = i;
			}
		}
	}
}