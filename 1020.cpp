#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct lines {
	int ps, is, length;
};	

int main() {
	int N;
    vector<int> postorder;
    vector<int> inorder;

	cin >> N;
    postorder.resize(N);
	inorder.resize(N);
    for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
	}

	queue<lines> level;
	lines temp, out;
	printf("%d", postorder[N - 1]);
	int index;
	for (int i = 0; i < N; i++) {
		if (inorder[i] == postorder[N - 1]) {
			index = i;
			break;
		}
	}
	if (index != 0) {
		temp.ps = 0;
		temp.is = 0;
		temp.length = index;
		level.push(temp);
	}
	if (N - index -1 != 0) {
		temp.ps = index;
		temp.is = index + 1;
		temp.length = N - index - 1;
		level.push(temp);
	}
	while (!level.empty()) {
		out = level.front();
		level.pop();
		printf(" %d", postorder[out.ps+out.length -1]);
		int index;
		for (int i = 0; i < out.length; i++) {
			if (inorder[out.is + i] == postorder[out.ps + out.length - 1]) {
				index = i;
				break;
			}
		}
		if (index != 0) {
			temp.ps = out.ps;
			temp.is = out.is;
			temp.length = index;
			level.push(temp);
		}		
		if (out.length - index - 1 != 0) {
			temp.ps = out.ps + index;
			temp.is = out.is + index + 1;
			temp.length = out.length - index - 1;
			level.push(temp);
		}		
	}

	printf("\n");

	system("pause");
	return 0;
}