#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define INT_MAX 0x7fffffff

struct station {
	int ID;
	double mindis;
	double avgdis;
};

int N, M, K;
double D;
vector<bool> visited;
vector<double> shortest;
vector<vector<double> > roads;
//vector<bool> solution;
vector<station> valid;

void Dijkstra(int outset) {
	int v;
	double min;
	for (int i = 1; i < N + M; i++) {
		min = (double)INT_MAX;
		for (int j = 0; j < N + M; j++) {
			if (!visited[j] && shortest[j] < min) {
				v = j;
				min = shortest[j];
			}
		}
		//if (min > D) {//sometimes min may be the distance to other gas stop;
		                //so it's not necessary to make min to be key point;
		//	return;
		//}
		visited[v] = true;
		for (int j = 0; j < N + M; j++) {
			if (!visited[j] && roads[v][j]<(double)INT_MAX) {
				if (min + roads[v][j] < shortest[j]) {
					shortest[j] = min + roads[v][j];
				}				
			}
		}
	}
	//solution[outset] = true;
	return;
}

bool camp(const station &A, const station &B) {
	if (A.mindis != B.mindis) {
		return A.mindis > B.mindis;
	}
	else {
		if (A.avgdis != B.avgdis) {
		    return A.avgdis < B.avgdis;
	    }
	    else {
		    return A.ID < B.ID;
	    }
	}	
}

int getnum() {
	char c[5];
	int sum;
	int res;

	scanf_s("%s", c, 5);
	sum = 0;
	if (c[0] != 'G') {
		for (int i = 0; c[i] != '\0'; i++) {
			sum = sum * 10 + c[i] - '0';
		}
		res = sum - 1;
	}
	else {
		for (int i = 1; c[i] != '\0'; i++) {
			sum = sum * 10 + c[i] - '0';
		}
		res = sum + N - 1;
	}

	return res;
}

int main() {
	double sum;
	double min;
	double max;
	cin >> N >> M >> K >> D;
	
	roads.resize(N + M);
	for (int i = 0; i < N + M; i++) {
		roads[i].resize(N + M, (double)INT_MAX);
		roads[i][i] = 0;
	}
	
	int a, b;
	double d;
	for (int i = 0; i < K; i++) {
		a = getnum();
		b = getnum();
		scanf_s("%lf", &d);
		roads[a][b] = roads[b][a] = d;
	}

	//solution.resize(M);
	station temp;
	for (int i = 0; i < M; i++) {
        visited.resize(N + M);
	    shortest.resize(N + M);

		for (int j = 0; j < N + M; j++) {
			shortest[j] = roads[N + i][j];
		}
		visited[N + i] = true;

		Dijkstra(i);

		sum = 0;
		min = (double)INT_MAX;// D;
		max = 0;
		//if (solution[i]) {
			for (int j = 0; j < N; j++) {
				sum += shortest[j];
				if (shortest[j] < min) {
					min = shortest[j];
				}
				if (shortest[j] > max) {
					max = shortest[j];
				}
			}
			temp.ID = i + 1;
			temp.mindis = min;
			temp.avgdis = sum / N;
			if (max <= D) {
				valid.push_back(temp);
			}			
		//}

		visited.clear();
		shortest.clear();
	}

    if (valid.empty()) {
		cout << "No Solution\n";
	}
	else {
		sort(valid.begin(), valid.end(), camp);
		cout << 'G' << valid[0].ID << endl;
		printf("%.1f %.1f\n", valid[0].mindis, valid[0].avgdis);
	}

	system("pause");
	return 0;
}
