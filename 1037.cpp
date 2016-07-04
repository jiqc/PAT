#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int NC, NP;
	vector<int> C, P;
	long long int sum = 0;

	int num;
	cin >> NC;
	for (int i = 0; i < NC; i++) {
		scanf_s("%d", &num);
		C.push_back(num);
	}
	cin >> NP;
	for (int i = 0; i < NP; i++) {
		scanf_s("%d", &num);
		P.push_back(num);
	}

	sort(C.begin(), C.end());
	sort(P.begin(), P.end());

	int tc, tp;
	tc = NC - 1;
	tp = NP - 1;
	while (C[tc]>0 && P[tp]>0) {
		sum = sum + C[tc] * P[tp];
		tc--;
		tp--;
	}

	tc = 0;
	tp = 0;
	while (C[tc]<0 && P[tp]<0) {
		sum = sum + C[tc] * P[tp];
		tc++;
		tp++;
	}

	cout << sum << endl;

	system("pause");
	return 0;
}