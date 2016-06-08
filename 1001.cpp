#include <cstdio>
#include <cstdlib>
using namespace std;

int main() {
	int a, b, sum;
	int output[3];

	scanf_s("%d %d", &a, &b);

	sum = a + b;

	if (sum == 0) {
		printf("0");
	}
	else {
		if (sum < 0) {
			printf("-");
			sum = -sum;
		}
		int i = 2;
		while (sum != 0) {
			output[i] = sum % 1000;
			sum = sum / 1000;
			i--;
		}
		i++;
		printf("%d", output[i]);
		i++;
		while (i < 3) {
			printf(",%03d", output[i]);
			i++;
		}
	}
	printf("\n");
	
	system("pause");
	return 0;
}
