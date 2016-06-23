#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N;
	double f;
	double sum;

	sum = 0;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf_s("%lf", &f);
		sum = sum + f*(N - i)*(i + 1);
	}

	printf("%.2f\n", sum);

	system("pause");
	return 0;
}