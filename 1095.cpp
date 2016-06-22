#include<cstdio>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

struct item {
	int time;
	bool in_out;
	int num;
};

struct car {
	string plate;
	int lasttime;
	int time;
	bool in_out;

	car() {
		lasttime = 0;
		time = 0;
		in_out = false;
	}
};

int gettime() {
	int h;
	int m;
	int s;
	scanf_s("%d:%d:%d", &h, &m, &s);
	return h * 3600 + m * 60 + s;
}

void printtime(int t) {
	int h, m, s;
	s = t % 60;
	t /= 60;
	m = t % 60;
	h = t / 60;
	printf("%02d:%02d:%02d", h, m, s);
}

bool less_time(const item &A, const item &B) {
	return A.time < B.time;
}

bool more_time(const car &A, const car &B) {
	if (A.lasttime != B.lasttime) {
	   return A.lasttime > B.lasttime;
	}
	else {
		return A.plate < B.plate;
	}		
}

int main() {
	int N, K;
	int t;
	char plate[8];
	char in_out[4];
	vector<car> vc;
	map<string, int> tovc;
	vector<item> records;
	vector<int> timein;
	vector<int> timeout;

	scanf_s("%d %d", &N, &K);

	int k = 0;
	records.resize(N);
	for (int i = 0; i < N; i++) {
		scanf_s("%s", plate, 8);
		if (tovc.find(plate) == tovc.end()) {
			car tempcar;
			tempcar.plate = plate;
			vc.push_back(tempcar);
			tovc[plate] = k;
			k++;
		}
		records[i].num = tovc[plate];
		records[i].time = gettime();
		scanf_s("%s", in_out, 4);
		if (in_out[0] == 'i') {
			records[i].in_out = true;
		}
		else {
			records[i].in_out = false;
		}
	}

	sort(records.begin(), records.end(), less_time);

	for (int i = 0; i < N; i++) {
		k = records[i].num;
		if (records[i].in_out) {
			if (!vc[k].in_out) {
				vc[k].time = records[i].time;
				vc[k].in_out = true;
			}
			else {
				vc[k].time = records[i].time;
			}
		}
		else {
			if (vc[k].in_out) {
				vc[k].lasttime += records[i].time - vc[k].time;
				timein.push_back(vc[k].time);
				timeout.push_back(records[i].time);
				vc[k].time = records[i].time;
				vc[k].in_out = false;
			}
			else {
				vc[k].time = records[i].time;
			}
		}
	}

	sort(timein.begin(), timein.end());
	sort(timeout.begin(), timeout.end());

	int inpos = 0;
	int outpos = 0;
	int count = 0;
	for (int i = 0; i < K; i++) {
		t = gettime();
		while (inpos < (int)timein.size() && timein[inpos] <= t) {
			count++;
			inpos++;
		}
		while (outpos < (int)timeout.size() && timeout[outpos] <= t) {
			count--;
			outpos++;
		}
		printf("%d\n", count);
	}

	sort(vc.begin(), vc.end(), more_time);

	int max = vc[0].lasttime;
	for (int i = 0; i < (int)vc.size(); i++) {
		if (vc[i].lasttime == max) {
			printf("%s ", vc[i].plate.c_str());
		}
		else {
			break;
		}
	}
	printtime(max);
	printf("\n");

	system("pause");
	return 0;
}