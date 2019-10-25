#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int q = atoi(argv[1]);
    int INF = atoi(argv[2]);
    cout << q << endl;
    for(int i = 0; i < q; i++){
        int t = rnd.next(1, 2);
        if (t == 1){
            printf("%d %d %d %d\n", t, rnd.next(-INF, INF), rnd.next(-INF, INF), rnd.next(-INF, INF));
        }
        else{
            int x1 = rnd.next(-INF, INF);
            int x2 = rnd.next(x1, INF);
            int y1 = rnd.next(-INF, INF);
            int y2 = rnd.next(y1, INF);
            printf("%d %d %d %d %d\n", t, x1, x2, y1, y2);
        }
    }
}
