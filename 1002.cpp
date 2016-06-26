#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct item {
	//int number;
	int exponent;
	float coefficient;
	item *next;
}item, *polynomial;

void construct(int length, polynomial &p) {
	p = new item;
	item *pre = p;
	while (length > 0) {
		item *temp = new item;
		scanf_s("%d%f", &temp->exponent, &temp->coefficient);
		temp->next = NULL;
		pre->next = temp;
		pre = temp;
		length--;
	}
}

int merge(polynomial &A, polynomial &B) {
	int length;
	item *temp;
	item *p1 = A->next;
	item *p2 = B->next;
	item *pre = A;
	delete B;

	length = 0;
	while (p1 != NULL && p2 != NULL) {
		if (p1->exponent > p2->exponent) {
			length++;
			pre->next = p1;
			pre = pre->next;
			p1 = p1->next;
		}
		else if (p1->exponent < p2->exponent) {
			length++;
			pre->next = p2;
			pre = pre->next;
			p2 = p2->next;
		}
		else {
			p1->coefficient += p2->coefficient;
			temp = p2;
			p2 = p2->next;
			delete temp;
			if (p1->coefficient != 0) {
				length++;
				pre->next = p1;
				pre = pre->next;
				p1 = p1->next;
			}
			else {
				temp = p1;
				p1 = p1->next;
				delete temp;
			}
		}
	}
	pre->next = NULL;
	if (p1 != NULL) {
		pre->next = p1;
		while (p1 != NULL) {
			length++;
			p1 = p1->next;
		}
	}
	if (p2 != NULL) {
		pre->next = p2;
		while (p2 != NULL) {
			length++;
			p2 = p2->next;
		}
	}

	return length;
}

int main() {
	polynomial p1, p2;
	int length;
	item *temp;

	scanf_s("%d", &length);
	construct(length, p1);
	scanf_s("%d", &length);
	construct(length, p2);

	length = merge(p1, p2);

	temp = p1->next;
	delete p1;
	if (length == 0) {
		printf("0");
	}
	else {
		printf("%d", length);
		while (temp != NULL) {
			printf(" %d %.1f", temp->exponent, temp->coefficient);
			item *pre = temp;
			temp = temp->next;
			delete pre;
		}
	}
	printf("\n");
	
	system("pause");
	return 0;
}