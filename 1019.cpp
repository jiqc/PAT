#include<cstdio>
#include<stdlib.h>
using namespace std;

int main() {
	int N, b;
	int a[32];
	int k;
	bool flag;

	scanf_s("%d %d", &N, &b);
	if (N == 0) {
		printf("Yes\n0\n");
	}
	else {
        k = 0;
	    while (N != 0) {
		    a[k] = N % b;
		    N = N / b;
		    k++;
	    }
		flag = true;
		for (int i = 0; i < k / 2; i++) {
			if (a[i] != a[k - 1 - i]) {
				flag = false;
			}
		}
		if (flag) {
			printf("Yes\n");
		}
		else {
			printf("No\n");
		}
		for (int i = k; i > 1; i--) {
			printf("%d ", a[i - 1]);
		}
		printf("%d\n", a[0]);
	}
	
	system("pause");
	return 0;
}