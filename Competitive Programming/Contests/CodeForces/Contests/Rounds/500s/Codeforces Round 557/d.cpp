#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;


int n, m;
set<pii> s;

bool f(int d){
    for(pii p : s){
        int a = p.first;
        int b = p.second;
        a = (a - d + n) % n;
        b = (b - d + n) % n;
        auto itr = s.find({a, b});
        auto itr2 = s.find({b, a});
        if (itr == s.end() && itr2 == s.end()){
            return false;
        }
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        s.insert({a, b});
    }

    for(int d = 1; d * d <= n; d++){
        if (n % d == 0){
            if (f(d)){
                cout << "Yes" << endl;
                return 0;
            }
            if (n / d != n && f(n / d)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}

