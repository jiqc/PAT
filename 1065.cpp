/*
#include<iostream>
#include<string>
using namespace std;

class bignumber {
private:
	bool sign;
	int numberstore[3];
public:
	bignumber() {
		sign = true;
		numberstore[0] = 0;
		numberstore[1] = 0;
		numberstore[2] = 0;
	}
	bignumber(const string A) {
		int num[72] = { 0 };
		int count = (int)A.size();
		if (A[0] == '-') {
			sign = false;
			for (int i = 0; i < count-1; i++) {
				num[i] = A[count - i - 1]-'0';
			}
		}
		else {
			sign = true;
			for (int i = 0; i < count; i++) {
				num[i] = A[count - i - 1]-'0';
			}
		}
		for (int i = 0; i < 3; i++) {
			numberstore[i] = 0;
			for (int j = 0; j < 24; j++) {
				numberstore[i] = numberstore[i] * 10 + num[i * 24 + 23 - j];
			}
		}
	}
	bool abscampare

};
*/

#include<iostream>
using namespace std;

int main() {
	int T;
	long long int A, B, C;
	long long int sum;

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> A >> B >> C;
		sum = A + B;
		cout << "Case #" << i + 1 << ": ";
		if (A > 0 && B > 0 && sum <= 0) {
			cout << "true" << endl;
			continue;
		}
		if (A < 0 && B < 0 && sum >= 0) {
			cout << "false" << endl;
			continue;
		}
		if (sum > C) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}

	system("pause");
	return 0;
}