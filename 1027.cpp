#include<cstdio>
#include<stdlib.h>
using namespace std;

char ab[13] = { '0','1','2','3','4','5','6','7','8','9','A','B','C' };

int main() {
	int num[3];

	scanf_s("%d %d %d", &num[0], &num[1], &num[2]);
	printf("#");
	int h, d;
	for (int i = 0; i < 3; i++) {
		d = num[i] % 13;
		h = num[i] / 13;
		printf("%c%c", ab[h], ab[d]);
	}
	printf("\n");

	system("pause");
	return 0;
}