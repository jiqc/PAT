#include<cstdio>
#include<vector>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

int hashname(const char* name) {
	return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + (name[3] - '0');
}

int main() {
	int N, K;

	vector<int> student[26*26*26*10];

	scanf_s("%d %d", &N, &K);

	int CI, NI;
	char name[5];
	int studentID;

	for(int i = 0; i < K; i++) {
		scanf_s("%d %d",&CI,&NI);
		for (int j = 0; j < NI; j++) {
			scanf_s("%s",name, 5);
			studentID = hashname(name);
			student[studentID].push_back(CI);
		}
	}

	
	for (int i = 0; i < N; i++) {
		scanf_s("%s", name, 5);
		studentID = hashname(name);
		if (student[studentID].empty()) {
			printf("%s 0\n",name);
		}
		else {
			printf("%s %d", name, student[studentID].size());
			sort(student[studentID].begin(), student[studentID].end());
			for (unsigned int i=0; i<student[studentID].size();i++) {
				printf(" %d", student[studentID][i]);
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}