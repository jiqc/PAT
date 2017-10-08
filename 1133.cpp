#include<cstdio>
#include<vector>

using namespace std;

void function() {
	int first, N, K;
	scanf_s("%d %d %d", &first, &N, &K);
	vector<vector<int> > data(100000);
	int pos, val, next;
	for (int i = 0; i < N; i++) {
		scanf_s("%d %d %d", &pos, &val, &next);
		data[pos].push_back(val);
		data[pos].push_back(next);
	}

	vector<int> kind(3, -1);
	vector<int> prekind(3, 0);
	pos = first;
	while (pos != -1) {
		if(data[pos][0] < 0){
			if (kind[0] == -1) {
				kind[0] = pos;
			}
			else {
				data[prekind[0]][1] = pos;
			}
			prekind[0] = pos;
		}
		else {
			if (data[pos][0] <= K) {
				if (kind[1] == -1) {
					kind[1] = pos;
				}
				else {
					data[prekind[1]][1] = pos;
				}
				prekind[1] = pos;
			}
			else {
				if (kind[2] == -1) {
					kind[2] = pos;
				}
				else {
					data[prekind[2]][1] = pos;
				}
				prekind[2] = pos;
			}
				
		}
		pos = data[pos][1];
	}

	first = -1;
	int end = -1;
	for (int i = 0; i < 3; i++) {
		if (kind[i] != -1) {
			if (first == -1) {
				first = kind[i];
			}
			else {
				data[end][1] = kind[i];
			}
			end = prekind[i];
		}
	}
	if (end != -1) {
		data[end][1] = -1;
	}

	pos = first;
	while (pos != -1) {
		printf("%05d %d ", pos, data[pos][0]);
		if (data[pos][1] != -1) {
			printf("%05d\n", data[pos][1]);
		}
		else {
			printf("-1\n");
		}
		pos = data[pos][1];
	}
}

int main() {
	function();
	system("pause");
	return 0;
}
