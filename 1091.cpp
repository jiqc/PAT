#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node {
	int a, b, c;
};

vector<vector<vector<int> > > slices;

int BFS(int i, int j, int k) {
	int count;
	queue<node> tqueue;
	node temp,t;

	temp.a = i;
	temp.b = j;
	temp.c = k;

	tqueue.push(temp);
	count = 1;
	slices[temp.a][temp.b][temp.c] = 0;
	while (!tqueue.empty()) {
		temp = tqueue.front();
		tqueue.pop();
		if (slices[temp.a + 1][temp.b][temp.c]) {
			t.a = temp.a + 1;
			t.b = temp.b;
			t.c = temp.c;
			tqueue.push(t);
			count++;
			slices[temp.a + 1][temp.b][temp.c] = 0;
		}
		if (slices[temp.a - 1][temp.b][temp.c]) {
			t.a = temp.a - 1;
			t.b = temp.b;
			t.c = temp.c;
			tqueue.push(t);
			count++;
			slices[temp.a - 1][temp.b][temp.c] = 0;
		}
		if (slices[temp.a ][temp.b+ 1][temp.c]) {
			t.a = temp.a;
			t.b = temp.b + 1;
			t.c = temp.c;
			tqueue.push(t);
			count++;
			slices[temp.a][temp.b + 1][temp.c] = 0;
		}
		if (slices[temp.a][temp.b-1][temp.c]) {
			t.a = temp.a ;
			t.b = temp.b-1;
			t.c = temp.c;
			tqueue.push(t);
			count++;
			slices[temp.a ][temp.b-1][temp.c] = 0;
		}
		if (slices[temp.a ][temp.b][temp.c+ 1]) {
			t.a = temp.a ;
			t.b = temp.b;
			t.c = temp.c+ 1;
			tqueue.push(t);
			count++;
			slices[temp.a ][temp.b][temp.c+ 1] = 0;
		}
		if (slices[temp.a ][temp.b][temp.c-1]) {
			t.a = temp.a;
			t.b = temp.b;
			t.c = temp.c-1;
			tqueue.push(t);
			count++;
			slices[temp.a ][temp.b][temp.c-1] = 0;
		}
	}

	return count;
}

int main() {
	int M, N, L, T;
	
	int stroke;
	int count;

	cin >> M >> N >> L >> T;
	slices.resize(L+2);
	for (int i = 0; i < L+2; i++) {
		slices[i].resize(M + 2);
		for (int j = 0; j < M + 2; j++) {
			slices[i][j].resize(N + 2);
		}
	}

	for (int i = 0; i < L; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				cin >> slices[i + 1][j + 1][k + 1];
			}
		}
	}

	stroke = 0;
	for (int i = 1; i < L+1; i++) {
		for (int j = 1; j < M+1; j++) {
			for (int k = 1; k < N+1; k++) {
				if (slices[i][j][k]) {
                    count=BFS(i, j, k);
					if (count >= T)stroke+=count;
				}				
			}
		}
	}

	cout << stroke << endl;

	system("pause");
	return 0;
}