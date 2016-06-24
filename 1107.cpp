#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int N;
vector<vector<int> > hob;
vector<vector<int> > person;
vector<bool> visited;

bool bigger_than(const int &A, const int &B) {
	return A > B;
}

int DFS(int n) {
	int count = 1;
	int k;

	visited[n] = true;
	for (int i = 0; i < (int)person[n].size(); i++) {
		k = person[n][i];
		for (int j = 0; j < (int)hob[k].size(); j++) {
			if (!visited[hob[k][j]]) {
				count += DFS(hob[k][j]);
			}
		}
	}

	return count;
}

int main() {
	int K;
	int h;
	int count;
	vector<int> clusters;

	scanf_s("%d", &N);
	person.resize(N);
	visited.resize(N);
	hob.resize(1001);
	for (int i = 0; i < N; i++) {
		scanf_s("%d:", &K);
		for (int j = 0; j < K; j++) {
			scanf_s("%d", &h);
			hob[h].push_back(i);
			person[i].push_back(h);
		}
	}

	for (int i = 0; i < N; i++) {
		if (!visited[i]) {
			count = DFS(i);
			clusters.push_back(count);
		}
	}

	sort(clusters.begin(), clusters.end(), bigger_than);

	printf("%d\n", clusters.size());
	printf("%d", clusters[0]);
	for (int i = 1; i < (int)clusters.size(); i++) {
		printf(" %d", clusters[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}