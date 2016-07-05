#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;


int hashname(char* name) {
	return (name[0] - 'A') * 26 * 26 * 10 + (name[1] - 'A') * 26 * 10 + (name[2] - 'A') * 10 + name[3] - '0';
}

void printname(int n) {
	printf("%c", n / (26 * 26 * 10) + 'A');
	n = n % (26 * 26 * 10);
	printf("%c", n / (26 * 10) + 'A');
	n = n % (26 * 10);
	printf("%c", n / 10 + 'A');
	printf("%c\n", n % 10 + '0');
}

int main() {
	int N, K, C;
	char name[5];
	vector<vector<int> > course;
	int num;
	int key;
	
	scanf_s("%d %d", &N, &K);
	course.resize(K);
	for (int i = 0; i < N; i++) {
		scanf_s("%s", name, 5);
		num = hashname(name);
		scanf_s("%d", &C);
		for (int j = 0; j < C; j++) {
			scanf_s("%d", &key);
			course[key - 1].push_back(num);
		}
	}

	for (int i = 0; i < K; i++) {
		printf("%d %d\n", i + 1, course[i].size());
		sort(course[i].begin(), course[i].end());
		for (unsigned int j = 0; j < course[i].size(); j++) {
			printname(course[i][j]);
		}
	}

	system("pause");
	return 0;
}