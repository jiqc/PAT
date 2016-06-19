#include<iostream>
#include<vector>
#include<string>
using namespace std;

string getKuchiguse(string A, string B) {
	string K;
	int len;
	int lena;
	int lenb;

	lena = A.size();
	lenb = B.size();
	len = A.size() < B.size() ? A.size() : B.size();
	for (int i = 1; i < len+1; i++) {
		if (A.substr(lena - i) == B.substr(lenb - i)) {
			K = A.substr(lena - i);
		}
		else {
			break;
		}
	}
	return K;
}

int main() {
	int N;
	bool find;
	vector<string> sentences;
	string Kuchiguse;

	cin >> N;
	sentences.resize(N);
	cin.get();
	for (int i = 0; i < N; i++) {
		getline(cin, sentences[i]);
	}


	find = true;
	Kuchiguse = sentences[0];
	for (int i = 1; i < N; i++) {
		Kuchiguse = getKuchiguse(Kuchiguse, sentences[i]);
		if (Kuchiguse.empty()) {
			find = false;
			break;
		}
	}

	if (!find) {
		cout << "nai" << endl;
	}
	else {
		cout << Kuchiguse << endl;
	}

	system("pause");
	return 0;
}