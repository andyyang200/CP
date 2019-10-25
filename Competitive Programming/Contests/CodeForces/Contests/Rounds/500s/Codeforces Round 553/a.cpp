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
int dist(char a, char b){
    int x = a - 'A';
    int y = b - 'A';
    int ans = abs(x - y);
    ans = min(ans, -ans + 26);
    return ans;
}

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 1000000000;
    FOR(i, 0, s.length() - 3){
        int x = dist('A', s[i]) + dist('C', s[i + 1])+ dist('T', s[i + 2]) + dist('G', s[i + 3]);
        ans = min(ans, x);
    }
    cout << ans << endl;

}


