#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

//алгоритм Флойда нахождения кратчайших путей между всеми вершинами
int** floyd(int **graph, int n)
{
	int** d = new int*[n];
	for (int i = 0; i < n; i++)
	{
		d[i] = new int[n]; 
		for (int j = 0; j < n; j++)
		{
			d[i][j] = graph[i][j];
		}
	}

	//алгоритм: путь между вершинами j и k либо проходит через i, и тогда путь из j в k = сумме пути из j в i и пути из i в k
	//либо не проходит, тогда ничего делать не надо
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (d[j][k] == -1) 
				{
					if (d[j][i] != -1 && d[i][k] != -1)
						d[j][k] = d[j][i] + d[i][k];
				}
				else if (d[j][i] != -1 && d[i][k] != -1) 
					d[j][k] = min(d[j][k], d[j][i] + d[i][k]);
			}
		}
	}

	return d;
}

int main()
{
	int n;
	int **graph;

	cin >> n;
	
	graph = new int*[n];
	for (int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
	}
	//считывание матрицы смежности
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> graph[i][j];
		}
		cout << endl;
	}


	int** ans = floyd(graph, n); // получили матрицу кратчайших путей

	
	int maxd = ans[0][0], maxi = 0, maxj = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ans[i][j] > maxd) 
			{
				maxd = ans[i][j];
				maxi = i;
				maxj = j;
			}
		}
	}
	
	cout << "Maximum distance is between vertices " << maxi << " and " << maxj << endl;
	cout << "Graph diameter is " << maxd << endl;
	system("pause"); 
	return 0;
}
