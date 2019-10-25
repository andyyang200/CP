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
string getstring(int len) {
    string s = "";
    FOR(i, 0, len){
        s += (char)('a' + rand() % 26);
	}
	return s;
}
int main(){
	freopen("test.out", "w", stdout);
	srand(123);
	ll n = 1;
	string t = "a";
    string s = "a";
	cout << n << endl;
	cout << s << endl;
	cout << t << endl;
}
