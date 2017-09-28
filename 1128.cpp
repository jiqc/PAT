#include<cstdio>
#include<vector>

using namespace std;

bool isanswer() {
	int N;
	vector<int> config;
	scanf_s("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf_s("%d", &temp);
		config.push_back(temp);
	}
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (config[i] == config[j]) {
				return false;
			}
			if (config[i] == config[j] + i - j) {
				return false;
			}
			if (config[i] == config[j] - i + j) {
				return false;
			}
		}
	}
	return true;
}

int main() {
	int K;
	scanf_s("%d", &K);
	for (int i = 0; i < K; i++) {
		if (isanswer()) {
			printf_s("YES\n");
		}
		else {
			printf_s("NO\n");
		}
	}
	system("pause");
	return 0;
}
