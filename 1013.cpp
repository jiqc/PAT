#include<cstdio>
#include<stdlib.h>
using namespace std;

//if using DFS, should use fixed storged map or use vector.resize
/*void Dfs(int **map, int *visited, const int v, int N) {
	visited[v] = 1;
	for (int i = 0; i < N; i++) {
		if (map[v][i] == 1 && visited[i] == 1) {
			Dfs(map, visited, i, N);
		}
	}
}

int getpart(int **map, int *visited, int N) {
	int count = 0;

	for (int i=0; i < N; i++) {
		if (visited[i] == 0) {
			Dfs(map, visited, i, N);
			count++;
		}
	}

	return count;
}*/

//here I try using union-find
int getpart(int **map, int *visited, int N, int d) {
	int count = N - d;
	int p, q;
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			if (visited[j] != -1 && visited[i] != -1) {
				if (map[i][j] == 1) {
					p = i;
					q = j;
					while (p != visited[p]) {
						p = visited[p];
					}
					while (q != visited[q]) {
						q = visited[q];
					}
					if (q != p) {
						visited[q] = p;
						count--;
					}					
				}
			}
		}
	}
	return count;
}

int main() {
	int N, M, K;
	int c1, c2, ck;
	//int part_origin;
	int	part;

	scanf_s("%d %d %d", &N, &M, &K);
	int ** map = (int**)malloc(sizeof(int*)*N);
	for (int i = 0; i < N; i++) {
		*(map + i) = (int*)malloc(sizeof(int)*N);
		for (int j = 0; j < N; j++) {
			map[i][j] = 0;
		}
	}
	int * visited = (int*)malloc(sizeof(int)*N);
	for (int i = 0; i < N; i++) {
		visited[i] = i;
	}

	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &c1, &c2);
		map[c1-1][c2-1] = map[c2-1][c1-1] = 1;
	}

	//part_origin = getpart(map, visited, N, 0);
	for (int i = 0; i < K; i++) {
		for (int i = 0; i < N; i++) {
			visited[i] = i;
		}
		scanf_s("%d", &ck);
		visited[ck - 1] = -1;
		part = getpart(map, visited, N, 1);
		printf("%d\n", part - 1);
	}

	system("pause");
	return 0;
}