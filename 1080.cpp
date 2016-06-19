#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct student {
	int id;
	int GE;
	int GI;
	int G;
	int rank;
	vector<int> ap;
};

struct school {
	int id;
	int quota;
	vector<int> ac;
};

bool camp(const student &A, const student &B) {
	if (A.G != B.G) {
		return A.G > B.G;
	}
	else {
		return A.GE > B.GE;
	}
}

bool campid(const student &A, const student &B) {
	return A.id < B.id;
}

int main() {
	int N, M, K;
	vector<student> applicants;
	vector<school> acadimies;

	scanf_s("%d %d %d", &N, &M, &K);
	applicants.resize(N);
	acadimies.resize(M);
	for (int i = 0; i < M; i++) {
		acadimies[i].id = i;
		scanf_s("%d", &acadimies[i].quota);
	}
	for (int i = 0; i < N; i++) {
		applicants[i].id = i;
		scanf_s("%d %d", &applicants[i].GE, &applicants[i].GI);
		applicants[i].G = (applicants[i].GE + applicants[i].GI)/2;
		applicants[i].ap.resize(K);
		for (int j = 0; j < K; j++) {
			scanf_s("%d", &applicants[i].ap[j]);
		}
	}

	sort(applicants.begin(), applicants.end(), camp);

	int maxG = applicants[0].G;
	int maxGE = applicants[0].GE;
	int prank = 0;
	for (int i = 0; i < N; i++) {
		if (applicants[i].G == maxG && applicants[i].GE == maxGE) {
			applicants[i].rank = prank;
		}
		else {
			applicants[i].rank = i;
			prank = i;
			maxG = applicants[i].G;
			maxGE = applicants[i].GE;
		}
	}

	vector<int> temp;
	temp.resize(N);
	for (int i = 0; i < N; i++) {
		temp[i] = applicants[i].id;
	}
	sort(applicants.begin(), applicants.end(), campid);

	int getid;
	int tap;
	for (int i = 0; i < N; i++) {
		getid = temp[i];
		for (int j = 0; j < K; j++) {
			tap = applicants[getid].ap[j];
			if ((int)acadimies[tap].ac.size() < acadimies[tap].quota
				||( applicants[getid].rank == applicants[acadimies[tap].ac.back()].rank)) {
				acadimies[tap].ac.push_back(getid);
				break;
			}
		}
	}

	for (int i = 0; i < M; i++) {
		if (!acadimies[i].ac.empty()) {		
			sort(acadimies[i].ac.begin(), acadimies[i].ac.end());
			printf("%d", acadimies[i].ac[0]);
			for (int j = 1; j < (int)acadimies[i].ac.size(); j++) {
				printf(" %d", acadimies[i].ac[j]);
			}			
		}
		printf("\n");
	}

	system("pause");
	return 0;
}