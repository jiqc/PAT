#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int getswap(vector<int> &num) {
	int count = 0;
	int temp1 = 0;
	int temp2 = num[temp1];
	num[0] = 0;

	while (temp2 != num[temp2]) {
		temp1 = num[temp2];
		num[temp2] = temp2;
		temp2 = temp1;
		count++;
	}

	return count;
}

int get(vector<int> &num) {
	int res = 0;

	for (unsigned int i = 0; i < num.size(); i++) {
		if (num[i] != i) {
			if (i != 0) {
				swap(num[0], num[i]);
				res++;
			}
			res += getswap(num);
		}
	}
	return res;
}

int main() {
	int N;
	vector<int> num;

	scanf_s("%d", &N);
	num.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num[i]);
	}
	printf("%d\n", get(num));

	system("pause");
	return 0;
}

