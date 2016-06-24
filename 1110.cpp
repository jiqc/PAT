#include<iostream>
#include<vector>
#include<queue>
#include<string>
using namespace std;

int N;
vector<bool> findroot;
vector<vector<int> > nodes;

void BFS(int root) {
	queue<int> tqueue;
	int temp;
	bool wasempty;
	bool complete;

	wasempty = false;
	complete = true;
	tqueue.push(root);
	while (!tqueue.empty()) {
		temp = tqueue.front();
		tqueue.pop();
		if (nodes[temp][0] == -1) {
			wasempty = true;
		}
		else {
			if (wasempty) {
				complete = false;
				break;
			}
			tqueue.push(nodes[temp][0]);
		}
		if (nodes[temp][1] == -1) {
			wasempty = true;
		}
		else {
			if (wasempty) {
				complete = false;
				break;
			}
			tqueue.push(nodes[temp][1]);
		}
	}

	if (!complete) {
		cout << "NO " << root << endl;
	}
	else {
		cout << "YES " << temp << endl;
	}
}

int getnumber(string c) {
	int sum = 0;

    for (int i = 0; i <(int) c.size(); i++) {
		sum = sum * 10 + c[i] - '0';
	}
	
	return sum;
}

int main() {
	string c;
	int root;
	int n;
	
	cin >> N;
	nodes.resize(N);
	findroot.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (c[0] == '-') {
			nodes[i].push_back(-1);
		}
		else{
			n = getnumber(c);
			nodes[i].push_back(n);
			findroot[n] = true;
		}
		cin >> c;
		if (c[0] == '-') {
			nodes[i].push_back(-1);
		}
		else {
			n = getnumber(c);
			nodes[i].push_back(n);
			findroot[n] = true;
		}
	}

	for (int i = 0; i < N; i++) {
		if (!findroot[i]) {
			root = i;
			break;
		}
	}

	BFS(root);

	system("pause");
	return 0;
}