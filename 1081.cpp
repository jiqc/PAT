#include<cstdio>
#include<vector>
using namespace std;

long long int getgcd(long long a, long long b) {
	if (a < 0) {
		a = -a;
	}
	while ((a %= b) && (b %= a));
	return a + b;
}

int main() {
	int N;
	long long int gcd;
	long long int intg;
	long long int numerator_sum, denominator_sum;
	long long int numerator_in, denominator_in;

	scanf_s("%d", &N);
	scanf_s("%lld/%lld", &numerator_sum, &denominator_sum);

	for (int i = 1; i < N; i++) {
		scanf_s("%lld/%lld", &numerator_in, &denominator_in);
		numerator_sum = numerator_sum*denominator_in + numerator_in*denominator_sum;
		denominator_sum = denominator_sum*denominator_in;
		gcd = getgcd(numerator_sum, denominator_sum);
		numerator_sum = numerator_sum / gcd;
		denominator_sum = denominator_sum / gcd;
	}

	intg = numerator_sum / denominator_sum;
	if (numerator_sum < 0) {
		numerator_sum = -numerator_sum;
	}
	numerator_sum = numerator_sum % denominator_sum;

	if (intg != 0) {
		printf("%lld", intg);
		if (numerator_sum != 0) {
			printf(" %lld/%lld\n", numerator_sum, denominator_sum);
		}
		else {
			printf("\n");
		}
	}
	else {
		if (numerator_sum != 0) {
		    printf("%lld/%lld\n", numerator_sum, denominator_sum);
		}
		else {
			printf("0\n");
		}
	}
	
	system("pause");
	return 0;

}