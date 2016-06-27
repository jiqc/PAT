#include<cstdio>
#include<stdlib.h>
using namespace std;

int main() {
	float w, t, l;
	float profit=1;
	char games[3];

	for (int i = 0; i < 3; i++) {
		scanf_s("%f %f %f", &w, &t, &l);
		if (w > t) {
			if (w > l) {
				games[i] = 'W';
				profit *= w;
			}
			else {
				games[i] = 'L';
				profit *= l;
			}
		}
		else {
			if (t > l) {
				games[i] = 'T';
				profit *= t;
			}
			else {
				games[i] = 'L';
				profit *= l;
			}
		}
	}

	profit = (profit * 0.65 - 1) * 2;
	printf("%c %c %c %.2f\n", games[0], games[1], games[2], profit);

	system("pause");
	return 0;
}