#include<iostream>
#include<vector>
using namespace std;

vector<int> num, r_num;

void input() {
	char c;
	
	cin.get(c);
	while (c != ' ') {
        num.push_back(c - '0');
		cin.get(c);
	}	
}

void reverse() {
	r_num.clear();
	for (unsigned int i = num.size(); i > 0; i--) {
		r_num.push_back(num[i - 1]);
	}
}

void add() {
	int carry = 0;
	for (unsigned int i = 0; i < num.size(); i++) {
		num[i] = num[i] + r_num[i] + carry;
		carry = num[i] / 10;
		num[i] = num[i] % 10;
	}
	if (carry) {
		num.push_back(1);
	}
}

bool palindromic() {
	reverse();
	for (unsigned int i = 0; i < num.size(); i++) {
		if (num[i] != r_num[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	int K;
	char c;

	input();
	cin >> K;

	int i = 0;
	while(i<=K){
		if (palindromic()) {
			for (unsigned int j = num.size(); j > 0; j--) {
				c = '0' + num[j - 1];
				cout << c;
			}
			cout << "\n" << i << "\n";
			break;
		}
		else {
			if (i != K) {
				add();
			}
			i++;
		}
	}

	if (i == K + 1) {
		for (unsigned int j = num.size(); j > 0; j--) {
			c = '0' + num[j - 1];
			cout << c;
		}
		cout << "\n" << K << "\n";
	}

	system("pause");
	return 0;
}