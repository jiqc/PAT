#include<iostream>
using namespace std;

struct avlnode {
	int num;
	avlnode * left;
	avlnode * right;
	int height;
};

inline int Avltree_Height(avlnode * P) {
	if (P == NULL) {
		return -1;
	}
	else {
		return P->height;
	}
}

avlnode * Single_Rotate_Left(avlnode * K2) {
	avlnode * K1;

	K1 = K2->left;
	K2->left = K1->right;
	K1->right = K2;

	K2->height = Avltree_Height(K2->left)>Avltree_Height(K2->right) ? Avltree_Height(K2->left) + 1 : Avltree_Height(K2->right) + 1;
	K1->height = Avltree_Height(K1->left)>Avltree_Height(K1->right) ? Avltree_Height(K1->left) + 1 : Avltree_Height(K1->right) + 1;

	return K1;
}

avlnode * Single_Rotate_Right(avlnode * K2) {
	avlnode * K1;

	K1 = K2->right;
	K2->right = K1->left;
	K1->left = K2;

	K2->height = Avltree_Height(K2->left)>Avltree_Height(K2->right) ? Avltree_Height(K2->left) + 1 : Avltree_Height(K2->right) + 1;
	K1->height = Avltree_Height(K1->left)>Avltree_Height(K1->right) ? Avltree_Height(K1->left) + 1 : Avltree_Height(K1->right) + 1;

	return K1;
}

avlnode * Double_Rotate_Left(avlnode * K3) {
	K3->left = Single_Rotate_Right(K3->left);
	return  Single_Rotate_Left(K3);
}

avlnode * Double_Rotate_Right(avlnode * K3) {
	K3->right = Single_Rotate_Left(K3->right);
	return  Single_Rotate_Right(K3);
}

avlnode * Avltree_Insert(int num, avlnode * T) {
	if (T == NULL) {
		T = new avlnode;
		T->num = num;
		T->left = T->right = NULL;
	}
	else {
		if (num < T->num) {
			T->left = Avltree_Insert(num, T->left);
			if (Avltree_Height(T->left) - Avltree_Height(T->right) == 2) {
				if (num < T->left->num) {
					T = Single_Rotate_Left(T);
				}
				else {
					T = Double_Rotate_Left(T);
				}
			}
		}
		else {
			if (num > T->num) {
				T->right = Avltree_Insert(num, T->right);
				if (Avltree_Height(T->right) - Avltree_Height(T->left) == 2) {
					if (num > T->right->num) {
						T = Single_Rotate_Right(T);
					}
					else {
						T = Double_Rotate_Right(T);
					}
				}
			}
		}
	}

	T->height = Avltree_Height(T->left)>Avltree_Height(T->right) ? Avltree_Height(T->left) + 1 : Avltree_Height(T->right) + 1;

	return T;
}

int main() {
	int N;
	int m;
	avlnode * root = NULL;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> m;
		root = Avltree_Insert(m, root);
	}

	cout << root->num << endl;

	system("pause");
	return 0;
}