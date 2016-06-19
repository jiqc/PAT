#include<cstdio>
#include<algorithm>
using namespace std;

void getc(int n, int * c) {
	c[0] = n % 10;
	n = n / 10;
	c[1] = n % 10;
	n = n / 10;
	c[2] = n % 10;
	n = n / 10;
	c[3] = n;
}

int getn(int *c) {
	return 1000 * c[3] + 100 * c[2] + 10 * c[1] + c[0];
}

bool sm(int A, int B) {
	return A > B;
}

int main() {
	int num[4];
	int n;
	int b, s;

	scanf_s("%d", &n);

	if (n == 6174) {
		printf("7641 - 1467 = 6174\n");
	}

	while (n != 0 && n != 6174) {
		getc(n, num);
		sort(num, num + 4, sm);
		s = getn(num);
		sort(num, num + 4);
		b = getn(num);
		n = b - s;
		printf("%04d - %04d = %04d\n", b, s, n);
	}

	system("pause");
	return 0;
}