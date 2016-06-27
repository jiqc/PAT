#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

struct student {
	int studentID;
	int cscore;
	int mscore;
	int escore;
	int ascore;
	int crank;
	int mrank;
	int erank;
	int arank;
};

bool bigger_cs(const student &A, const student &B) {
	return A.cscore > B.cscore;
}

bool bigger_mth(const student &A, const student &B) {
	return A.mscore > B.mscore;
}

bool bigger_eg(const student &A, const student &B) {
	return A.escore > B.escore;
}

bool bigger_av(const student &A, const student &B) {
	return A.ascore > B.ascore;
}

bool less_id(const student &A, const student &B) {
	return A.studentID < B.studentID;
}

int binary_find(const student *list, const int ID, const int N) {
	int front, end, mid;

	front = 0;
	end = N - 1;

	while (front <= end) {
		mid = (front + end) / 2;
		if (list[mid].studentID < ID) {
			front = mid + 1;
		}
		else {
			if (list[mid].studentID > ID) {
				end = mid - 1;
			}
			else {
				return mid;
			}
		}
	}

	return -1;
}

int main() {
	int N, M, n;
	int ID;
	int cscore, mscore, escore;
	int tempscore, temprank;
	char classname;

	cin >> N >> M;
	student * list = new student[N];
	for (int i = 0; i < N; i++) {
		cin >> ID >> cscore >> mscore >> escore;
		list[i].studentID = ID;
		list[i].cscore = cscore;
		list[i].mscore = mscore;
		list[i].escore = escore;
		list[i].ascore = cscore + escore + mscore;
	}

	sort(list, list + N, bigger_cs);
	tempscore = 0; 
	temprank = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].cscore == tempscore) {
			list[i].crank = temprank;
			temprank++;
		}
		else {
			temprank++;
			list[i].crank = temprank;
			tempscore = list[i].cscore;					
		}
	}
	sort(list, list + N, bigger_mth);
	tempscore = 0;
	temprank = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].mscore == tempscore) {
			list[i].mrank = temprank;
			temprank++;
		}
		else {
			temprank++;
			list[i].mrank = temprank;
			tempscore = list[i].mscore;
		}
	}
	sort(list, list + N, bigger_eg);
	tempscore = 0;
	temprank = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].escore == tempscore) {
			list[i].erank = temprank;
			temprank++;
		}
		else {
			temprank++;
			list[i].erank = temprank;
			tempscore = list[i].escore;
		}
	}
	sort(list, list + N, bigger_av);
	tempscore = 0;
	temprank = 0;
	for (int i = 0; i < N; i++) {
		if (list[i].ascore == tempscore) {
			list[i].arank = temprank;
			temprank++;
		}
		else {
			temprank++;
			list[i].arank = temprank;
			tempscore = list[i].ascore;
		}
	}

	sort(list, list + N, less_id);
	for (int i = 0; i < M; i++) {
		cin >> ID;
		n = binary_find(list, ID, N);
		if (n == -1) {
			printf("N/A\n");
		}
		else {
			temprank = list[n].arank;
			classname = 'A';
			if (list[n].crank < temprank) {
				temprank = list[n].crank;
				classname = 'C';
			}
			if (list[n].mrank < temprank) {
				temprank = list[n].mrank;
				classname = 'M';
			}
			if (list[n].erank < temprank) {
				temprank = list[n].erank;
				classname = 'E';
			}
			printf("%d %c\n", temprank, classname);
		}
	}

	delete[] list;
	system("pause");
	return 0;
}