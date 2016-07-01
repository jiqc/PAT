#include<cstdio>
#include<iostream>
using namespace std;

struct node {
	char c;
	int next;
	int count = 0;
};

node table[100000];

int main() {
	int begin1, begin2;
	int N;

	scanf_s("%d %d %d", &begin1, &begin2, &N);

	int addr, next;
	char c;
	for (int i = 0; i < N; i++) {
		scanf_s("%d ", &addr);				
		c= getchar();
		table[addr].c = c;
		scanf_s("%d", &next);
		table[addr].next = next;
	}
	
	if (begin1 == -1 || begin2 == -1) {
		printf("-1\n");
		return 0;
	}

	int temp = begin1;
	while (temp != -1) {
		table[temp].count = 1;
		temp = table[temp].next;
	}

	temp = begin2;
	while (temp!=-1) {
		if (table[temp].count ==1) {
			break;
		}
		temp = table[temp].next;
	}

	if (temp == -1) {
		printf("-1\n");
	}
	else{
		printf("%05d\n",temp);
	}

	system("pause");
	return 0;
}