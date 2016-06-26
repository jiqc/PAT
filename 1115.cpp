#include<iostream>
#include<queue>
using namespace std;

struct node {
	int num;
	node *left;
	node *right;
};

node * insert(node *P, int s) {
	if (P == NULL) {
		P = new node;
		P->num = s;
		P->left = P->right = NULL;
	}
	else {
		if (s <= P->num) {
			P->left = insert(P->left, s);
		}
		else {
			P->right = insert(P->right, s);
		}
	}

	return P;
}

void BFS(node *P) {
	queue<node*> tqueue;
	int lst, lbo;
	int q;
	node * temp;

	tqueue.push(P);
	q = 1;
	lst = lbo = 0;
	while (!tqueue.empty()) {
		lbo = lst;
		lst = q;
		q = 0;
		for (int i = 0; i < lst; i++) {
			temp = tqueue.front();
			tqueue.pop();
			if (temp->left != NULL) {
				tqueue.push(temp->left);
				q++;
			}
			if (temp->right != NULL) {
				tqueue.push(temp->right);
				q++;
			}			
		}
	}

	cout << lst << " + " << lbo << " = " << lst + lbo << endl;
}

int main() {
	int N;
	int num;
	node *root;

	root = NULL;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num;
		root = insert(root, num);
	}

	BFS(root);

	system("pause");
	return 0;
}