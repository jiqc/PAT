#include<cstdio>
#include<vector>
using namespace std;

#define INTMAX 0x7fffffff

int N, M;
int outset, dest;
vector<bool> visited;
vector<vector<int> > roads_length;
vector<vector<int> > roads_time;
vector<int> shortest;
vector<int> fastest;
vector<int> least;
vector<int> pre_short;
vector<int> pre_fast;
vector<int> path_short;
vector<int> path_fast;

void getpath_short(int d) {
	if (pre_short[d] != -1) {
		getpath_short(pre_short[d]);
	}
	path_short.push_back(d);
}

void Dijkstra_len() {
	for (int i = 0; i < N; i++) {
		shortest[i] = roads_length[outset][i];
	}
	for (int i = 0; i < N; i++) {
		fastest[i] = roads_time[outset][i];
	}
	visited[outset] = true;

	int v, min;
	for (int i = 1; i < N; i++) {
		min = INTMAX;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && shortest[j] < min) {
				v = j;
				min = shortest[j];
			}
		}
		if (v == dest) {
			break;
		}
		visited[v] = true;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && roads_length[v][j]<INTMAX) {
				if (shortest[j] > min + roads_length[v][j]) {
					shortest[j] = min + roads_length[v][j];
					fastest[j] = fastest[v] + roads_time[v][j];
					pre_short[j] = v;
				}
				else {
					if (shortest[j] == min + roads_length[v][j]) {
						if (fastest[j] > fastest[v] + roads_time[v][j]) {
							fastest[j] = fastest[v] + roads_time[v][j];
							pre_short[j] = v;
						}
					}
				}
			}
		}
	}

	getpath_short(dest);
}

void getpath_fast(int d) {
	if (pre_fast[d] != -1) {
		getpath_fast(pre_fast[d]);
	}
	path_fast.push_back(d);
}

void Dijkstra_t() {
	for (int i = 0; i < N; i++) {
		fastest[i] = roads_time[outset][i];
	}
	//least[outset] = 1;
	visited.clear();
	visited.resize(N);
	visited[outset] = true;

	int v, min;
	for (int i = 1; i < N; i++) {
		min = INTMAX;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && fastest[j] < min) {
				v = j;
				min = fastest[j];
			}
		}
		if (v == dest) {
			break;
		}
		visited[v] = true;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && roads_time[v][j]<INTMAX) {
				if (fastest[j] > min + roads_time[v][j]) {
					fastest[j] = min + roads_time[v][j];
					least[j] = least[v] + 1;
					pre_fast[j] = v;
				}
				else {
					if (fastest[j] == min + roads_time[v][j]) {
						if (least[j] > least[v] + 1) {
							least[j] = least[v] + 1;
							pre_fast[j] = v;
						}
					}
				}
			}
		}
	}

	getpath_fast(dest);
}

void printpaths() {
	int d, t;
	int index = 0;
	bool same = false;

	d = (int)path_short.size();
	t = (int)path_fast.size();
	if (d == t) {
		for (; index < d; index++) {
			if (path_short[index] != path_fast[index]) {
				break;
			}
		}
		if (index == d) {
			same = true;
		}
	}

	if (same) {
		printf("Distance = %d; Time = %d: ", shortest[dest], fastest[dest]);
		printf("%d",outset);
		for (int i = 0; i < d; i++) {
			printf(" -> %d", path_short[i]);
		}
		printf("\n");
	}
	else {
		printf("Distance = %d: ", shortest[dest]);
		printf("%d", outset);
		for (int i = 0; i < d; i++) {
			printf(" -> %d", path_short[i]);
		}
		printf("\n");
		printf("Time = %d: ",fastest[dest]);
		printf("%d", outset);
		for (int i = 0; i < t; i++) {
			printf(" -> %d", path_fast[i]);
		}
		printf("\n");
	}
}

int main() {

	scanf_s("%d %d", &N, &M);
	visited.resize(N);
	roads_length.resize(N);
	for (int i = 0; i < N; i++) {
		roads_length[i].resize(N, INTMAX);
		roads_length[i][i] = 0;
    }
	roads_time.resize(N);
	for (int i = 0; i < N; i++) {
		roads_time[i].resize(N, INTMAX);
		roads_time[i][i] = 0;
	}
	shortest.resize(N);
	fastest.resize(N);
	least.resize(N);
	pre_short.resize(N,-1);
	pre_fast.resize(N,-1);

	int a, b, oneway, len, t;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d %d %d %d", &a, &b, &oneway, &len, &t);
		
		roads_length[a][b] = len;
		roads_time[a][b] = t;
		if (oneway==0) {
			roads_length[b][a] = len;
			roads_time[b][a] = t;
		}
	}

	scanf_s("%d %d", &outset, &dest);

	Dijkstra_len();

	Dijkstra_t();

	printpaths();

	system("pause");
	return 0;
}