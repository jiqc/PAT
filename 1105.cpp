#include<cstdio>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int getn(int N) {
	int sq = (int)sqrt(N);
	for (int i = sq; i > 0; i--) {
		if (N % i == 0) {
			return i;
		}
	}

	return 1;
}

bool bigger_than(const int &A, const int &B) {
	return A > B;
}

int main() {
	int N;
	vector<int> numbers;
	vector<vector<int> > matrix;
	int m, n;
	int left, right, up, down;

	scanf_s("%d", &N);
	numbers.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &numbers[i]);
	}
	sort(numbers.begin(), numbers.end(), bigger_than);

	n = getn(N);
	m = N / n;

	left = -1;
	right = n;
	up = 0;
	down = m;
	matrix.resize(m);
	for (int i = 0; i < m; i++) {
		matrix[i].resize(n);
	}

	int direction;
	int ph, pv;
	direction = 0;
	ph = 0;
	pv = 0;
	for (int i = 0; i < N; i++) {
		switch (direction) {
		case 0:
			matrix[pv][ph] = numbers[i];
			ph++;
			if (ph == right) {				
				direction = 1;
				right--;
				ph = right;
				pv++;
			}
			break;
		case 1:
			matrix[pv][ph] = numbers[i];
			pv++;
			if (pv == down) {
				direction = 2;
				down--;
				pv = down;
				ph--;
			}
			break;
		case 2:
			matrix[pv][ph] = numbers[i];
			ph--;
			if (ph == left) {
				direction = 3;
				left++;
				ph = left;
				pv--;
			}
			break;
		case 3:
			matrix[pv][ph] = numbers[i];
			pv--;
			if (pv == up) {
				direction = 0;
				up++;
				pv = up;
				ph++;
			}
			break;
		}
	}

	for (int i = 0; i < m; i++) {
		printf("%d", matrix[i][0]);
		for (int j = 1; j < n; j++) {
			printf(" %d", matrix[i][j]);
		}
		printf("\n");
	}

	system("pause");
	return 0;
}