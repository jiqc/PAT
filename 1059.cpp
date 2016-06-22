#include<iostream>
#include<map>
using namespace std;

map<int, int> primefactors;

void getfactor(long int N) {
	int f;

	if (N % 2 == 0) {
		primefactors[2] = 1;
		N = N / 2;
		while (N % 2 == 0) {
		    primefactors[2] ++;
		    N = N / 2;
	    }
	}
		
	f = 3;
	while (f <= N) {
		if (N % f == 0) {
			primefactors[f] = 1;
			N = N / f;
			while (N % f == 0) {
			    primefactors[f] ++;
			    N = N / f;
		    }
		}		
		f = f + 2;
	}
}

int main() {
	long int num;

	cin >> num;

	if (num <= 3) {
		cout << num << '=' << num << endl;
	}
	else {
		getfactor(num);

	    cout << num << '=';
	    map<int, int>::const_iterator it = primefactors.begin();
	    while (true) {
		    cout << it->first;
		    if (it->second > 1) {
			    cout << '^' << it->second;
		    }
		    it++;
		    if (it == primefactors.end()) {
			    cout << endl;
			    break;
		    }
		    cout << '*';
	    }
	}

	system("pause");
	return 0;
}