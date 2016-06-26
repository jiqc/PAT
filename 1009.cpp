#include<cstdio>
#include<stdlib.h>
using namespace std;

int main() {
	int X_K, Y_K;
	int exponent;

	scanf_s("%d", &X_K);
	int *X_exp = (int*)malloc(sizeof(int)*X_K);
	float *X_coe = (float*)malloc(sizeof(float)*X_K);
	for (int i = 0; i < X_K; i++) {
		scanf_s("%d %f", (X_exp + i), (X_coe + i));
	}
	scanf_s("%d", &Y_K);
	int *Y_exp = (int*)malloc(sizeof(int)*Y_K);
	float *Y_coe = (float*)malloc(sizeof(float)*Y_K);
	for (int i = 0; i < Y_K; i++) {
		scanf_s("%d %f", (Y_exp + i), (Y_coe + i));
	}
	int P_K = X_exp[0] + Y_exp[0];
	float *P_coe = (float*)malloc(sizeof(float)*(P_K+1));
	for (int i = 0; i <= P_K; i++) {
		P_coe[i] = 0;
	}

	for (int i = 0; i < X_K; i++) {
		for (int j = 0; j < Y_K; j++) {
			exponent = X_exp[i] + Y_exp[j];
			P_coe[exponent] += X_coe[i] * Y_coe[j];
		}
	}

	int P = 0;
	for (int i = 0; i <= P_K; i++) {
		if (P_coe[i] != 0) {
			P++;
		}
	}
	printf("%d", P);
	for (int i = P_K; i >= 0; i--) {
		if (P_coe[i] != 0) {
			printf(" %d %.1f", i, P_coe[i]);
		}
	}
	printf("\n");

	free(P_coe);
	free(Y_coe);
	free(Y_exp);
	free(X_coe);
	free(X_exp);

	system("pause");
	return 0;
}