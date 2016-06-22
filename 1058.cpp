#include<cstdio>
#include<stdlib.h>
using namespace std;

int main(){
	int a[3], b[3];
	int sum[3];
	int carry;

	scanf_s("%d.%d.%d", &a[2], &a[1], &a[0]);
	scanf_s("%d.%d.%d", &b[2], &b[1], &b[0]);

	sum[0] = (a[0] + b[0]) % 29;
	carry = (a[0] + b[0]) / 29;
	sum[1] = (a[1] + b[1] + carry) % 17;
	carry = (a[1] + b[1] + carry) / 17;;
	sum[2] = (a[2] + b[2] + carry) % 10000001;


	printf("%d.%d.%d\n", sum[2], sum[1], sum[0]);

	system("pause");
	return 0;
}