#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int N, M;
	vector<vector<int> > members;
	int num;
	int k;

	cin >> N >> M;
	members.resize(N+1);
	for (int i = 0; i < M; i++) {
		cin >> num >> k;
		members[num].resize(k);
		for (int j = 0; j < k; j++) {
			cin >> members[num][j];
		}
	}

	queue<int> tqueue;
	int n_max = 1;
	int n_level = 1;
	int level = 1;
	int tq, q;

	tqueue.push(1);
	tq = 1;
	while (!tqueue.empty()) {
		q = tq;
		if (q > n_max) {
			n_max = q;
			n_level = level;
		}
		tq = 0;
		for (int i = 0; i < q; i++) {
			num = tqueue.front();
			tqueue.pop();
			for (int j = 0; j < (int)members[num].size(); j++) {
				tqueue.push(members[num][j]);
				tq++;
			}
		}
		level++;
	}

	cout << n_max << ' ' << n_level << endl;

	system("pause");
	return 0;
}