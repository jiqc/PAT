#include<cstdio>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct person {
	string name;
	int height;
};

bool shorter(const person &A, const person &B) {
	if (A.height != B.height) {
		return A.height < B.height;
	}
	else {
		return A.name > B.name;
	}
}

int main() {
	char name[9];
	int height;
	int N, K;
	vector<person> people;
	vector<vector<person> > photo;

	scanf_s("%d %d", &N, &K);
	people.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s", name, 9);
		scanf_s("%d", &height);
		people[i].name = name;
		people[i].height = height;
	}

	sort(people.begin(), people.end(), shorter);

	photo.resize(K);
	for (int i = 0; i < K - 1; i++) {
		photo[i].resize(N / K);
	}
	photo[K - 1].resize(N / K + N % K);

	int m;
	int p;
	p = 0;
	for (int i = 0; i < K; i++) {
		 m = photo[i].size();
	     if (m % 2==0) {
			for (int j = m-1; j > m / 2 - 1; j--) {
				photo[i][m - j - 1] = people[p];
				p++;
				photo[i][j] = people[p];
				p++;
			}
		 }
		 else {			 
			 for (int j = m - 1; j > m / 2; j--) {
				 photo[i][j] = people[p];
				 p++;
				 photo[i][m - j - 1] = people[p];
				 p++;
			 }
			 photo[i][m / 2] = people[p];
			 p++;
		 }
	}

	for (int i = K - 1; i >= 0; i--) {
		printf("%s", photo[i][0].name.c_str());
		for (int j = 1; j < (int)photo[i].size(); j++) {
			printf(" %s", photo[i][j].name.c_str());
		}
		printf("\n");
	}
	
	system("pause");
	return 0;
}