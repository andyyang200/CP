#include <bits/stdc++.h>
#include "testlib.h"

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

bool visited[2000000];
int m, n;
string get(int x){
    string s = "";
    FOR(i, 0, m){
        if (x & (1 << i)){
            s = '1' + s;
        }
        else{
            s = '0' + s;
        }
    }
    return s;
}
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    m = atoi(argv[1]);
    n = atoi(argv[2]);
    printf("%d %d\n", m, n);
    vector<int> v;
    FOR(i, 0, 1 << m){
        v.push_back(i);
    }
    shuffle(v.begin(), v.end());
    FOR(i, 0, n){
        cout << get(v[i]) << endl;
    }
}
