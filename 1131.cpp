#include<cstdio>
#include<vector>
#define INT_MAX 2147483647
using namespace std;

int N;
int cross[10000][10000];
vector<vector<int> > stops(10000);
void buildsubway() {
	scanf_s("%d", &N);
	for (int i = 1; i < N + 1; i++) {
		int M;
		scanf_s("%d", &M);
		int preS;
		for (int j = 0; j < M; j++) {
			int S;
			scanf_s("%d", &S);
			if (j > 0) {
				cross[preS][S] = i;
				cross[S][preS] = i;
				stops[S].push_back(preS);
				stops[preS].push_back(S);
			}
			preS = S;
		}
	}
}

int visited[10000];
vector<int> path;
vector<int> trans;
vector<int> temppath;
vector<int> temptrans;
int steps;
int tnfs;
int start;
int destination;
void dfs(int stop, int tempstep, int temptnfs, int line) {
	if (stop == destination) {
		if (tempstep < steps || (tempstep == steps && temptnfs < tnfs)) {
			path = temppath;
			path.push_back(stop);
			trans = temptrans;
			trans.push_back(line);
			steps = tempstep;
			tnfs = temptnfs;
			return;
		}
	}
	for (int S:stops[stop]) {
		if (visited[S] == 0) {
			visited[S] = 1;
			if (line != 0 && line != cross[stop][S]) {
				temppath.push_back(stop);
				temptrans.push_back(line);
				dfs(S, tempstep + 1, temptnfs + 1, cross[stop][S]);
				temptrans.pop_back();
				temppath.pop_back();
			}
			else {
				dfs(S, tempstep + 1, temptnfs, cross[stop][S]);
			}
			visited[S] = 0;
		}
	}
}

void findway() {
	int K;
	scanf_s("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf_s("%d %d", &start, &destination);

		steps = INT_MAX;
		tnfs = INT_MAX;
		temppath.clear();
		temptrans.clear();
		temppath.push_back(start);
		visited[start] = 1;
		dfs(start, 0, 0, 0);
		visited[start] = 0;

		printf("%d\n", steps);
		if (trans.size() == 0) {
			printf("Take Line#0 from %04d to %04d.\n", start, destination);
		}
		else {
			for (int i = 0; i < trans.size(); i++) {
				printf("Take Line#%d from %04d to %04d.\n", trans[i], path[i], path[i+1]);
			}
		}

	}
}

int main() {
	buildsubway();	
	findway();
	system("pause");
	return 0;
}
