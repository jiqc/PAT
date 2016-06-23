#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N;
	vector<int> numlist;
	vector<bool> first;
	vector<int> pivot;
	int max, min;

	scanf_s("%d", &N);
	numlist.resize(N);
	first.resize(N);
	max = 0;
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &numlist[i]);
		if (numlist[i] > max) {
			first[i] = true;
			max = numlist[i];
		}
	}

	min = 0x7fffffff;
	for (int i = N - 1; i >= 0; i--) {
		if (numlist[i] < min ) {			
			min = numlist[i];
			if (first[i]) {
				pivot.push_back(numlist[i]);
			}
		}
	}

	printf("%d\n", (int)pivot.size());
	sort(pivot.begin(), pivot.end());
	if (!pivot.empty()) {
		printf("%d", pivot[0]);
		for (int i = 1; i < (int)pivot.size(); i++) {
			printf(" %d", pivot[i]);
		}		
	}
	printf("\n");

	system("pause");
	return 0;
}