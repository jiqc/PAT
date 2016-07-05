#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N;
	vector<int> distance;
	int partdis;
	int M;

	scanf_s("%d", &N);
	distance.resize(N+1);
	int dis;
	for (int i = 1; i <= N; i++) {
		scanf_s("%d", &dis);
		distance[i] = distance[i - 1] + dis;
	}
	

	scanf_s("%d", &M);
	int pa, pb;
	for (int i = 0; i < M; i++) {
		scanf_s("%d %d", &pa, &pb);
		if (pa > pb) {
			int temp = pa;
			pa = pb;
			pb = temp;
		}
		partdis = distance[pb - 1] - distance[pa - 1];
		if (distance[N] - partdis < partdis) {
			partdis = distance[N] - partdis;
		}
		printf("%d\n", partdis);
	}

	system("pause");
	return 0;
}