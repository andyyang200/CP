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


int main() {
    int a;
    cin >> a >> a;
    string s, t;
    cin >> s >> t;
    int x = -1;
    FOR(i, 0, s.length()) {
        if (s[i] == '*') {
            x = i;
            break;
        }
    }
    if (x == -1) {
        if (s == t){
            cout << "YES" << endl;
            return 0;
        }
        cout << "NO" << endl;
        return 0;
    }
    FOR(i, 0, x) {
        if (s[i] != t[i]){
            cout << "NO" << endl;
            return 0;
        }
    }
    int j = t.length() - 1;
    RFOR(i, s.length() - 1, x) {
        if (s[i] != t[j]){
            cout << "NO" << endl;
            return 0;
        }
        j--;
    }
    if (t.length() >= s.length() - 1) {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
