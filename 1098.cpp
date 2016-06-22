#include<iostream>
#include<vector>
using namespace std;

int N;
vector<int> forinsert;
vector<int> forheap;
vector<int> sorted;

bool insertsort() {
	bool onemore;
	bool find;
	int temp;
	int k;

	find = false;
	onemore = true;
	for (int i = 1; i < N; i++) {
		temp = forinsert[i];		
		for (int j = i - 1; j >= 0; j--) {
			if (forinsert[j] > temp) {
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
		    cout <<' '<< forinsert[i];
	    }
        cout << endl;
	}

	return find;
}

void PercDown(int i, int N) {
	int child;
	int temp;

	for (temp = forheap[i]; 2 * i + 1 < N; i = child) {
		child = 2 * i + 1;
		if (child != N - 1 && forheap[child + 1] > forheap[child]) {
			child++;
		}
		if (temp < forheap[child]) {
			forheap[i] = forheap[child];
		}
		else {
			break;
		}
	}
	forheap[i] = temp;
}

void heapsort() {
	bool onemore;
	bool find;
	int k;
	int temp;

	for (int i = N / 2; i >= 0; i--) {
		PercDown(i, N);
	}
	onemore = true;
	find = false;
	for (int i = N - 1; i > 0; i--) {
		if (!onemore) {
			break;
		}
		for (k = 0; k < N; k++) {
			if (forheap[k] != sorted[k]) {
				break;
			}
		}
		if (k == N) {
			find = true;
			onemore = false;
		}
		temp = forheap[0];
		forheap[0] = forheap[i];
		forheap[i] = temp;		
		PercDown(0, i);
	}

	if (find) {
		cout << "Heap Sort" << endl;
		cout << forheap[0];
		for (int i = 1; i < N; i++) {
			cout << ' ' << forheap[i];
		}
		cout << endl;
	}
}

int main() {
	bool find;

	cin >> N;
	forinsert.resize(N);
	forheap.resize(N);
	sorted.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> forinsert[i];
		forheap[i] = forinsert[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> sorted[i];
	}

	find = insertsort();
	if (!find) {
		heapsort();
	}

	system("pause");
	return 0;
}