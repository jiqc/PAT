//The first, second & third procedure has been AC.
/****************************************************/


//the time complexity is O(log(M+N))
#include<cstdio>
#include<vector>
using namespace std;

int N1, N2;
vector<long int>a, b;

long int findkth(bool ab, int pos1, int m, int pos2, int n, int k) {
	if (m > n) {
		return findkth(!ab, pos2, n, pos1, m, k);
	}
	if (m == 0) {
		if (ab) {
			return b[pos2 + k - 1];
		}
		else {
			return a[pos2 + k - 1];
		}
	}
	if (k == 1) {
		if (ab) {
			return a[pos1] < b[pos2] ? a[pos1] : b[pos2];
		}
		else {
			return b[pos1] < a[pos2] ? b[pos1] : a[pos2];
		}
	}
	int p1 = k / 2 < m ? k / 2 : m;
	int p2 = k - p1;
	if (ab) {
		if (a[pos1 + p1 - 1] == b[pos2 + p2 - 1])return a[pos1 + p1 - 1];
		if (a[pos1 + p1 - 1] < b[pos2 + p2 - 1]) {
			return findkth(ab, pos1 + p1, m - p1, pos2, p2, k - p1);
		}
		else {
			return findkth(ab, pos1, p1, pos2 + p2, n - p2, k - p2);
		}
	}
	else {
		if (b[pos1 + p1 - 1] == a[pos2 + p2 - 1])return b[pos1 + p1 - 1];
		if (b[pos1 + p1 - 1] < a[pos2 + p2 - 1]) {
			return findkth(ab, pos1 + p1, m - p1, pos2, p2, k - p1);
		}
		else {
			return findkth(ab, pos1, p1, pos2 + p2, n - p2, k - p2);
		}
	}
}

int main() {
	long int num;

	scanf_s("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf_s("%ld", &num);
		a.push_back(num);
	}
	scanf_s("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf_s("%ld", &num);
		b.push_back(num);
	}

	printf("%ld\n", findkth(true,0,N1,0,N2,N1+N2-(N1+N2)/2));

	system("pause");
	return 0;
}


/************************************************************/
/*

//the time complexity is O(M+N)
#include<cstdio>
#include<cstdlib>
using namespace std;

int main() {
	int N1, N2;
	

	scanf_s("%d", &N1);
	long int *a = (long int *)malloc(sizeof(long int)*N1);
	for (int i = 0; i < N1; i++) {
		scanf_s("%ld", &a[i]);
	}

	scanf_s("%d", &N2);
	long int *b = (long int *)malloc(sizeof(long int)*N2);
	for (int i = 0; i < N2; i++) {
		scanf_s("%ld", &b[i]);
	}

	int K;
	K = (N1 + N2 - 1) / 2;
	if (a[N1 - 1] <= b[0]) {
		if (K <= N1 - 1) {
			printf("%ld\n", a[K]);
		}
		else {
			printf("%ld\n", b[K - N1]);
		}
	}
	else {
		if (a[0] >= b[N2 - 1]) {
			if (K <= N2 - 1) {
				printf("%ld\n", b[K]);
			}
			else {
				printf("%ld\n", a[K - N2]);
			}
		}
		else {
			int k = 0, j = 0;
			for (int i = 0; i < K; i++) {
				if (k == N1 || (j != N2 && a[k] > b[j])) {
					j++;
				}
				else {
					k++;
				}
			}

			if (k == N1 || (j != N2 && a[k] > b[j])) {
				printf("%ld\n", b[j]);
			}
			else {
				printf("%ld\n", a[k]);
			}
		}
	}
	

	free(a);
	free(b);

	system("pause");
	return 0;
}

*/
/**********************************************************************/
/*

//the time complexity is O(log(M+N))
#include<cstdio>
#include<vector>
using namespace std;

int N1, N2;
vector<long int>a, b;

int findonline(int K, int j1, int j2) {
	for (int i = 0; i < K; i++) {
		if (j1 == N1 || (j2 != N2 && a[j1] > b[j2])) {
			j2++;
		}
		else {
			j1++;
		}
	}

	if (j1 == N1 || (j2 != N2 && a[j1] > b[j2])) {
		return b[j2];
	}
	else {
		return a[j1];
	}
}

int main() {
	long int num;

	scanf_s("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf_s("%ld", &num);
		a.push_back(num);
	}
	scanf_s("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf_s("%ld", &num);
		b.push_back(num);
	}

	int K;
	K = (N1 + N2 - 1) / 2;
	if (a[N1 - 1] <= b[0]) {
		if (K <= N1 - 1) {
			num = a[K];
		}
		else {
			num = b[K - N1];
		}
	}
	else {
		if (a[0] >= b[N2 - 1]) {
			if (K <= N2 - 1) {
				num = b[K];
			}
			else {
				num = a[K - N2];
			}
		}
		else {
			int p1 = 0, p2 = 0;
	        while(K>10){
		        if ((N1 - p1 >= K / 2) && (N2 - p2 >= K / 2)) {
			        if (a[p1 + K / 2] > b[p2 + K / 2]) {
				        p2 += K / 2;
				        K = K - K / 2;
		         	}
		        	else {
			        	p1 += K / 2;
		        		K = K - K / 2;
		        	}
	        	}
		        else {
    		    	if (N1 - p1 < K / 2) {
		    		    if (a[N1 - 1] < b[p2 + K / 2]) {
	     	    			K = K - (N1 - p1);
	    	    			p1 = N1;
    		    			break;
	        			}
	        			else {
	        				p2 += K / 2;
	         				K = K - K / 2;
	        			}
        			}
					else{
	        			if (a[p1 + K / 2]>b[N2 - 1]) {
	        				K = K - (N2 - p2);
			         		p2 = N2;
		        			break;
	        			}
		        		else {
		         			p1 += K / 2;
	         				K = K - K / 2;
	        			}
        			}
	         	}
        	}

        	if (p1 == N1) {
         		num = b[p2 + K];
        	}
        	else {
        		if (p2 == N2) {
         			num = a[p1 + K];
        		}
        		else {
        			num = findonline(K, p1, p2);
        		}
        	}	
		}
	}
	

	printf("%ld\n", num);

	system("pause");
	return 0;
}

*/
/***********************************************************************/
/* 

//the time complexity is O((M+N)log(M + N))
#include<cstdio>
#include<cstdlib>
using namespace std;

struct Treap_Node {
	long int value;
	int count;
	int size;
	int fix;
	Treap_Node *left, *right;

	Treap_Node():count(0), size(0), left(NULL), right(NULL){}
	Treap_Node(long int _value):value(_value),count(0),size(0),left(NULL),right(NULL){}
};

Treap_Node *root = NULL;

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

void Treap_Insert(Treap_Node *&P, long int value) {
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
		if (value > P->value) {
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

Treap_Node * Treap_Findkth(Treap_Node *&P, int k) {
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

int main() {
	int N1,N2;
	long int num;

	scanf_s("%d", &N1);
	for (int i = 0; i < N1; i++) {
		scanf_s("%ld", &num);
		Treap_Insert(root, num);
	}
	scanf_s("%d", &N2);
	for (int i = 0; i < N2; i++) {
		scanf_s("%ld", &num);
		Treap_Insert(root, num);
	}

	int k = (N1 + N2 + 1) / 2;
	Treap_Node * T = Treap_Findkth(root, k);
	printf("%ld\n", T->value);

	system("pause");
	return 0;
}

*/
