/*
ID: andyyang200
PROG: ttwo
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

char map[10][10];
bool visited[10][10][4][10][10][4]; // r1, c1, d1, r2, c2, d2
int farmerRow = 0, farmerCol = 0, farmerDirection = 0;
int cowRow = 0, cowCol = 0, cowDirection = 0;
// n = 0, e = 1, s = 2, w = 3;

void farmerMove()
{
	int newRow = farmerRow;
	int newCol = farmerCol;
	switch (farmerDirection)
	{
		case 0:
		{
			newRow--;
			if (newRow < 0)
			{
				farmerDirection = (farmerDirection + 1) % 4;
				return;
			}
			break;
		}
		case 1:
		{
			newCol++;
			if (newCol > 9)
			{
				farmerDirection = (farmerDirection + 1) % 4;
				return;
			}
			break;
		}
		case 2:
		{
			newRow++;
			if (newRow > 9)
			{
				farmerDirection = (farmerDirection + 1) % 4;
				return;
			}
			break;
		}
		case 3:
		{
			newCol--;
			if (newCol < 0)
			{
				farmerDirection = (farmerDirection + 1) % 4;
				return;
			}
			break;
		}
	}
	if (map[newRow][newCol] == '*')
	{
		farmerDirection = (farmerDirection + 1) % 4;
		return;
	}
	farmerRow = newRow;
	farmerCol = newCol;
}
void cowMove()
{
	int newRow = cowRow;
	int newCol = cowCol;
	switch (cowDirection)
	{
		case 0:
		{
			newRow--;
			if (newRow < 0)
			{
				cowDirection = (cowDirection + 1) % 4;
				return;
			}
			break;
		}
		case 1:
		{
			newCol++;
			if (newCol > 9)
			{
				cowDirection = (cowDirection + 1) % 4;
				return;
			}
			break;
		}
		case 2:
		{
			newRow++;
			if (newRow > 9)
			{
				cowDirection = (cowDirection + 1) % 4;
				return;
			}
			break;
		}
		case 3:
		{
			newCol--;
			if (newCol < 0)
			{
				cowDirection = (cowDirection + 1) % 4;
				return;
			}
			break;
		}
	}
	if (map[newRow][newCol] == '*')
	{
		cowDirection = (cowDirection + 1) % 4;
		return;
	}
	cowRow = newRow;
	cowCol = newCol;
}

int main()
{
	ifstream fin("ttwo.in");
	ofstream fout("ttwo.out");

	for (int r = 0; r < 10; r++) for (int c = 0; c < 10; c++)
	{
		fin >> map[r][c];
		if (map[r][c] == 'F')
		{
			farmerRow = r;
			farmerCol = c;
		}
		if (map[r][c] == 'C')
		{
			cowRow = r;
			cowCol = c;
		}
	}
	int minutes = 0;
	while (true)
	{
		visited[farmerRow][farmerCol][farmerDirection][cowRow][cowCol][cowDirection] = 1;
		farmerMove();
		cowMove();
		minutes++;
		if (visited[farmerRow][farmerCol][farmerDirection][cowRow][cowCol][cowDirection] == 1)
		{
			fout << 0 << endl;
			return 0;
		}
		if (farmerRow == cowRow && farmerCol == cowCol)
		{
			fout << minutes << endl;
			return  0;
		}
	}

}

