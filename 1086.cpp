#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

vector<int> preorder;
vector<int> inorder;

void printpost(int pb, int pe, int ib, int ie) {
	int id;
	int index;

	id = preorder[pb];
	for (int i = ib; i < ie; i++) {
		if (id == inorder[i]) {
			index = i;
		}
	}

	int lenleft = index - ib;
	int lenright = ie - index -1;
	if (lenleft > 0) {
		printpost(pb + 1, pb + lenleft + 1, ib, ib + lenleft);
		cout << ' ';
	}
	if (lenright > 0) {
		printpost(pb + lenleft + 1, pe, ib + lenleft + 1, ie);
		cout << ' ';
	}
	cout << id;
}

int main() {
	int N;
	string str;
	int id;
	stack<int> ct;
	
	cin >> N;
	for (int i = 0; i < 2*N; i++) {
		cin >> str;
		if (str == "Push") {
			cin >> id;
			ct.push(id);
			preorder.push_back(id);
		}
		else {
			id = ct.top();
			ct.pop();
			inorder.push_back(id);
		}
	}

	printpost(0, N, 0, N);
	cout << endl;

	system("pause");
	return 0;
}