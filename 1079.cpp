#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<iomanip>
using namespace std;

struct node {
	int id;
	bool retailer;
	int selled;
	vector<int> adj;

	node() {
		retailer = false;
		selled = 0;
	}
};

int N;
double P, r;
vector<node> chain;

double BFS() {
	queue<int> tempqueue;
	double tempprice;
	int tempqs;
	int levelsize;
	int tempid;
	double sales;

	tempqueue.push(0);
	tempqs = 1;
	tempprice = P;
	sales = 0;
	while (!tempqueue.empty()) {
		levelsize = tempqs;
		tempqs = 0;
		for (int i = 0; i < levelsize; i++) {
			tempid = tempqueue.front();
		    tempqueue.pop();
			if (chain[tempid].retailer) {
				sales += tempprice*chain[tempid].selled;
			}
			else {
				for (int j = 0; j < (int)chain[tempid].adj.size(); j++) {
					tempqueue.push(chain[tempid].adj[j]);
					tempqs++;
				}
			}
		}
		tempprice *= (1 + r / 100);
	}

	return sales;
}

int main() {
	int K, ID;
	double sales;

	cin >> N >> P >> r;

	chain.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> K;
		if (K == 0) {
			chain[i].retailer = true;
			cin >> ID;
			chain[i].selled = ID;
		}
		else {
			for (int j = 0; j < K; j++) {
				cin >> ID;
				chain[i].adj.push_back(ID);
			}
		}
	}

	sales = BFS();

	printf("%.1f\n", sales);
	//cout << setiosflags(ios::fixed) << setprecision(1) << sales << endl;

	system("pause");
	return 0;
}

