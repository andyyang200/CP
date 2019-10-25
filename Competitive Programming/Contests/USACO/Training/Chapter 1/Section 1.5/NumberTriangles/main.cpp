/*
ID: andyyan1
PROG: numtri
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    return b;
}
int main()
{
    ofstream fout ("numtri.out");
    ifstream fin ("numtri.in");
    int rows;
    fin >> rows;
    int triangle[rows][rows];
    for (int r = 0; r < rows; r++)
    {
        for (int c = 0; c <= r; c++)
        {
            fin >> triangle[r][c];
        }
    }
    for (int r = rows - 2; r >= 0; r--)
    {
        for (int c = 0; c <= r; c++)
        {
            triangle[r][c] += max(triangle[r + 1][c], triangle[r + 1][c + 1]);
        }
    }
    fout << triangle[0][0] << endl;
    return 0;
}

