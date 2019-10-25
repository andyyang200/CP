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

int main(void)
{
    int n;
    cin >> n;
    set<string> ans;
    FOR(i, 0, n){
        string s;
        cin >> s;
        set<char> c;
        FOR(j, 0, s.length()){
            c.insert(s[j]);
        }
        string t = "";
        for(char x : c){
            t += x;
        }
        ans.insert(t);
    }
    cout << ans.size() << endl;
}

