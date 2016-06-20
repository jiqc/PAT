#include<iostream>
#include<vector>
#include<string>
using namespace std;

string bitname[9] = { "","Shi","Bai", "Qian","Wan","Shi","Bai","Qian","Yi"};
string numname[10] = { "ling","yi","er","san","si","wu","liu","qi" ,"ba","jiu"};

int main() {
	int n;
	int nb[9] = { 0 };
	vector<string> read;
	bool front;
	bool zero;

	cin >> n;
	front = false;
	zero = false;
	if (n < 0) {
		read.push_back("Fu");
		n = -n;
	}
	int i = 0;
	while (n > 0) {
		nb[i] = n % 10;
		n = n / 10;
		i++;
	}

	for (int i = 8; i >= 0; i--) {
		if (nb[i] == 0) {
			zero = true;
			if (front && i == 4) {
				read.push_back(bitname[i]);
				zero = false;
			}
		}
		else {
			if (front && zero) {
				read.push_back(numname[0]);
			}
			read.push_back(numname[nb[i]]);
			if (i) {
				read.push_back(bitname[i]);
			}
			front = true;
			zero = false;
		}
	}

	if (read.empty()) {
		cout << "ling" << endl;
	}
	else {
		cout << read[0];
		for (int i = 1; i < (int)read.size(); i++) {
			cout << ' ' << read[i];
		}
		cout << endl;
	}
	
	system("pause");
	return 0;
}