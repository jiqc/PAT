#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int weight;
	int K;
	vector<int> leaves;
	bool find;
	int parent;
};

int N, M, S;
vector<node> tree;
vector<vector<int> > path;

void DFS(int id, int s) {
	int surplus = s - tree[id].weight;
	if (surplus > 0) {
		for (int i = 0; i < tree[id].K; i++) {
			DFS(tree[id].leaves[i], surplus);
		}
	}
	else {
		if (surplus == 0) {
			if (tree[id].K == 0) {
				tree[id].find = true;
			}
		}
	}
}

void makepath(int id, int p) {
	if (id != 0) {
		makepath(tree[id].parent, p);
		path[p].push_back(tree[id].weight);
	}
	else {
		path[p].push_back(tree[id].weight);
	}
}

void findpath() {
	int p = 0;
	vector<int> temp;
	for (int i = 0; i < N; i++) {
		if (tree[i].find) {
			path.push_back(temp);
			makepath(i, p);
			p++;
		}
	}
}

bool no_increase(const vector<int> &A, const vector<int> &B) {
	int i = 0;
	int min = A.size() < B.size() ? A.size() : B.size();
	while (A[i] == B[i]) {
		i++;
		if (i == min - 1) {
			break;
		}
	}
	return A[i] > B[i];
}

int main() {
	
	cin >> N >> M >> S;

	tree.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> tree[i].weight;
	}

	int id;
	for (int i = 0; i < M; i++) {
		cin >> id;
		cin >> tree[id].K;
		tree[id].leaves.resize(tree[id].K);
		int subid;
		for (int j = 0; j < tree[id].K; j++) {
			cin >> subid;
			tree[id].leaves[j] = subid;
			tree[subid].parent = id;
		}
	}

	DFS(0, S);

	findpath();

	sort(path.begin(), path.end(), no_increase);

	for (unsigned int i = 0; i < path.size(); i++) {
		cout << path[i][0];
		for (unsigned int j = 1; j < path[i].size(); j++) {
			cout << ' ' << path[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}