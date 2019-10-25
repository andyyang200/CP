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
map<char, int> m;
int main(void)
{
    string s;
    cin >> s;
    FOR(i, 0, s.length()){
        m[s[i]]++;
    }
    vector<int> v;
    FOREACH(itr, m){
        v.push_back(itr->second);
    }
    sort(v.begin(), v.end());
    if (v.size() == 4){
        cout << "Yes" << endl;
        return 0;
    }
    else if (v.size() == 3 && v[2] >= 2){
        cout << "Yes" << endl;
        return 0;
    }
    else if (v.size() == 2 && v[0] != 1){
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
}


