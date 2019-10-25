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
struct Node{
    Node* n[26];
    int cnt = 0;
    bool b = false;
    void add(string& s, int i){
        if (i == s.length()){
            b = true;
            return;
        }
        else{
            if (n[s[i] - 'A'] == NULL){
                n[s[i] - 'A'] = new Node();
                cnt++;
            }
            n[s[i] - 'A']->add(s, i + 1);
        }
    }
    pii match(){
        int matched = 0;
        int unmatched = 0;
        if (b){
            unmatched++;
        }
        FOR(i, 0, 26){
            if (n[i] != NULL){
                pii p = n[i]->match();
                matched += p.first;
                unmatched += p.second;
            }
        }
        if (unmatched >= 2){
            unmatched -= 2;
            matched += 2;
        }
        return {matched, unmatched};
    }
};
Node root;
int main(){
    int tests;
    scanf("%d", &tests);
    FOR(test, 0, tests){
        int n;
        scanf("%d", &n);
        root = Node();
        FOR(i, 0, n){
            string s;
            cin >> s;
            reverse(s.begin(), s.end());
            root.add(s, 0);
        }
        int ans = 0;
        FOR(i, 0, 26){
            if (root.n[i] != NULL){
                ans += root.n[i]->match().first;
            }
        }
        printf("Case #%d: %d\n", test + 1, ans);
    }

}


