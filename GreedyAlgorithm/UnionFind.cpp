#include <stdio.h>

// Finding parents node
int getParent(int parent[], int x)
{
	if (parent[x] == x)	return x;

	return parent[x] = getParent(parent, parent[x]);
}


void unionParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	// add minimum value
	if (a < b) parent[b] = a;
	else parent[a] = b;
}


int findParent(int parent[], int a, int b)
{
	a = getParent(parent, a);
	b = getParent(parent, b);
	if (a == b)
	{
		return 1;
	}

	return 0;
}

int main(void)
{
	// put in 10 elements
	int parent[11];
	for (int i = 0; i < 11; i++)
	{
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 3, 4);
	unionParent(parent, 5, 6);
	unionParent(parent, 6, 7);
	unionParent(parent, 7, 8);
	/*
	[1]-[2]-[3]-[4], [5]-[6]-[7]-[8]
	*/
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
	unionParent(parent, 2, 8);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
}