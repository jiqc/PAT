#include<stdio.h>
#include<cstdio>
#include<vector>

using namespace std;

class unionset {
public:
	int num;
	vector<int> vtx;
	vector<int> rank;
	unionset(int n) {
		num = n;
		vtx.resize(n + 1);
		for (int i = 0; i < n + 1; i++) {
			vtx[i] = i;
		}
		rank.resize(n + 1, 0);
	}
	~unionset() {};
	int find(int x) {
		if (vtx[x] == x) {
			return x;
		}
		else {
			vtx[x] = find(vtx[x]);
			return vtx[x];
		}
	}
	void uniontwo(int x, int y) {
		int fx = find(x);
		int fy = find(y);
		if (fx == fy) {
			return;
		}
		if (rank[fx] > rank[fy]) {
			vtx[fy] = fx;
		}
		else {
			vtx[fx] = fy;
			if (rank[fx] == rank[fy]) {
				rank[fy] ++;
			}
		}
		num--;
	}
};

int main() {
	int N, M;
	scanf_s("%d %d", &N, &M);
	unionset graph(N);
	vector<int> vertices(N + 1, 0);
	int v1, v2;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &v1, &v2);
		vertices[v1]++;
		vertices[v2]++;
		graph.uniontwo(v1, v2);
	}

	int cnt_odd = 0;
	if (vertices[1] % 2) {
		cnt_odd = 1;
	}
	printf_s("%d", vertices[1]);
	for (int i = 2; i < N + 1; i++) {
		printf_s(" %d", vertices[i]);
		if (vertices[i] % 2) {
			cnt_odd++;
		}
	}
	printf("\n");

	if (graph.num > 1) {
		printf_s("Non-Eulerian\n");
		system("pause");
		return 0;
	}
	if (cnt_odd) {
		if (cnt_odd == 2) {
			printf_s("Semi-Eulerian\n");
		}
		else {
			printf_s("Non-Eulerian\n");
		}
	}
	else {
		printf_s("Eulerian\n");
	}

	system("pause");
	return 0;
}
