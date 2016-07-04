#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

bool less_than_merge(const string & A,const string & B) {
	if (A.size() < B.size() && A == B.substr(0, A.size())) {
		return A + B < B + A;
	}
	if (B.size() < A.size() && B == A.substr(0, B.size())) {
		return A + B < B + A;
	}
	return A < B;
}

int main() {
    vector<string> numbergroup;
    int N;
	bool started = false;

	cin >> N;
	numbergroup.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> numbergroup[i];
	}
	
	sort(numbergroup.begin(), numbergroup.end(), less_than_merge);

	for (int i = 0; i < N; i++) {
		if (started) {
			cout << numbergroup[i];
		}
		else {
			int j = 0;
			while (numbergroup[i][j] == '0') {
				j++;
			}
			if (j != numbergroup[i].size()) {
				started = true;
				cout << numbergroup[i].substr(j, numbergroup[i].size());
			}			
		}
	}
	if (!started) {
		cout << '0';
	}
	cout << endl;

	system("pause");
	return 0;
}