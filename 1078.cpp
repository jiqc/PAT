#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

enum KindOfEntry {Legitimate,Empty,Deleted};

struct HashEntry {
	int element;
	enum KindOfEntry Info;
};

struct HashTabl {
	int TableSize;
	vector<HashEntry> TheCells;
};

bool IsPrime(int n) {
	for (int i = 3; i <= (int)sqrt(n); i+=2) {
		if (n%i == 0) {
			return false;
		}
	}
	return true;
}

int NextPrime(int N) {
	if(N > 2){
		if (N % 2 == 0) {
			N++;
		}
		while (!IsPrime(N)) {
			N += 2;
		}
	}
	else {
		N = 2;
	}

	return N;
}

HashTabl * Initialization(int TableSize) {
	HashTabl * H;

	H = new HashTabl;

	H->TableSize = NextPrime(TableSize);

	H->TheCells.resize(H->TableSize);

	for (int i = 0; i < H->TableSize; i++) {
		H->TheCells[i].Info = Empty;
	}

	return H;
}

int Find(int Key, HashTabl *H) {
	int CurrentPos;
	int CollosionNum;

	CollosionNum = 0;
	CurrentPos = Key % H->TableSize;
	while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].element != Key) {
		if (CollosionNum >= H->TableSize) {
			CurrentPos = -1;
			break;
		}
		CurrentPos += 2 * (++CollosionNum) - 1;
		if (CurrentPos >= H->TableSize) {
			CurrentPos %= H->TableSize;
		}
	}

	return CurrentPos;
}

int Insert(int Key, HashTabl *H) {
	int Pos;

	Pos = Find(Key, H);

	if (Pos != -1) {
		if (H->TheCells[Pos].Info != Legitimate) {
		    H->TheCells[Pos].Info = Legitimate;
		    H->TheCells[Pos].element = Key;
	    }
	}
	
	return Pos;
}

int main() {
	int TS, NS;
	int num;
	HashTabl *H;
	vector<int> Position;

	cin >> TS >> NS;

	H = Initialization(TS);
	Position.resize(NS, -1);

	for (int i = 0; i < NS; i++) {
		cin >> num;
		Position[i] = Insert(num, H);
	}

	for (int i = 0; i < NS - 1; i++) {
		if (Position[i] != -1) {
			cout << Position[i] << ' ';
		}
		else {
			cout << "- ";
		}
	}
	if (Position[NS-1] != -1) {
		cout << Position[NS-1] << endl;
	}
	else {
		cout << '-' << endl;
	}

	system("pause");
	return 0;

}