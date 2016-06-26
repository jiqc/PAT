#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int M, N, ID, K, child;

	//construct tree
	cin >> M >> N;
	vector<int> *node = new vector<int>[M];
	for (int i = 0; i < N; i++) {
		cin >> ID >> K;
		for (int j = 0; j < K; j++) {
			cin >> child;
			node[ID - 1].push_back(child - 1);
		}
	}

	//breadth first search
	queue<int> layer;
	layer.push(0);
	while (!layer.empty()) {
		int num_leaf = 0;
		int cursize = layer.size();
		for (int i = 0; i < cursize; i++) {
			int one = layer.front();
			if (node[one].empty()) {
				num_leaf++;
			}
			else {
				for (int j = 0; j < node[one].size(); j++) {
					layer.push(node[one][j]);
				}
			}
			layer.pop();
		}
		cout << num_leaf;
		if (!layer.empty()) {
			cout << " ";
		}
	}
	cout<<"\n";

	system("pause");
	return 0;
}