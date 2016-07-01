#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

struct account {
	string name;
	char pw[11];
	bool modified;
};

vector<account> accountlist;

int main() {
	int N, M;

	cin >> N;
	accountlist.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> accountlist[i].name >> accountlist[i].pw;
	}

	M = 0;
	bool modified ;
	for (int i = 0; i < N; i++) {
		modified = false;
		for (int j = 0; j < 10; j++) {
			switch (accountlist[i].pw[j]) {
			case'1':
				accountlist[i].pw[j] = '@';
				modified = true;
				break;
			case'l':
				accountlist[i].pw[j] = 'L';
				modified = true;
				break;
			case'O':
				accountlist[i].pw[j] = 'o';
				modified = true;
				break;
			case'0':
				accountlist[i].pw[j] = '%';
				modified = true;
				break;
			}
		}
		if (modified) {
			accountlist[i].modified = true;
			M++;
		}
	}

	if (M) {
		cout << M << endl;
		for (int i = 0; i < N; i++) {
			if (accountlist[i].modified) {
				cout << accountlist[i].name << ' ' << accountlist[i].pw << endl;
			}
		}
	}
	else {
		if (N == 1) {
			cout << "There is 1 account and no account is modified" << endl;
		}
		else {
			cout << "There are " << N << " accounts and no account is modified" << endl;
		}
	}

	system("pause");
	return 0;
}