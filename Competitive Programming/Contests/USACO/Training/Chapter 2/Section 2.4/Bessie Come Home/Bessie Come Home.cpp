/*
ID: andyyang200
PROG: comehome
LANG: C++
*/

#include <iostream>
#include <fstream>

using namespace std;

#define INFINITY 1000000000
#define numPastures 52

struct Pasture
{
	char name;
	int distanceToSource;
	bool visited;
};

Pasture pastures[numPastures];
int dis[numPastures][numPastures];

int getIndex(char c)
{
	if (c <= 'Z')
		return c - 'A';
	return c - 'a' + 26;
}
char getName(int i)
{
	if (i + 'A' <= 'Z')
		return i + 'A';
	return i - 26 + 'a';
}

int main()
{
	ifstream fin("comehome.in");
	ofstream fout("comehome.out");

	for (int x = 0; x < numPastures; x++)
	{
		pastures[x].name = getName(x);
		pastures[x].distanceToSource = (pastures[x].name == 'Z' ? 0 : INFINITY);
	}

	int edges;
	fin >> edges;
	for (int x = 0; x < edges; x++)
	{
		char one, two;
		int d;
		fin >> one >> two >> d;
		if (d < dis[getIndex(one)][getIndex(two)] || (one != two && dis[getIndex(one)][getIndex(two)]) == 0)
		{
			dis[getIndex(one)][getIndex(two)] = dis[getIndex(two)][getIndex(one)] = d;
		}
		
	}

	int closestCowDistance = INFINITY;
	int closestCow = 0;
	for (int x = 0; x < numPastures; x++)
	{
		int minPastureDistance = INFINITY;
		int minPasture = -1;
		for (int i = 0; i < numPastures; i++)
		{
			if (!pastures[i].visited && pastures[i].distanceToSource < minPastureDistance)
			{
				minPastureDistance = pastures[i].distanceToSource;
				minPasture = i;
			}
		}
		if (minPasture == -1)
			break;
		pastures[minPasture].visited = 1;
		for (int i = 0; i < numPastures; i++)
		{
			if (dis[minPasture][i] > 0)
			{
				if (pastures[minPasture].distanceToSource + dis[minPasture][i] < pastures[i].distanceToSource)
					pastures[i].distanceToSource = pastures[minPasture].distanceToSource + dis[minPasture][i];
				if (getName(i) >= 'A' && getName(i) <= 'Y' && pastures[i].distanceToSource < closestCowDistance)
				{
					closestCowDistance = pastures[i].distanceToSource;
					closestCow = i;
				}
			}
		}
	}
	fout << getName(closestCow) << " " << closestCowDistance << endl;
}
