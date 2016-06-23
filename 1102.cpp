#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int N;
vector<vector<int> > nodes;
vector<int> findroot;
vector<int> inodr;
vector<int> levelorder;

void inorder(int root) {
	if (nodes[root][1] != -1) {
		inorder(nodes[root][1]);
	}
	inodr.push_back(root);
	if (nodes[root][0] != -1) {
		inorder(nodes[root][0]);
	}
}

void BFS(int root) {
	queue<int> tqueue;
	int temp;

	tqueue.push(root);
	while (!tqueue.empty()) {
		temp = tqueue.front();
		levelorder.push_back(temp);
		tqueue.pop();
		if (nodes[temp][1] != -1) {
			tqueue.push(nodes[temp][1]);
		}
		if (nodes[temp][0] != -1) {
			tqueue.push(nodes[temp][0]);
		}
	}
}

int main() {
	char c;
	int root;

	cin >> N;
	nodes.resize(N);
	findroot.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c != '-') {
			nodes[i].push_back(c - '0');
			findroot[c - '0'] = true;
		}
		else {
			nodes[i].push_back(-1);
		}
		cin >> c;
		if (c != '-') {
			nodes[i].push_back(c - '0');
			findroot[c - '0'] = true;
		}
		else {
			nodes[i].push_back(-1);
		}
	}

	for (int i = 0; i < N; i++) {
		if (!findroot[i]) {
			root = i;
			break;
		}
	}

	BFS(root);

	inorder(root);

	cout << levelorder[0];
	for (int i = 1; i < N; i++) {
		cout <<' ' << levelorder[i];
	}
	cout << endl;
	cout << inodr[0];
	for (int i = 1; i < N; i++) {
		cout << ' ' << inodr[i];
	}
	cout << endl;

	system("pause");
	return 0;
}