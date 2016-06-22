#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	int N;
	int max;
	int tmax;
	int pd;
	int k;
	vector<int> factors;
	vector<int> res;

	cin >> N;
	max = 0;
	for (int i = 2; i <= (int)sqrt(N); i++) {
		k = 0;
		factors.clear();
		pd = i+k;
		tmax = 0;
		while (0 == N % pd ) {
			factors.push_back(i + k);
			tmax++;
			k++;
			if (N / pd <i+k) {
				break;
			}
			pd = pd*(i + k);			
		}
		if (tmax > max) {
			max = tmax;
			res = factors;
		}
	}

	if (max == 0) {
		max++;
		res.push_back(N);
	}

	cout << max << endl;
	cout << res[0];
	for (int i = 1; i < (int)res.size(); i++) {
		cout << '*' << res[i];
	}
	cout << endl;

	system("pause");
	return 0;
}