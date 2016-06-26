#include<cstdio>
#include<stdlib.h>
using namespace std;

int main() {
	int quantity;
	int num;
	int maxsum, thissum;
	int min, max;
	int thismin;
	bool neg;
	int firstnum;
	int thisminnum=0;

	maxsum = 0;
	thissum = 0;
	min = 0;
	max = 0;
	thismin = 0;
	neg = true;

	scanf_s("%d", &quantity);
	for (int i = 0; i < quantity;i++){
		scanf_s("%d", &num);
		if (i == thisminnum) {
			thismin = num;
		}
		if (num >= 0) {
			neg = false;
		}
		if (i == 0) {
			firstnum = num;
		}
		thissum += num;
		if (thissum > maxsum) {
			maxsum = thissum;
			max = num;
			min = thismin;
		}
		else {
			if (thissum < 0) {
				thissum = 0;
				thisminnum = i+1;
			}
		}
	}

	if (neg) {
		printf("0 %d %d\n", firstnum, num);
	}
	else {
		printf("%d %d %d\n", maxsum, min, max);
	}

	system("pause");
	return 0;
}