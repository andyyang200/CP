#include <bits/stdc++.h>
using namespace std;
#define FOR(index, start, end) for(int index = start; index < end; ++index)
#define RFOR(index, start, end) for(int index = start; index > end; --index)
#define FOREACH(itr, b) for(auto itr = b.begin(); itr != b.end(); ++itr)
#define RFOREACH(itr, b)  qfor(auto itr = b.rbegin(); itr != b.rend(); ++itr)
#define db(x) cerr << #x << " = " << x << endl
#define db2(x, y) cerr << #x << " = " << x << ", " << #y << " = " << y << endl
#define db3(x, y, z) cerr << #x << " = " << x << ", " << #y << " = " << y << ", " << #z << " = " << z << endl
#define INF 1000000000
#define M 1000000007
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;


//---------------------------------------------------------------------------------------------------------------


int n;
string s;
int na = 0;
int nb = 0;
int nc = 0;
int work(){
    int a = 0;
    int b = na;
    int c = na + nb;
    int x = 0;
    FOR(i, 0, b){
        if (s[i] != 'A'){
            x++;
        }
    }
    FOR(i, b, c){
        if (s[i] != 'B'){
            x++;
        }
    }
    FOR(i, c, n){
        if (s[i] != 'C'){
            x++;
        }
    }
    int ans = x;
    FOR(i, 0, n + 1){
        int a2 = (a + 1) % n;
        int b2 = (b + 1) % n;
        int c2 = (c + 1) % n;
        if (s[a] == 'A'){
            x++;
        }
        if (s[a] == 'C'){
            x--;
        }
        if (s[b] == 'B'){
            x++;
        }
        if (s[b] == 'A'){
            x--;
        }
        if (s[c] == 'C'){
            x++;
        }
        if (s[c] == 'B'){
            x--;
        }
        a = a2;
        b = b2;
        c = c2;
        ans = min(ans, x);
    }
    return ans;
}

int main(){
    cin >> n >> s;
    FOR(i, 0, n){
        if (s[i] == 'A')na++;
        if (s[i] == 'B')nb++;
        if (s[i] == 'C')nc++;
    }
    int ans = work();
    reverse(s.begin(), s.end());
    ans = min(ans, work());
    cout << ans << endl;

}
/*
5
ABABC

12
ABCABCABCABC

4
ACBA


*/

