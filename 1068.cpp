/*
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N, M;
vector<int> wallet;
vector<int> res;

bool getcoin(int k, int m) {
	bool r;

	if (m == 0) {
		return true;
	}
	if (k == wallet.size() || m < 0) {
		return false;
	}
	if (m < wallet[k]) {
		return false;
	}
	for (unsigned int i = k; i < wallet.size(); i++) {
		r = getcoin(i + 1, m - wallet[i]);
		if (r) {
			res.push_back(wallet[i]);
			return true;
		}
	}

	return false;
}

int main() {
	bool find;

	scanf_s("%d %d", &N, &M);
	wallet.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &wallet[i]);
	}

	sort(wallet.begin(), wallet.end());

	if (M < wallet[0]) {
		find = false;
	}
	else {
		find = getcoin(0, M);
	}

	if (find) {
		for (unsigned int i = res.size(); i > 1; i--) {
			printf("%d ", res[i-1]);
		}
		printf("%d\n", res[0]);
	}
	else {
		printf("No Solution\n");
	}

	system("pause");
	return 0;
}
*********************************************************/

#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool camp(int A, int B) {
	return A > B;
}

int main() {
	int N, M;
    vector<int> wallet;
    vector<vector<int> > dp;
    vector<vector<bool> > included;

	scanf_s("%d %d", &N, &M);
	wallet.resize(N+1);
	for (int i = 1; i <= N; i++) {
		scanf_s("%d", &wallet[i]);
	}
	dp.resize(N+1);
	for (int i = 0; i <= N; i++) {
		dp[i].resize(M+1);
	}
	included.resize(M+1);
	for (int i = 0; i <= M; i++) {
		included[i].resize(N + 1);
	}

	sort(wallet.begin()+1, wallet.end(),camp);
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (j<wallet[i] || dp[i - 1][j]>wallet[i] + dp[i - 1][j - wallet[i]]) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = wallet[i] + dp[i - 1][j - wallet[i]];
				included[j][i]=true;
			}
		}
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			printf("%d ", dp[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i <= N; i++) {
		for (int j = 0; j <= M; j++) {
			printf("%d ", (int)included[j][i]);
		}
		printf("\n");
	}

	if (dp[N][M] != M) {
		printf("No Solution\n");
	}
	else {
		bool first = true;
		for (int i = N; i >= 1 && M > 0; i--) {
			if (included[M][i]) {
				if (first) {
					printf("%d", wallet[i]);
					first = false;
				}
				else {
					printf(" %d", wallet[i]);					
				}
				M -= wallet[i];
			}
		}
		printf("\n");
	}

	system("pause");
	return 0;
}