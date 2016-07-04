#include<cstdio>
#include<vector>
using namespace std;
   
struct node {
	int num;
	node * right;
	node * left;
};

int N;
vector<int> numin;
bool mirror;

bool judge(int pre, int pos) {
	if (pre + 2 >= pos) {
		return true;
	}
	int mid = numin[pre];
	int index;
	pre++;
	if (mirror) {
		for (index = pre; index < pos; index++) {
			if (numin[index] < mid) {
				break;
			}
		}
		for (int i = index; i < pos; i++) {
			if (numin[i] >= mid) {
				return false;
			}
		}
		return judge(pre, index) && judge(index, pos);
	}
	else {
		for (index = pre; index < pos; index++) {
			if (numin[index] >= mid) {
				break;
			}
		}
		for (int i = index; i < pos; i++) {
			if (numin[i] < mid) {
				return false;
			}
		}
		return judge(pre, index) && judge(index, pos);
	}
}

node * insert(int m, node*T) {
	if (T == NULL) {
		T = new node;
		T->num = m;
		T->left = T->right = NULL;
	}
	else {
		if (mirror) {
			if (m >= T->num) {
				T->left = insert(m, T->left);
			}
			else {
				T->right = insert(m, T->right);
			}
		}
		else {
			if (m < T->num) {
				T->left = insert(m, T->left);
			}
			else {
				T->right = insert(m, T->right);
			}
		}
	}
	return T;
}

node * maketree(node * tree) {
	for (int i = 0; i < N; i++) {
		tree = insert(numin[i],tree);
	}
	return tree;
}

void postprint(node * t) {
	if (t == NULL) {
		return;
	}
	if (t->left != NULL) {
		postprint(t->left);
	    printf(" ");
	}
	if (t->right != NULL) {
        postprint(t->right);
	    printf(" ");
	}	
	printf("%d", t->num);
}

int main() {
	bool isbft;
	node * tree;
	tree = NULL;
	
	scanf_s("%d", &N);
	numin.resize(N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &numin[i]);
	}

	if (numin[0] <= numin[1]) {
		mirror = true;
	}
	else {
		mirror = false;
	}

	isbft = judge(0, N);

	if (isbft) {
		tree = maketree(tree);
		printf("YES\n");
		postprint(tree);
		printf("\n");
	}
	else {
		printf("NO\n");
	}

	system("pause");
	return 0;
}