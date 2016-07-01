#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main() {
	char phrase[81];
	int num, n1, n2;

	gets_s(phrase);
	num = strlen(phrase);
	n1 = (num+2) / 3;
	n2 = num + 2 - n1 - n1;

	for (int i = 0; i < n1-1; i++) {
		printf("%c", phrase[i]);
		for (int j = 0; j < n2 - 2; j++) {
			printf(" ");
		}
		printf("%c\n", phrase[num-1-i]);
	}
	for (int i = 0; i < n2; i++) {
		printf("%c", phrase[n1 -1 + i]);
	}
	printf("\n");

	system("pause");
	return 0;
}