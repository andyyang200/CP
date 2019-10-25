#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 50000

bool front[MAX];
int back[MAX];
int main()
{
	ifstream fin("cowfind.in");
	ofstream fout("cowfind.out");

	string line;
	getline(fin, line);

	for (int x = 0; x < line.size() - 1; x++)
	{
		if (line[x] == '(' && line[x + 1] == '(')
		{
			front[x] = 1;
		}
	}

	int numBack = 0;
	for (int x = line.size() - 2; x >= 0; x--)
	{
		if (line[x] == ')' && line[x + 1] == ')')
		{
			numBack++;
		}
		back[x] = numBack;
	}
	int count = 0;
	for (int x = 0; x < line.size() - 1; x++)
	{
		if (front[x])
		{
			count += back[x];
		}
	}
	fout << count << endl;
}