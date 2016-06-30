#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
using namespace std;

struct student {
	int ID;
	char name[9];
	int grade;
};

bool less_than_ID(student &A, student &B) {
	return A.ID < B.ID;
}

bool less_than_name(student &A, student &B) {
	int c = strcmp(A.name, B.name);
	if (c == 0) {
		return A.ID < B.ID;
	}
	else {
		return c < 0;
	}
}

bool less_than_grade(student &A, student &B) {
	if (A.grade == B.grade) {
		return A.ID < B.ID;
	}
	else {
		return A.grade < B.grade;
	}
}

int main() {
	int N, C;

	scanf_s("%d %d",&N,&C);
	student * group = (student*)malloc(sizeof(student)*N);
	for(int i = 0; i < N; i++) {
		scanf_s("%d %s %d", &group[i].ID, group[i].name, &group[i].grade);
	}

	switch (C) {
	case 1:
		sort(group, group + N, less_than_ID);
		break;
	case 2:
		sort(group, group + N, less_than_name);
		break;
	case 3:
		sort(group, group + N, less_than_grade);
	}

	for (int i = 0; i < N; i++) {		
		printf("%06d %s %d\n", group[i].ID, group[i].name,group[i].grade);
	}

	free(group);
	system("pause");
	return 0;
}