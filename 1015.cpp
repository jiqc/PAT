#include <cstdio>
#include <stdlib.h>
#include <cmath>
using namespace std;

bool isprime(int num) {
	int i;
	int sq;
	if (num > 1) {
		sq = (int)sqrt((double)num);
	    for ( i = 2; i <= sq; i++) {
		    if (num % i == 0)break;
	    }
	    if (i > sq)return 1;
	}
	
	return 0;
}

int reverse(int num, int radix) {
	int re_num = 0;
	while (num > 0) {
		re_num = re_num*radix + num%radix;
		num = num / radix;
	}
	return re_num;
}

int main() {
	int prime, radix;
	int num;

	scanf_s("%d", &num);
	while (num > 0) {
		prime = num;
		scanf_s("%d", &radix);
		if (isprime(prime)) {
			num = reverse(prime, radix);
			if (isprime(num)) {
				printf("Yes\n");
			}
			else {
				printf("No\n");
			}
		}
		else {
			printf("No\n");
		}
		scanf_s("%d", &num);
	}

	system("pause");
	return 0;
}