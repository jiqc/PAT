#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool find(vector<char> str, char c) {
	for (int i = 0; i<(int)str.size(); i++) {
		if (c == str[i]) {
			return true;
		}
	}
	return false;
}

int main() {
	string original, typedout;
	int po, pt;
	int so, st;
	vector<char> bk;

	cin >> original >> typedout;

	so = (int)original.size();
	st = (int)typedout.size();
	po = pt = 0;

	while (po < so) {
		if (original[po] != typedout[pt]) {
			if (original[po] >= 'a' && original[po] <= 'z') {
				if (!find(bk, original[po]-32)) {
					bk.push_back(original[po]-32);
				}
			}
			else {
				if (!find(bk, original[po])) {
					bk.push_back(original[po]);
				}
			}
			po++;
		}
		else {
			po++;
			pt++;
		}
	}

	for (int i = 0; i<(int)bk.size(); i++) {
		printf("%c", bk[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}