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

int main(){
    int a, b, x;
	cin >> a >> b >> x;
	string ans = "";
	int c = (a > b ? 0 : 1);
	if (c == 0) a--; else b--;
	ans += to_string(c);
	c = (c + 1) % 2;
	FOR(i, 0, x){
        ans += to_string(c);
        if (c == 0) a--;
        else b--;
        c = (c + 1) % 2;
	}
	FOR(i, 0, ans.size()){
        if (ans[i] == '0'){
            string t = "";
            FOR(asd, 0, a){
                t += "0";
            }
            ans.insert(i, t);
            break;
        }
	}
	FOR(i, 0, ans.size()){
        if (ans[i] == '1'){
            string t = "";
            FOR(asd, 0, b){
                t += "1";
            }
            ans.insert(i, t);
            break;
        }
	}
	cout << ans << endl;
}
