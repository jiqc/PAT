#include<cstdio>
#include<stdlib.h>
using namespace std;

int main() {
	int N;
	int cur_floor,pre_floor,dif_floor;
	int sum;

	pre_floor = 0;
	sum = 0;

	scanf_s("%d", &N);
	while (N > 0) {
		scanf_s("%d", &cur_floor);
		dif_floor = cur_floor - pre_floor;
		if (dif_floor > 0) {
			sum = sum + 6 * dif_floor + 5;
		}
		else {
			sum = sum - 4 * dif_floor + 5;
		}
		pre_floor = cur_floor;
		N--;
	}

	printf("%d\n", sum);

	system("pause");
	return 0;
}