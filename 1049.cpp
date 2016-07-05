#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> recordbit;
	recordbit.resize(10);
	int t = 1;
	for (int i = 0; i < 10; i++) {
		recordbit[i] = t*(i+1);
		t *= 10;
	}

	int N;	
	int sum = 0;
	int temp;
	int m;
	int i;
	int dec;
	cin >> N;
	temp = N;
	i = 0;
	dec = 1;
	m = (temp % (dec*10))/dec;	
	if (m >= 1) {
		sum++;
	}
	temp = temp - m*dec;
	dec *= 10;
	while (temp > 0) {
		m = (temp % (dec * 10)) / dec;
		if (m > 1) {
			sum += dec + m*recordbit[i];
		}
		else {
			if (m == 1) {
				sum += N - temp + 1 + recordbit[i];
			}
		}
		temp = temp - m*dec;
		dec *= 10;
		i++;
	}
	
	cout << sum << endl;

	system("pause");
	return 0;
}