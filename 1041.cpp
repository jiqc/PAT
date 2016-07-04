#include<cstdio>
#include<vector>
#include<stdlib.h>
using namespace std;

int main() {
	vector<int> records;
	int N;
	vector<int> num;

	records.resize(10001);

	scanf_s("%d", &N);
	num.resize(N);

	for (int i = 0; i < N; i++) {
		scanf_s("%d", &num[i]);
		records[num[i]] ++;
	}

	int index;
	for ( index = 0; index < N; index++) {
		if (records[num[index]]==1) {
			break;
		}
	}

	if (index == N) {
		printf("None\n");
	}
	else {
		printf("%d\n", num[index]);
	}


	system("pause");
	return 0;	
}