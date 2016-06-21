#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int N;
vector<int> forinsert;
vector<int> formerge;
vector<int> sorted;

bool isinsert() {
	bool find;
	bool onemore;
	int temp;
	int k;

	find = false;
	onemore = true;
	for (int i = 1; i < N; i++) {
		temp = forinsert[i];
		for (int j = i-1; j >=0; j--) {
			if (temp < forinsert[j]) {
				forinsert[j + 1] = forinsert[j];
				forinsert[j] = temp;
			}
		}
		if (!onemore) {
			break;
		}
		for (k = 0; k < N; k++) {
			if (forinsert[k] != sorted[k]) {
				break;
			}
		}		
		if (k == N) {
			find = true;
			onemore = false;
		}
	}

	if (find) {
		cout << "Insertion Sort" << endl;
		cout << forinsert[0];
		for (int i = 1; i < N; i++) {
			cout << ' ' << forinsert[i];
		}
		cout << endl;
	}

	return find;
}

void ismerge() {
	bool find;
	bool onemore;
	int q;
	int tq;
	int k;
	queue<pair<int, int>> tqueue;
	pair<int, int> v1, v2;

	tq = N;
	for (int i = 0; i < N; i++) {
		tqueue.push(pair<int, int>(i, i + 1));
	}
	find = false;
	onemore = true;
	while (tq > 1) {
		q = tq;
		tq = 0;
		for (int i = 0; i < q / 2; i++) {
			v1 = tqueue.front();
			tqueue.pop();
			v2 = tqueue.front();
			tqueue.pop();
			sort(formerge.begin() + v1.first, formerge.begin() + v2.second);
			tqueue.push(pair<int, int>(v1.first, v2.second));
			tq++;
		}
		if (q % 2 == 1) {
			v1 = tqueue.front();
			tqueue.pop();
			tqueue.push(v1);
			tq++;
		}
		if (!onemore) {
			break;
		}
		for (k = 0; k < N; k++) {
			if (formerge[k] != sorted[k]) {
				break;
			}
		}
		if (k == N) {
			find = true;
			onemore = false;
		}
	}

	if (find) {
		cout << "Merge Sort" << endl;
		cout << formerge[0];
		for (int i = 1; i < N; i++) {
			cout << ' ' << formerge[i];
		}
		cout << endl;
	}
}

int main() {
	bool find;

	cin >> N;
	forinsert.resize(N);
	formerge.resize(N);
	sorted.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> forinsert[i];
		formerge[i]=forinsert[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> sorted[i];
	}

	find=isinsert();
	if (!find) {
		ismerge();
	}

	system("pause");
	return 0;
}