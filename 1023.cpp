#include<iostream>
using namespace std;

int numdenum[10] = { 0,0,0,0,0,0,0,0,0,0 };
char numd[20];
int k;

int read(int i) {
	char c;
	int carry;
	int num;
	int sum;

	k = i;
	cin.get(c);
	if (c < '0' || c > '9') {
		return 0;
	}
	else {
		num = c - '0';
		numdenum[num]++;
		carry = read(i+1);
		sum = num * 2 + carry;
		num = sum % 10;
		numd[i] = '0' + num;
		numdenum[num]--;
		carry = sum / 10;
	}

	return carry;
}

int main() {
	int ca;

	ca = read(0);

	if (ca) {
		cout << "No\n1";
	}
	else {
		int i;
		for (i = 0; i < 10; i++) {
			if (numdenum[i])break;
		}
		if (i == 10) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	}

	for (int j = 0; j < k; j++) {
		cout << numd[j];
	}
	cout << '\n';

	system("pause");
	return 0;
}