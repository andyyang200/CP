#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[1]);
    int maxv = atoi(argv[2]);
    cout << n << endl;
    for(int i = 0; i < n; i++){
        printf("%d", rnd.next(1, maxv));
        if (i < n - 1){
            printf(" ");
        }
    }
    cout << endl;
    for(int i = 0; i < n; i++){
        printf("%d", rnd.next(1, maxv));
        if (i < n - 1){
            printf(" ");
        }
    }
    cout << endl;
}
