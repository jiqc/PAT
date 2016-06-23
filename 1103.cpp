#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, K, P;
vector<int> powerp;
vector<int> templist;
vector<int> choose;
int sum;
/*
bool campare(const vector<int> &A, const vector<int> &B) {
	if (A[K] != B[K]) {
		return A[K] > B[K];
	}
	else {
		int i = 0;
		while (A[i] == B[i]) {
			i++;
			if (i == K) {
				break;
			}
		}
		return A[i] > B[i];
	}
}
*/
bool getnext(int n, int k, int t) {	
	int tsum;
	if (n < k) {
		return false;
	}
	if (k == 1) {
		while (n != powerp[t]) {
			t--;
			if (t == 0) {
				return false;
			}
		}
		templist[K-1] = t;
		tsum = 0;
		for (int j = 0; j < K; j++) {
			tsum += templist[j];
		}
		if (tsum > sum) {
			choose = templist;
			sum = tsum;
		}
		else {
			if (tsum == sum) {
				int w=0;
				while (templist[w] == choose[w]) {
					w++;
					if (w == K-1) {
						break;
					}
				}
				if (templist[w] > choose[w]) {
					choose = templist;
				}/*
				for (int j = 0; j <K; j++) {
					if (templist[j] > choose[j]) {
						choose = templist;
						sum = tsum;
						break;
					}
				}*/
			}
		}
		return true;
	}
	else {
		for (int i = t; i > 0; i--) {
		    templist[K-k] = i;
			if (n < powerp[i]) {
				continue;
			}
			getnext(n - powerp[i], k - 1, i);
	    }
	}

	return false;
}

int main() {	
	int temp;

	cin >> N >> K >> P;
	templist.resize(K);
	for (int i = 0; i < 21; i++) {
		temp = 1;
		for (int j = 0; j < P; j++) {
			temp *= i;
		}
		if (temp > N) {
			break;
		}
		powerp.push_back(temp);
	}

	sum = 0;
	getnext(N, K, (int)powerp.size()-1);

	//sort(choose.begin(), choose.end(), campare);

	if (choose.empty()) {
		cout << "Impossible" << endl;
	}
	else {
		cout << N << " = " << choose[0] << "^"<<P;
		for (int i = 1; i <K; i++) {
			cout << " + " << choose[i] << "^"<<P;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}