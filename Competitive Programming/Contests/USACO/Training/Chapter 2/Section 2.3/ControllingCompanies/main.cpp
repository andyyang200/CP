/*
ID: andyyan1
PROG: concom
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

int controls[101][101];
int visited[101][101];

void addcontroller(int i, int j)
{
    if (visited[i][j] == 1)
    {
        return;
    }

    visited[i][j] = 1;

    for(int x = 0; x <= 100; x++)
    {
        controls[i][x] += controls[j][x];
    }

    for(int x = 0; x <= 100; x++)
    {
        if(controls[x][i] > 50)
        {
            addcontroller(x, j);
        }
    }
    for(int x = 0; x <= 100; x++)
    {
        if(controls[i][x] > 50)
        {
            addcontroller(i, x);
        }
    }
}

int main()
{
    ifstream fin ("concom.in");
    ofstream fout ("concom.out");

    for (int x = 0; x <= 100; x++)
    {
        controls[x][x] = 100;
        visited[x][x] = 1;
    }

    int sets, c1, c2, p;
    fin >> sets;
    for (int set = 0; set < sets; set++)
    {
        fin >> c1 >> c2 >> p;
        for(int x = 0; x <= 100; x++)
        {
            if(controls[x][c1] > 50)
            {
                controls[x][c2] += p;
                if(controls[x][c2] > 50)
                {
                    addcontroller(x, c2);
                }
            }
        }
    }
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            if (x != y && visited[x][y] == 1)
            {
                fout << x << " " << y << endl;
            }
        }
    }
}
