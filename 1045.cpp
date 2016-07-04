#include<cstdio>
#include<vector>
using namespace std;
/*
struct node {
	int num;
	vector<int> next;
};
int N;
int M;
vector<int> favs;
int L;
vector<node> stripe;
vector<bool> started;

int maxlenght=0;

void DFS(int index,int deep) {
	started[index] = true;
	deep++;
	if (stripe[index].next.empty()) {
		if (deep > maxlenght) {
			maxlenght = deep;
		}
	}
	else {
		for (unsigned int i = 0; i < stripe[index].next.size(); i++) {
			DFS(stripe[index].next[i], deep);
		}
	}
}

int main() {
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	favs.resize(N+1);
	int tempnum;
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &tempnum);
		favs[tempnum] = i + 1;
	}
	scanf_s("%d", &L);
	node temp;
	for (int i = 0; i < L; i++) {
		scanf_s("%d", &temp.num);
		if (favs[temp.num] == 0) {
			continue;
		}
		else {
			int lth = stripe.size();
			for (int j = lth; j > 0; j--) {
				if (favs[temp.num] > favs[stripe[j-1].num]) {
					stripe[j-1].next.push_back(lth);
					break;
				}
			}
			for (int j = lth; j > 0; j--) {
				if (favs[temp.num] == favs[stripe[j-1].num]) {
					stripe[j-1].next.push_back(lth);
					break;
				}
			}
		}
		stripe.push_back(temp);
	}

	int lth = stripe.size();
	started.resize(lth);
	for (int i = 0; i < lth; i++) {
		if (!started[i]) {
			DFS(0,0);
		}
	}

	printf("%d\n", maxlenght);

	system("pause");
	return 0;
}*/

int N, M, L;
vector<int> favs;
vector<int> stripe;

vector<vector<int> > dp;

int lst(int m, int n) {
	if (m == 0 || n == 0) {
		return 0;
	}

	if (dp[m][n] != -1) {
		return dp[m][n];
	}

	if (favs[m - 1] == stripe[n - 1]) {
		dp[m][n - 1] = lst(m, n - 1);
		dp[m][n] = dp[m][n - 1] + 1;
		return dp[m][n];
	}
	else {
		dp[m][n - 1] = lst(m, n - 1);
		dp[m - 1][n] = lst(m - 1, n);
		dp[m][n] = dp[m][n - 1] > dp[m - 1][n] ? dp[m][n - 1] : dp[m - 1][n];
		return dp[m][n];
	}
}

int main() {
	scanf_s("%d", &N);
	scanf_s("%d", &M);
	favs.resize(M);
	for (int i = 0; i < M; i++) {
		scanf_s("%d", &favs[i]);
	}
	scanf_s("%d", &L);
	stripe.resize(L);
	for (int i = 0; i < L; i++) {
		scanf_s("%d", &stripe[i]);
	}
	dp.resize(M + 1);
	for (int i = 0; i < M + 1; i++) {
		dp[i].resize(L + 1, -1);
	}

	printf("%d\n", lst(M, L));

	for (int i = 0; i < M + 1; i++) {
		for (int j = 0; j < L + 1; j++) {
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}
