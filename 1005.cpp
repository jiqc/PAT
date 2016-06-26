#include<cstdio>
#include<cstring>
#include<string>
using namespace std;

string engnum[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printeng(int num) {
	
	if (num == 0) {
		return;
	}
	printeng(num / 10);
	if (num / 10 != 0) {
		printf(" ");
	}
	printf("%s", engnum[num % 10].c_str());
}

int main() {
	char numchar;
	int num;
	int sum;

	sum = 0;
	numchar = getchar();
	while (numchar != '\n' && numchar != EOF) {
		num = numchar - '0';
		sum += num;
		numchar = getchar();
	}
	
	if (sum == 0) {
		printf("zero\n");
	}
	else {
        printeng(sum);
	    printf("\n");
	}
	
	system("pause");
	return 0;
}