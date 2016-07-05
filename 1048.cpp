#include<cstdio>
#include<vector>
using namespace std;

int coins[100003] = { 0 };

int main() {
	int N, M;
	bool find;

	int num;
	scanf_s("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num);
		coins[num]++;
	}

	find = false;
	for (int i = 1; i < M / 2 + 1; i++) {
		if (coins[i] > 0) {
			coins[i]--;
			num = M - i;
			if (coins[num] > 0) {
				printf("%d %d\n", i, num);
				find = true;
				break;
			}
		}
	}

	if (!find) {
		printf("No Solution\n");
	}

	system("pause");

	return 0;
}