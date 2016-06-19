#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

int findroot(int st, int ed) {
	int root;
	int num = ed - st;
	if (num == 1) {
		return st;
	}
	int temp = 4;
	while (temp < 1050) {
		if (num < temp) {
			root = num >= (3 * temp / 4 ) ? st + (temp / 2) - 1 : st + num - (temp/4);
			break;
		}
		temp *= 2;
	}
	return root;
}

int main() {
	vector<int> CBST;
	vector<int> numlist;
	int N;

	scanf_s("%d", &N);
	numlist.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%d", &numlist[i]);
	}

	sort(numlist.begin(), numlist.end());

	queue<pair<int, int> > tq;
	int pre, post;
	int root;
	tq.push(pair<int, int>(0, numlist.size()));
	while (!tq.empty()) {
		pre = tq.front().first;
		post = tq.front().second;
		tq.pop();
		root = findroot(pre, post);
		CBST.push_back(numlist[root]);
		if (pre != root) {
			tq.push(pair<int, int>(pre, root));
		}
		if (root + 1 != post) {
			tq.push(pair<int, int>(root+1, post));
		}
	}

	printf("%d", CBST[0]);
	for (unsigned int i = 1; i < CBST.size(); i++) {
		printf(" %d", CBST[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}