const int V=6;

//Алгоритм Дейкстры - находит расстояние вершины номер st
//графа GR размерностью V	до всех остальных
//Вернет массив расстояний, INT_MAX - прохода нет

int *Dijkstra(int **GR, int V, int st) {
 int *distance, count, index, i, u;
 bool *visited;
 distance = new int [V];
 visited = new bool [V];

//Запись дистанции и пометка о том, что не посещали
 for (i=0; i<V; i++) 
{ 
	distance[i] = INT_MAX;
	visited[i]=false;
}

 distance[st]=0;

//перебираем все
 for (count=0; count<V-1; count++)
{
  int min=INT_MAX;
//Поиск минимальной дистанции
  for (i=0; i<V; i++)
	if (!visited[i] && distance[i]<=min)
	{	
		min=distance[i]; index=i;
	}
  u=index;
  visited[u]=true;
  for (i=0; i<V; i++)
//Если вершина не посещена, существует для неё потомок, дистанция не равна максимум и сумма расстояния от нее до потомка меньше i расстояния 
  	if (!visited[i] && GR[u][i] && distance[u]!=INT_MAX && distance[u]+GR[u][i]<distance[i])
//Добавляем в массив расстояний
		   distance[i]=distance[u]+GR[u][i];
 }
 return distance;
}