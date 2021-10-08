#include<stdio.h>

int num = 6;
// expression: infinite
int INF = 10000000;

// Initialize all graph
int a[6][6] =
{
	
	{0, 2, 5, 1, INF, INF},
	{2, 0, 3, 2, INF, INF},
	{5, 3, 0, 2, 1, 5},
	{1, 2, 3, 0, 1, INF},
	{INF, INF, 1, 1, 0, 2},
	{INF, INF, 5, INF, 2, 0},
};

bool vis[6];	// visited node
int dis[6];   // shortest distance


int getSmallIndex()
{
	int min = INF;
	int index = 0;
	
	// Linear Search
	for (int i = 0; i < num; i++)
	{
		if (!vis[i] && dis[i] < min)
		{
			min = dis[i];
			// remember index location
			index = i;
		}
	}
	return index;
}

// Dijkstra Function
void dijkstra(int start)		// -> A function that calculates the minimum cost from a particular vertex to every other vertex
{
	for (int i = 0; i < num; i++)
	{
		// minimum cost = from the start point to the end
		dis[i] = a[start][i];
	}

	vis[start] = true;		// visiting
	
	////////////////////////////////////////////////////////////////////////////////////////
	
	for (int i = 0; i < num - 2; i++) // -> 필요 이유?
	{
		// Get an index of a node that has the minimum cost among nodes that are not currently visited
		int current = getSmallIndex();
		vis[current] = true;

		for (int j = 0; j < num; j++)
		{
			if (!vis[j] && dis[current] + a[current][j] < dis[j])
			{
				dis[j] = dis[current] + a[current][j];
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
	dijkstra(0);

	for (int i = 0; i < num; i++)
	{
		printf("%d ", dis[i]);
	}
}