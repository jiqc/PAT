#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<double> numbers;
/*
void islegal(string str) {
	double sum = 0;
	int i = 0;
	double dcm = 0.1;
	bool neg = false;
	bool legal = true;

	if (str[0] == '-') {
		neg = true;
		i++;
	}
	if (str[i] == '\0') {
		legal = false;
	}

	while (str[i] != '.' && str[i] != '\0') {
		if (str[i] < '0'|| str[i] >'9') {
			legal = false;
			break;
		}
		sum = sum * 10 + str[i] - '0';
		i++;
	}
	if (str[i] == '.') {
		if (i == 0 || str[i - 1] == '-') {
			legal = false;
		}
		i++;
		if (str[i] == '\0') {
			legal = false;
		}
		if (legal) {
		    while (dcm >= 0.01 && str[i] != '\0') {
			    if (str[i] < '0' || str[i] >'9') {
				    legal = false;
				    break;
			    }
			    sum += (str[i] - '0')*dcm;
			    i++;
			    dcm /= 10;
		    }
		    if (str[i] != '\0') {
			    legal = false;
	 	    }
	    }
	}
	if (sum > 1000) {
		legal = false;
	}

	if (legal) {
		if (neg) {
			sum = -sum;
		}
		numbers.push_back(sum);
	}
	else {
		cout << "ERROR: " << str << " is not a legal number" << endl;
	}

}*/

void islegal(string str) {
	double sum = 0;
	int i = 0;
	double dcm = 0.1;
	bool neg = false;
	bool legal = true;
	string b, s;
	int len = (int)str.size();

	if (str[0] == '-') {
		neg = true;
		i++;
	}

	for (; i <  len; i++) {
		if (str[i] == '.') {
			break;
		}
	}

	if (i != len) {
		if (neg) {
			b = str.substr(1, i-1);
			s = str.substr(i+1);
		}
		else {
			b = str.substr(0, i);
			s = str.substr(i + 1,len);
		}
	}
	else {
		if (neg) {
			b = str.substr(1, len);
		}
		else {
			b = str.substr(0, len);
		}
	}

	if (b.empty()) {
		legal = false;
	}
	else {
		i = 0;
		while (b[i] != '\0') {
			if (b[i] < '0' || b[i] >'9') {
				legal = false;
				break;
			}
			sum = sum * 10 + b[i] - '0';
			i++;
		}
	}
	if (legal) {
		if (s.size()>2) {
			legal = false;
		}
		else {
			i = 0;
			while (s[i] != '\0') {
				if (s[i] < '0' || s[i] >'9') {
					legal = false;
					break;
				}
				sum += (s[i] - '0')*dcm;
				i++;
				dcm /= 10;
			}
		}
	}
	if (sum > 1000) {
		legal = false;
	}

	if (legal) {
		if (neg) {
			sum = -sum;
		}
		numbers.push_back(sum);
	}
	else {
		cout << "ERROR: " << str << " is not a legal number" << endl;
	}
}

int main() {
	int N;
	string str;	
	double avg,sum;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> str;
		islegal(str);
	}

	if (numbers.empty()) {
		printf("The average of 0 numbers is Undefined\n");
	}
	else {
		if (numbers.size() == 1) {
			printf("The average of 1 number is %.2f\n", numbers[0]);
		}
		else {
			sum = 0;
			for (int i = 0; i < (int)numbers.size(); i++) {
				sum += numbers[i];
			}
			avg = sum / (int)numbers.size();
			printf("The average of %d numbers is %.2f\n", (int)numbers.size(), avg);
		}
	}

	system("pause");
	return 0;
}