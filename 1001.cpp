#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int main() {
	int a, b, sum;
	vector<int> output;

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
		int i = 0;
		while (sum != 0) {
			output.push_back(sum % 1000);
			sum = sum / 1000;
			i++;
		}
		i--;
		printf("%d", output[i]);
		i--;
		while (i >=0) {
			printf(",%03d", output[i]);
			i--;
		}
	}
	printf("\n");
	
	system("pause");
	return 0;
}
