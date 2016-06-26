#include<cstdio>
#include<stdlib.h>
using namespace std;

int main() {
	int num_city, num_road, outset, destination;

	//inicialization
	scanf_s("%d %d %d %d", &num_city, &num_road, &outset, &destination);
	int **roads = new int *[num_city];
	//int **roads = (int**)malloc(sizeof(int*)*num_city);
	for (int i = 0; i < num_city; i++) {
		roads[i] = new int[num_city];
		//*(roads + i) = (int*)malloc(sizeof(int)*num_city);
		for (int j = 0; j < num_city; j++) {
			roads[i][j] = INT_MAX;
		}													
		roads[i][i] = 0;														
	}
	int *teams = new int[num_city];
	//int *teams = (int*)malloc(sizeof(int)*num_city);
	for (int i = 0; i < num_city; i++) {
		scanf_s("%d", &teams[i]);
	}
	for (int i = 0; i < num_road; i++) {
		int a, b, length;
		scanf_s("%d %d %d", &a, &b, &length);
		roads[a][b] = length;
		roads[b][a] = length;
	}
	int *equalways = new int[num_city];  //the number of equal ways
	int *max = new int[num_city];        //the maximum number of rescure teams 
	int *shortestpath = new int[num_city];//the shortest distances between outset to other cities
	bool *visited = new bool[num_city];
	for (int i = 0; i < num_city; i++) {
		visited[i] = false;
	}
	for (int i = 0; i < num_city; i++) {
		if (i == outset) {
			continue;
		}
		shortestpath[i] = roads[outset][i];
		if (shortestpath[i] == INT_MAX) {
			equalways[i] = 0;
			max[i] = teams[i];
		}
		else {
			equalways[i] = 1;
			max[i] = teams[outset] + teams[i];
		}
	}
	shortestpath[outset] = 0;
	equalways[outset] = 1;
	visited[outset] = true;
	max[outset] = teams[outset];

	//Dijkstra
	int min,v;
	for (int i = 1; i < num_city; i++) {
		min = INT_MAX;
		for (int j = 0; j < num_city; j++) {
			if (!visited[j] && shortestpath[j] < min) {
				min = shortestpath[j];
				v = j;
			}
		}
		if (destination == v) {
			break;
		}
		visited[v] = true;
		for (int j = 0; j < num_city; j++) {
			if (!visited[j] && roads[v][j] < INT_MAX) {
				if (min + roads[v][j] < shortestpath[j]) {
					shortestpath[j] = min + roads[v][j];
					equalways[j] = equalways[v];
					max[j] = max[v] + teams[j];
				}
				else {
					if(min + roads[v][j] == shortestpath[j]){
						equalways[j] = equalways[v]+ equalways[j];
						if (max[v] + teams[j]>max[j]) {
							max[j] = max[v] + teams[j];
						}
					}
				}				
			}
		}
	}

	printf("%d %d\n", equalways[destination], max[destination]);
	
	delete[] visited;
	delete[] shortestpath;
	delete[] max;
	delete[] equalways;
	delete[] teams;
	//free(teams);
	for (int i = 0; i < num_city; i++) {
		delete[] roads[i];
	}
	delete[] roads;
	//for (int i = 0; i < num_city; i++) {
	//	free(*(roads + i));
	//}
	//free(roads);

	system("pause");
	return 0;
}