#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
//five solutions http://blog.csdn.net/sinat_29278271/article/details/47291659
/*---------------------------------------------------------------------------------
vector<int> mystack;
vector<int> mymid;
int pos;

void newpop() {
	if (pos != -1) {
		printf("%d\n", mystack[pos]);
		pos--;
	}
	else {
		printf("Invalid\n");
	}
}

void newpush() {
	int mid;
	vector<int> bak;
	
	pos++;
	scanf_s("%d", &mystack[pos]);
	
	bak.insert(bak.begin(), mystack.begin(), mystack.begin()+pos+1);
	sort(bak.begin(), bak.end());
	mid = pos / 2;
	mymid[pos] = bak[mid];
}

void findmid() {
	if (pos != -1) {		
		printf("%d\n", mymid[pos]);
	}
	else {
		printf("Invalid\n");
	}
}

int main() {
	pos = -1;
	mystack.resize(100000);
	mymid.resize(100000);

	char str[11];

	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s", str, 11);
		if (strcmp(str, "Pop")==0) {
			newpop();
		}
		else {
			if (strcmp(str, "PeekMedian")==0) {
				findmid();
			}
			else {
				newpush();
			}
		}
	}

	system("pause");
	return 0;
}
-----------------------------------------------------------------------------------------*/

struct Treap_Node {
	int value;
	int count;
	int size;
	int fix;
	Treap_Node *left, *right;

	Treap_Node() :count(0), size(0), left(NULL), right(NULL) {}
	Treap_Node(int _value) :value(_value), count(0), size(0), left(NULL), right(NULL) {}
};

Treap_Node * root = NULL;

inline void Treap_SetSize(Treap_Node *&P) {
	if (P) {
		P->size = P->count;
		if (P->left) {
			P->size += P->left->size;
		}
		if (P->right) {
			P->size += P->right->size;
		}
	}
}

inline int lsize(Treap_Node *&P) {
	return P->left ? P->left->size : 0;
}

inline int rsize(Treap_Node *&P) {
	return P->right ? P->right->size : 0;
}

void Treap_Left_Rotate(Treap_Node *&a) {
	Treap_Node *b = a->right;
	a->right = b->left;
	b->left = a;
	a = b;
	Treap_SetSize(a->left);
	Treap_SetSize(a->right);
	Treap_SetSize(a);
}

void Treap_Right_Rotate(Treap_Node *&a) {
	Treap_Node *b = a->left;
	a->left = b->right;
	b->right = a;
	a = b;
	Treap_SetSize(a->left);
	Treap_SetSize(a->right);
	Treap_SetSize(a);
}

bool Treap_Delete(Treap_Node *&P, int value) {
	bool ret = false;
	if (!P) {
		ret = false;
	}
	else {
		if (value < P->value) {
			Treap_Delete(P->left, value);
		}
		else {
			if (value > P->value) {
				Treap_Delete(P->right, value);
			}
			else {
				if (P->count == 0 ||(--P->count) == 0 ) {
					if (!P->left || !P->right) {
						Treap_Node *t = P;
						if (!P->right) {
							P = P->left;
						}
						else {
							P = P->right;
						}
						delete t;
						ret = true;
					}
					else {
						if (P->left->fix < P->right->fix) {
							Treap_Right_Rotate(P);
							ret = Treap_Delete(P->right, value);
						}
						else {
							Treap_Left_Rotate(P);
							ret = Treap_Delete(P->left, value);
						}
					}
				}				
			}
		}
		Treap_SetSize(P);
	}
	return ret;
}

void Treap_Insert(Treap_Node *&P, int value) {
	if (!P) {
		P = new Treap_Node;
		P->value = value;
		P->fix = rand();
	}
	if (value < P->value) {
		Treap_Insert(P->left, value);
		if (P->left->fix < P->fix) {
			Treap_Right_Rotate(P);
		}
	}
	else {
		if (P->value < value) {
			Treap_Insert(P->right, value);
			if (P->right->fix < P->fix) {
				Treap_Left_Rotate(P);
			}
		}
		else {
			P->count++;
		}
	}
	Treap_SetSize(P);
}

Treap_Node* Treap_Findkth(Treap_Node *&P, int k) {
	if (k <= lsize(P)) {
		return Treap_Findkth(P->left, k);
	}
	else {
		if (k > lsize(P) + P->count) {
			return Treap_Findkth(P->right, k - (lsize(P) + P->count));
		}
		else {
			return P;
		}
	}
}

stack<int> mystack;

void mypop() {
	if (mystack.empty()) {
		printf("Invalid\n");
	}
	else {
		printf("%d\n", mystack.top());

		Treap_Delete(root, mystack.top());

		mystack.pop();
	}
}

void mypush() {
	int num;

	scanf_s("%d", &num);
	mystack.push(num);

	Treap_Insert(root, num);
}

void peekmedian() {
	if (mystack.empty()) {
		printf("Invalid\n");
	}
	else {
		Treap_Node *T = Treap_Findkth(root, (mystack.size() + 1) / 2);
		printf("%d\n", T->value);
	}
}

int main() {
	char str[11];

	int N;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s", str, 11);
		switch(str[1]) {
		case'o':
			mypop();
			break;
		case'u':
			mypush();
			break;
		case'e':
			peekmedian();
			break;
		}
	}

	system("pause");
	return 0;
}
