#include<cstdio>
#include<string>
#include<cstring>
using namespace std;

int main() {
	char A[10000];
	bool ascii[128] = { 0 };

	char c;
	int i = 0;
	c = getchar();
	while (c != '\n') {
		A[i] = c;
		i++;
		c = getchar();
	}
	A[i] = '\n';

	c = getchar();
	while (c != '\n') {
		ascii[c] = true;
		c = getchar();
	}

	i = 0;
	while (A[i] != '\n') {
		if (!ascii[A[i]]) {
			putchar(A[i]);
		}		
		i++;
	}
	printf("\n");

	system("pause");
	return 0;
}