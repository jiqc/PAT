#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

struct stuckedchar {
	char c;
	bool stucked;
};

vector<stuckedchar> stucked;

int getnumber(char c) {
	int i;
	for (i = 0; i < (int)stucked.size(); i++) {
		if (stucked[i].c == c) {
			break;
		}
	}
	if (i == (int)stucked.size()) {
		stuckedchar temp;
		temp.c = c;
		temp.stucked = true;
		stucked.push_back(temp);
	}
	return i;
}

int main() {
	int K;
	string str,outstr;
	string tempstr;
	queue<string> queuestr;
	int pf, pr;
	int n,k;

	cin >> K;
	cin >> str;
	pf = pr = 0;
	while (pr<=(int)str.size()) {
		if (str[pr] == str[pf]) {
			pr++;
		}
		else {
			k = getnumber(str[pf]);
			queuestr.push(str.substr(pf, pr - pf));
			if ((pr - pf) % K != 0) {
				stucked[k].stucked = false;
			}
			pf = pr;
			pr++;
		}
	}

	for (int i = 0; i < (int)stucked.size(); i++) {
		if (stucked[i].stucked) {
			cout << stucked[i].c;
		}
	}
	cout << endl;

	while (!queuestr.empty()) {
		tempstr = queuestr.front();
		queuestr.pop();
		k = getnumber(tempstr[0]);
		if (stucked[k].stucked) {
			n = tempstr.size() / K;
			outstr += tempstr.substr(0, n);
		}
		else {
			outstr += tempstr;
		}
	}

	cout << outstr << endl;

	system("pause");
	return 0;
}