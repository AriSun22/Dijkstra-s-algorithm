/*!
\file Dijkstra's algorithm.cpp
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных 
классов, используемых в демонстрационной программе
*/
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <time.h>
#include <iostream>

using namespace std;

const int MaxV=15;

/**   
		Aлгоритм Дейкстры
	*/
void Dijkstra(int GR[MaxV][MaxV], int V)
	{
		int st = 0;
		int distance[MaxV], count, index, i, u, m=st+1;
		bool visited[MaxV];
		for (i=0; i<V; i++)
			{
				distance[i]=INT_MAX; visited[i]=false;
			}
				distance[st]=0;
				for (count=0; count<V-1; count++)
					{
						int min=INT_MAX;
						for (i=0; i<V; i++)
						if (!visited[i] && distance[i]<=min)
							{
								min=distance[i]; index=i;
							}
		u=index;
		visited[u]=true;
		for (i=0; i<V; i++)
		if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX &&
		distance[u]+GR[u][i]<distance[i])
		distance[i]=distance[u]+GR[u][i];
					}
	for (i=1; i<V; i++) 
		if (distance[i]!=INT_MAX)
			cout<<distance[i]<<" ";
			else cout<<-1<<" ";
		cout<<"\n";
	}

//главная функция
void main()
{

	int V,data, GR[MaxV][MaxV];
	cin>>V;
	for (int i=0; i<V; i++){
		for(int j=0; j<V; j++){
			cin>>GR[i][j];
		}
	}

	Dijkstra(GR,V);
	system("pause>>void");
}
