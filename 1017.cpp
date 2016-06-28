#include <cstdio>
#include <algorithm>
using namespace std;

struct customer {
	int arrivetime;
	int usetime;
};

bool less_than_time(customer &A, customer &B) {
	return A.arrivetime < B.arrivetime;
}

int main() {
	int N, K;
	int h, m, s, w;
	int wait;
	int count;

	scanf_s("%d %d", &N, &K);
	customer* cus = (customer*)malloc(sizeof(customer)*N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d:%d:%d %d", &h, &m, &s, &w);
		cus[i].arrivetime = h * 3600 + m * 60 + s;
		if (w > 60) {
			cus[i].usetime = 3600;
		}
		else {
			cus[i].usetime = w * 60;
		}
	}
	int* windows = (int*)malloc(sizeof(int)*K);
	for (int i = 0; i < K; i++) {
		windows[i] = 8 * 3600;
	}

	sort(cus, cus + N, less_than_time);

	wait = 0;
	count = 0;
	for (int i = 0; i < N; i++) {
		if (cus[i].arrivetime <= (17 * 3600)) {
			count++;
			int t=0;
			for (int j = 1; j < K; j++) {
				if (windows[t] > windows[j]) {
					t = j;
				}
			}
			if (windows[t] <= cus[i].arrivetime) {
				windows[t] = cus[i].arrivetime + cus[i].usetime;
			}
			else {
				wait = wait + windows[t] - cus[i].arrivetime;
				windows[t] = windows[t] + cus[i].usetime;
			}
		}
	}

	float wm = (float)wait / (60*count);
	printf("%.1f\n", wm);

	free(windows);
	free(cus);
	system("pause");
	return 0;
}