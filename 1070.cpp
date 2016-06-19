#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct cake {
    float amount;
	float price;
	float perprice;
};

bool biggrt_perprice(const cake &A, const cake &B) {
	return A.perprice > B.perprice;
}

int main() {
	vector<cake> inventory;
	int N;
	float D;
	float sum;

	scanf_s("%d %f", &N, &D);
	inventory.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%f", &inventory[i].amount);
	}
	for (int i = 0; i < N; i++) {
		scanf_s("%f", &inventory[i].price);
		inventory[i].perprice = inventory[i].price / inventory[i].amount;
	}

	sort(inventory.begin(), inventory.end(), biggrt_perprice);

	sum = 0;
	for (int i = 0; i < N && D > 0; i++) {
		if (D >= inventory[i].amount) {
			D -= inventory[i].amount;
			sum += inventory[i].price;
		}
		else {
			sum += (D / inventory[i].amount)*inventory[i].price;
			D = 0;
		}
	}

	printf("%.2f\n", sum);

	system("pause");
	return 0;
}