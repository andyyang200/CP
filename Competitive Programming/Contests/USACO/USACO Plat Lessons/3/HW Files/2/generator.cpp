#include "testlib.h"
#include <iostream>

using namespace std;
int a[100005];
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int n = atoi(argv[2]);
    string type = argv[1];

    if (type == "line"){
        cout << n << endl;
        for(int i = 1; i <= n; i++){
            a[i] = i;
        }
        shuffle(a + 1, a + n + 1);
        for(int i = 1; i < n; i++){
            printf("%d %d\n", a[i], a[i + 1]);
        }
        return 0;
    }


    if (type == "cactus"){
        cout << n << endl;
        for(int i = 1; i <= n; i++){
            a[i] = i;
        }
        shuffle(a + 1, a + n + 1);
        for(int i = 2; i <= n; i++){
            printf("%d %d\n", a[1], a[i]);
        }
        return 0;
    }


    cout << n << endl;
    for(int i = 1; i <= n; i++){
        a[i] = i;
    }
    shuffle(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++){
        int j = rnd.next(1, i - 1);
        printf("%d %d\n", a[i], a[j]);
    }
    return 0;

}
