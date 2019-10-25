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
    string s;
    cin >> s;
    FOR(i, 0, s.length()){
        if (s[i] < 'a' || s[i] > 'c'){
            cout << "NO" << endl;
            return 0;
        }
    }
    int cnt = 0;
    FOR(i, 0, s.length() - 1){
        if (s[i] != s[i + 1]){
            cnt++;
            if (s[i] == 'a' && s[i + 1] == 'b') continue;
            else if (s[i] == 'b' && s[i + 1] == 'c') continue;
            else{
                cout << "NO" << endl;
                return 0;
            }
        }
    }
    if (cnt != 2 || s[0] != 'a' || s[s.length() - 1] != 'c'){
        cout << "NO" << endl;
        return 0;
    }
    map<char, int> m;
    FOR(i, 0, s.length())m[s[i]]++;
    if (m['c'] != m['a'] && m['c'] != m['b']){
        cout << "NO" << endl;
            return 0;
    }
    cout << "YES" << endl;
}

