#include<cstdio>
#include<vector>
#include<cstring>
#include<string>
using namespace std;

struct word {
	string w;
	int count;
	word * left;
	word * right;

	word() {
		w = "";
		count = 0;
		left = right = NULL;
	}
	word(string a) :w(a) {
		count = 1;
		left = right = NULL;
	}
};

word * root = NULL;

word* rotate_left(word * P) {
	word * K;

	K = P->left;
	P->left = K->right;
	K->right = P;

	return K;
}

word * rotate_right(word * P) {
	word *K;

	K = P->right;
	P->right = K->left;
	K->left = P;

	return K;
}

word * word_insert(const string s, word * P) {
	if (P == NULL) {
		P = new word(s);
	}
	else {
		if (s < P->w) {
			P->left = word_insert(s, P->left);
			if (P->left->count >= P->count) {
				P = rotate_left(P);
			}
		}
		else {
			if (s > P->w) {
				P->right = word_insert(s, P->right);
			    if (P->right->count > P->count) {
				    P = rotate_right(P);
			    }
			}
			else {
				P->count++;
			}		
		}
	}

	return P;
}

int main() {
	char c;
	string s;

	while ((c = getchar()) != '\n') {
		if ((c >= '0'&& c<='9')|| (c >= 'A'&& c <= 'Z') || (c >= 'a'&& c <= 'z')) {			
			if (c >= 'A'&&c <= 'Z') {
				c = c + 32;
			}
			s.push_back(c);
		}
		else {
			if (!s.empty()) {
				root = word_insert(s, root);
				s.clear();
			}			
		}
	}
	if (!s.empty()) {
		root = word_insert(s, root);
		s.clear();
	}
	
	printf("%s %d\n", (root->w).c_str(), root->count);

	system("pause");
	return 0;
}