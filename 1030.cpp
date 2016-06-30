#include<iostream>
#include<vector>
using namespace std;

#define INTMAX 0x7fffffff

int N, M, S, D;
vector<vector<int> > roads;
vector<bool> visited;
vector<int> previsit;
vector<vector<int> > prices;
vector<int> shortest;
vector<int> cost;

void printpath(int c) {
	if (c == S) {
		cout << S << ' ';
	}
	else {
		printpath(previsit[c]);
		cout << c << ' ';
	}
}

int main() {	

	cin >> N >> M >> S >> D;
	roads.resize(N);
	for (int i = 0; i < N; i++) {
		roads[i].resize(N);
		for (int j = 0; j < N; j++) {
			roads[i][j] = INTMAX;
		}
		roads[i][i] = 0;
	}
	visited.resize(N);
	previsit.resize(N, S);
	prices.resize(N);
	for (int i = 0; i < N; i++) {
		prices[i].resize(N);
	}
	shortest.resize(N, INTMAX);
	cost.resize(N,INTMAX);

	int c1, c2, r, p;
	for (int i = 0; i < M; i++) {
		cin >> c1 >> c2 >> r >> p;
		roads[c1][c2] = roads[c2][c1] = r;
		prices[c1][c2] = prices[c2][c1] = p;
	}
	for (int i = 0; i < N; i++) {
		shortest[i] = roads[S][i];
		cost[i] = prices[S][i];
	}

	visited[S] = true;
	shortest[S] = 0;
	cost[S] = 0;
	previsit[S] = S;

	int v, min;
	for (int i = 1; i < N; i++) {
		min = INTMAX;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && shortest[j] < min) {
				min = shortest[j];
				v = j;				
			}
		}
		if (v == D) {
			break;
		}
		visited[v] = true;
		for (int j = 0; j < N; j++) {
			if (!visited[j] && roads[v][j] < INTMAX) {
				if (min + roads[v][j] < shortest[j]) {
					shortest[j] = min + roads[v][j];
					cost[j] = cost[v] + prices[v][j];
					previsit[j] = v;
				}
				else {
					if (min + roads[v][j] == shortest[j]) {
						if (cost[j] > cost[v] + prices[v][j]) {
							cost[j] = cost[v] + prices[v][j];
							previsit[j] = v;
						}
					}
				}
			}
		}
	}

	printpath(D);
	cout << shortest[D] << ' ' << cost[D]<<endl;

	system("pause");
	return 0;
}