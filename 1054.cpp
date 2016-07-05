//when i use vector it surplus the time...
#include<cstdio>
#include<map>
using namespace std;

int main() {
	int M, N;
	int color;
	map<int, int> colorset;

	scanf_s("%d %d", &M, &N);
	int threshold = (M*N + 1) / 2;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &color);
			if (colorset.find(color) == colorset.end()) {
				colorset[color] = 0;
			}
			colorset[color]++;
			if (colorset[color] >= threshold) {
                printf("%d\n", color);
				break;
			}			
		}
	}	

	system("pause");
	return 0;
}