#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int N, M, K;
stack<int> cup;
vector<int> temp;

bool isright() {
	while (!cup.empty()) {
		cup.pop();
	}
	int num;
	int p = N;
	for (int i = N - 1; i >= 0; i--) {
		if (cup.empty()) {
			cup.push(temp[i]);
		}
		else {
			while (!cup.empty() && cup.top() > temp[i]) {
				num = cup.top();
				if (num != p) {
					return false;
				}
				cup.pop();
				p--;
			}
			if (cup.size() == M) {
				return false;
			}
			else {
				cup.push(temp[i]);
			}
		}
	}
	return true;
}

int main() {
	bool judge;	

	cin >> M >> N >> K;
	temp.resize(N);
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> temp[j];
		}
		judge = isright();
		if (judge) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}

	system("pause");
	return 0;
}