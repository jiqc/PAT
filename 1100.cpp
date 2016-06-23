#include<iostream>
#include<string>
using namespace std;

string lows[13] = { "tret" ,"jan", "feb","mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string high[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

void pmar(string A) {
	int index;

	for (index = 0; index < 12; index++) {
		if (A.substr(0,3) == high[index]) {
			break;
		}
	}

	if (index == 12) {
		for (index = 0; index < 13; index++) {
			if (A == lows[index]) {
				cout << index << endl;
				break;
			}
		}
	}
	else {
		if (A.size() > 5) {
            for (int i = 0; i< 13; i++) {
			    if (A.substr(4,7) == lows[i]) {
				    cout << (index+1)*13 + i << endl;
				    break;
			    }
		    }
		}
		else {
			cout << (index + 1) * 13 << endl;
		}		
	}
}

void pear(string A) {
	int num;
	int h, l;

	num = 0;
	for (int i = 0; i < (int)A.size(); i++) {
		num = num * 10 + A[i] - '0';
	}

	l = num % 13;
	h = num / 13;

	if (h != 0 && l != 0) {
		cout << high[h - 1] << ' ' << lows[l] << endl;
	}
	else {
		if (h != 0 && l == 0) {
			cout << high[h - 1] << endl;
		}
		else {
			cout<< lows[l] << endl;
		}
	}
}

int main() {
	int N;
	string num;

	cin >> N;
	cin.get();
	for (int i = 0; i < N; i++) {
		getline(cin,num);
		if (num[0] > '9') {
			pmar(num);
		}
		else {
			pear(num);
		}
	}

	system("pause");
	return 0;
}