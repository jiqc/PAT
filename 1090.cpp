#include<cstdio>
#include<vector>
#include<queue>
using namespace std;

int N;
double P, r;
vector<vector<int> > chain;

void BFS(int root) {
	queue<int> tqueue;
	int tq;
	int q;
	int t;
	double price;

	tqueue.push(root);
	tq = 1;
	price = P;
	while (!tqueue.empty()) {
		q = tq;
		tq = 0;
		for (int i = 0; i < q; i++) {
			t = tqueue.front();
			tqueue.pop();
			for (int j = 0; j < (int)chain[t].size(); j++) {
				tqueue.push(chain[t][j]);
				tq++;
			}
		}		
		price = price*r;//this is the price this level gives
	}

	price = price / r;// this is the price this level gets

	printf("%.2f %d\n", price, q);
}

int main() {
	int num;
	int root;

	scanf_s("%d %lf %lf", &N, &P, &r);
	r = (100 + r) / 100;

	chain.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		if (num == -1) {
			root = i;
		}
		else {
			chain[num].push_back(i);
		}
	}

	BFS(root);

	system("pause");
	return 0;
}