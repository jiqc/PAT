#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	vector<int> numlist;
	int sum;

	scanf_s("%d", &N);
	numlist.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &numlist[i]);
	}

	sort(numlist.begin(), numlist.end());

	if (N % 2 == 0) {
		printf("0 ");
		sum = 0;
		for (int i = 0; i < N / 2; i++) {
			sum = sum + numlist[i + N / 2] - numlist[i];
		}	
		printf("%d\n", sum);
	}
	else {
		printf("1 ");
		sum = 0;
		for (int i = 0; i < N / 2; i++) {
			sum = sum + numlist[i + N / 2] - numlist[i];
		}
		sum += numlist[N - 1];
		printf("%d\n", sum);
	}

	system("pause");
	return 0;
}