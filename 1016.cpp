#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
using namespace std;

int toll[24];
int tollhour[24];
int tollday;

struct item {
	int  d, h, min;
	bool condition;
};

struct itempair {
	int bd, bh, bm;
	int ed, eh, em;
	int lt;
	float cost;
};

struct person {
	char name[21];
	int  mth;
	vector<item> records;
	vector<itempair> outs;
	float total;
};

bool less_than_name(person &A, person &B) {
	return strcmp(A.name, B.name) < 0;
}

bool less_than_time(item &A, item &B) {
	if (A.d < B.d) {
		return true;
	}
	else {
		if (A.d == B.d && A.h < B.h) {
			return true;
		}
		else {
			if (A.d == B.d && A.h == B.h && A.min < B.min) {
				return true;
			}
			else {
				return false;
			}
		}
	}
}

int main() {
	int N;
	vector<person> people;

	for (int i = 0; i < 24; i++) {
		scanf_s("%d", &toll[i]);
	}
	tollhour[0] = 0;
	for (int i = 1; i < 24; i++) {
		tollhour[i] = tollhour[i - 1] + 60 * toll[i - 1];
	}
	tollday = tollhour[23] + 60 * toll[23];


	scanf_s("%d", &N);
	item ti;
	person tp;
	int np = 0;
	char temp_name[21];
	char on_off[10];
	for (int i = 0; i < N; i++) {
		scanf_s("%s", &temp_name, 21);
		int j,index;
		if (np == 0) {
			strcpy_s(tp.name ,temp_name);
			people.push_back(tp);
			index = 0;
			np++;
		}
		else {
			for (j = 0; j < np; j++) {
				if (strcmp(people[j].name, temp_name) == 0) {
					index = j;
					break;
				}
			}
			if (j == np) {
				strcpy_s(tp.name, temp_name);
				people.push_back(tp);
				index = np;
				np++;
			}
		}
		scanf_s("%d:%d:%d:%d", &people[index].mth, &ti.d, &ti.h, &ti.min);
		scanf_s("%s", &on_off, 10);
		ti.condition = (strcmp(on_off, "on-line") == 0);
		people[index].records.push_back(ti);
	}

	sort(people.begin(), people.end(), less_than_name);

	for (int i = 0; i < np; i++) {
		sort(people[i].records.begin(), people[i].records.end(), less_than_time);
	}

	bool single = false;
	float bill, totalbill;
	int timebegin[3], timeend[3];
	int time;
	itempair tpair;
	for (int i = 0; i < np; i++) {
		totalbill = 0;
		single = false;
		for (unsigned j = 0; j < people[i].records.size(); j++) {
			if (people[i].records[j].condition) {
				timebegin[0] = people[i].records[j].min;
				timebegin[1] = people[i].records[j].h;
				timebegin[2] = people[i].records[j].d;
				single = true;
			}
			else {
				if (single) {
					timeend[0] = people[i].records[j].min;
					timeend[1] = people[i].records[j].h;
					timeend[2] = people[i].records[j].d;
					tpair.bd = timebegin[2];
					tpair.bh = timebegin[1];
					tpair.bm = timebegin[0];
					tpair.ed = timeend[2];
					tpair.eh = timeend[1];
					tpair.em = timeend[0];
					time = (timeend[2] - timebegin[2]) * 24 * 60 + (timeend[1] - timebegin[1]) * 60 + timeend[0] - timebegin[0];
					tpair.lt = time;
					bill = (float)((timeend[2] - timebegin[2])*tollday + tollhour[timeend[1]] - tollhour[timebegin[1]] + toll[timeend[1]] * timeend[0] - toll[timebegin[1]] * timebegin[0]) / 100;
					tpair.cost = bill;
					people[i].outs.push_back(tpair);
					totalbill += bill;
					single = false;
				}
			}
		}
		people[i].total = totalbill;
	}	

	for (int i = 0; i < np; i++) {
		if (people[i].total>0) {
			printf("%s %02d\n", people[i].name, people[i].mth);
			for (unsigned int j = 0; j < people[i].outs.size(); j++) {
				printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", people[i].outs[j].bd, people[i].outs[j].bh, people[i].outs[j].bm, people[i].outs[j].ed, people[i].outs[j].eh, people[i].outs[j].em, people[i].outs[j].lt, people[i].outs[j].cost);
			} 
			printf("Total amount: $%.2f\n", people[i].total);
		}
	}
  
	system("pause");
	return 0;
}