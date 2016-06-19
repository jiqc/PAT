#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, M;
vector<vector<int> > score;
vector<int> fullmark;

bool camp(const vector<int> &A, const vector<int> &B) {
	if (A[K + 3] != B[K + 3]) {
		return A[K + 3] > B[K + 3];
	}
	else {
		if (A[K + 1] != B[K + 1]) {
			return A[K + 1] > B[K + 1];
		}
		else {
			return A[0] < B[0];
		}
	}
}

int main() {

	scanf_s("%d %d %d",&N,&K,&M);

	fullmark.resize(K + 1);
	for (int i = 1; i < K + 1; i++) {
		scanf_s("%d", &fullmark[i]);
	}

	score.resize(N + 1);
	for (int i = 0; i < N + 1; i++) {
		score[i].resize(K + 4,-2);//0:id; k+1:perfectly solved problem id; k+2:can print;k+3: sum
		score[i][0] = i;
		score[i][K + 1] = 0;
	}

	int user_id, problem_id, partial_score_obtained;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d %d", &user_id, &problem_id, &partial_score_obtained);

		if (score[user_id][problem_id] < partial_score_obtained) {
			score[user_id][problem_id] = partial_score_obtained;

			if (partial_score_obtained == fullmark[problem_id]) {
				score[user_id][K + 1]++;
			}			
	    }
	}

	int sum;
	for (int i = 1; i < N + 1; i++) {
		sum = 0;
		for (int j = 1; j < K + 1; j++) {
			if (score[i][j] >= 0) {
				sum += score[i][j];
				score[i][K + 2] = 1;
			}
		}
		score[i][K + 3] = sum;
	}

	sort(score.begin()+1, score.end(), camp);

	int plrank, allrank, max;
	plrank = 1;
	allrank = 0;
	max = score[1][K+3];
	for (int i = 1; i < N + 1; i++) {
		if (score[i][K + 2]>0) {
			allrank++;
			if (score[i][K + 3] == max) {
				printf("%d ", plrank);
			}
			else {
				printf("%d ", allrank);
				max = score[i][K + 3];
				plrank = allrank;
			}
			printf("%05d %d", score[i][0], score[i][K + 3]);
			for (int j = 1; j < K + 1; j++) {
				if (score[i][j] == -1) {
					printf(" 0");
				}
				else {
					if (score[i][j] == -2) {
						printf(" -");
					}
					else {
					    printf(" %d", score[i][j]);
				    }
				}			
			}
			printf("\n");
		}
	}

	system("pause");
	return 0;
}