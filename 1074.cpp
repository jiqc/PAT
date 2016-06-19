#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

struct node {
	int id;
	int num;
	int next;
};

node L[100000];

int main() {
	int start;
	bool b;
	int N, K;
	int id;
	vector<node> temp;

	scanf_s("%d %d %d", &start, &N, &K);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &id);
		L[id].id = id;
		scanf_s("%d %d", &L[id].num, &L[id].next);
	}

	b = false;
	while (start!=-1) {
		if (temp.size() == K) {
			reverse(temp.begin(), temp.end());
			if (b) {
				printf("%05d\n", temp[0].id);
			}
			for (int i = 0; i < K - 1; i++) {
				printf("%05d %d %05d\n", temp[i].id, temp[i].num, temp[i + 1].id);
			}
			printf("%05d %d ", temp[K-1].id, temp[K-1].num);
			temp.clear();
			b = true;
		}
		temp.push_back(L[start]);
		start = L[start].next;
	}
	if (temp.size() == K) {
		reverse(temp.begin(), temp.end());
		if (b) {
			printf("%05d\n", temp[0].id);
		}
		for (int i = 0; i < K - 1; i++) {
			printf("%05d %d %05d\n", temp[i].id, temp[i].num, temp[i + 1].id);
		}
		printf("%05d %d -1\n", temp[K - 1].id, temp[K - 1].num);
	}
	else {
		if (!temp.empty()) {
			int index;
			if (b) {
				printf("%05d\n", temp[0].id);
			}
		    for (index = 0; index < (int)temp.size()-1; index++) {
			    printf("%05d %d %05d\n", temp[index].id, temp[index].num, temp[index].next);
		    }
			printf("%05d %d -1\n", temp[index].id, temp[index].num);
	    }
	}	

	system("pause");
	return 0;
}