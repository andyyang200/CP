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

bool subsequence(string a, string b){
    int i = 0;
    FOR(j, 0, b.length()){
        if (i < a.length() && b[j] == a[i]){
            i++;
        }
    }
    return i == a.length();
}

string words[100005];
int n;
int main(){
    cin >> n;
    string all = "";
    FOR(i, 0, n){
        cin >> words[i];
        all += "<3";
        all += words[i];
    }
    all += "<3";
    string code;
    cin >> code;
    if (subsequence(all, code)){
        cout << "yes" << endl;
    }
    else{
        cout << "no" << endl;
    }

}

