#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N, L;
vector<bool> visited;
vector<vector<int> > weibo;

int BFS(int U) {
	int templevel;
	int count;
	int tempU;
	int quantitydelevel;
	int tempql;
	queue<int> tempqueue;

	visited.clear();
	visited.resize(N + 1);

	templevel = 0;
	count = 0;
	tempqueue.push(U);
	tempql = 1;
	visited[U] = true;
	while (templevel < L && !tempqueue.empty()) {
		quantitydelevel = tempql;
		tempql = 0;
		for (int i = 0; i < quantitydelevel; i++) {
			tempU = tempqueue.front();
		    tempqueue.pop();
			for (int j = 0; j < (int)weibo[tempU].size(); j++) {
				if (!visited[weibo[tempU][j]]) {
					tempqueue.push(weibo[tempU][j]);
					visited[weibo[tempU][j]] = true;
					tempql++;
					count++;
				}
			}
		}
		templevel++;		
	}

	return count;
}

int main() {
	
	scanf_s("%d %d", &N, &L);

	int M, U;
	weibo.resize(N + 1);
	for (int i = 1; i < N + 1; i++) {
		scanf_s("%d", &M);
		for (int j = 0; j < M; j++) {
			scanf_s("%d", &U);
			weibo[U].push_back(i);
		}
	}

	int K;
	int G;
	scanf_s("%d", &K);
	for (int i = 0; i < K; i++) {
		scanf_s("%d", &U);
		G = BFS(U);
	    printf("%d\n", G);
	}

	system("pause");
	return 0;
}