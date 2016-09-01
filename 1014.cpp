#include <iostream>
#include <vector>
#include <iomanip>
#include <queue>
using namespace std;

//you may use queue as windows

class customer{
public:
	bool service;
	int hour;
	int minute;
	int ptime;
	customer() {
		service = 1;
		hour = 8;
		minute = 0;
		ptime = 0;
	}
	customer(const int t) {
		service = 1;
		hour = 8;
		minute = 0;
		ptime = t;
	}
	void print() {
		if (service) {
			cout << setfill('0') << setw(2) << hour << ':' << setfill('0') << setw(2) << minute << '\n';
		}
		else {
			cout << "Sorry\n";
		}
	}
	~customer(){}
};

class ventana {
public:
	queue<customer> waitinqueue;
	int M;
	int shour;
	int sminute;
	int hour;
	int minute;
	ventana() {
		shour = 7;
		sminute = 0;
		hour = 8;
		minute = 0;
	}
	ventana(int t) {
		shour = 7;
		sminute = 0;
		hour = 8;
		minute = 0;
		M = t;
	}
	~ventana(){}
	bool need() {
		return waitinqueue.size() < M;
	}
	void addprocess(customer &A) {
		if (waitinqueue.empty()) {
			shour = hour;
			sminute = minute;
		}
		else {
            shour = waitinqueue.front().hour;
		    sminute = waitinqueue.front().minute;
		    waitinqueue.pop();
		}
		if (hour >= 17) {
			A.service = false;
		}
		else {
			minute += A.ptime % 60;
			if (minute>59) {
				minute -= 60;
				hour = hour + 1 + A.ptime / 60;
			}
			else {
				hour += A.ptime / 60;
			}
			//if ((hour > 17)||(hour==17 && minute>0)) {
			//	A.service = false;
			//}
			//else {
				A.hour = hour;
				A.minute = minute;
			//}
		}
		waitinqueue.push(A);
	}
};

int main() {
	int N, M, K, Q;
	int pt;
	int qr;
	int th, tm;
	int process;

	cin >> N >> M >> K >> Q;
	ventana *windows = new ventana[N];
	for (int i = 0; i < N; i++) {
		windows[i] = M;
	}
	customer *customers = new customer[K];

	for (int i = 0; i < K; i++) {
		cin >> pt;
		customers[i] = pt;
		th = windows[0].shour;
		tm = windows[0].sminute;
		process = 0;
		for (int j = 1; j < N; j++) {
			if (th > windows[j].shour) {
				process = j;
				th = windows[j].shour;
				tm = windows[j].sminute;
			}
			else {
				if ((th == windows[j].shour) && (tm>windows[j].sminute)) {
					process = j;
					th = windows[j].shour;
					tm = windows[j].sminute;
				}
			}
		}
		windows[process].addprocess(customers[i]);
	}

	for (int i = 0; i < Q; i++) {
		cin >> qr;
		customers[qr-1].print();
	}

	delete[] customers;
	delete[] windows;

	system("pause");
	return 0;
}
