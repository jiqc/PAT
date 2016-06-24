#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

int N;
double P;
double r;
vector<vector<int> > chain;

void BFS() {
	queue<int> tqueue;
	double price;
	int tq;
	int q;
	int temp;
	int k;

	tqueue.push(0);
	tq = 1;
	price = P;
	while (!tqueue.empty()) {
		q = tq;
		tq = 0;
		k = 0;
		for (int i = 0; i < q;i++){
			temp = tqueue.front();
			tqueue.pop();
			if (chain[temp].empty()) {
				k++;
			}
			for (int j = 0; j < (int)chain[temp].size(); j++) {
				tqueue.push(chain[temp][j]);
				tq++;
			}
		}
		if (k != 0) {
			break;
		}
		price *= r;
	}

	//price /= r;
	printf("%.4f %d\n", price, k);
}

int main() {
	int K;
	
	scanf_s("%d %lf %lf", &N, &P, &r);
	r = (r + 100) / 100;

	chain.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &K);
		chain[i].resize(K);
		for (int j = 0; j < K; j++) {
			scanf_s("%d", &chain[i][j]);
		}
	}

	BFS();

	system("pause");
	return 0;
}